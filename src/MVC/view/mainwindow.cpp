#include "mainwindow.h"

#include <QFileDialog>
#include <QLayout>

#include "3rdparty/QtGifImage/src/gifimage/qgifimage.h"
#include "ui_mainwindow.h"

#define COLOR_NUM 6

MainWindow::MainWindow(Controller& controller, QWidget* parent)
    : QMainWindow(parent), controller(controller), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  ui->glviewport->setController(&controller);
  controller.addObserver(this);

  settings = new QSettings("sc21", "3d_Viewer", this);
  load_settings();

  const char* colour[COLOR_NUM] = {"Grey", "White", "Blue",
                                   "Red",  "Cyan",  "Yellow"};
  for (int i = 0; i < COLOR_NUM; i++) ui->bg_color_picker->addItem(colour[i]);
  for (int i = 0; i < COLOR_NUM; i++) ui->edge_color_picker->addItem(colour[i]);
  for (int i = 0; i < COLOR_NUM; i++)
    ui->vertex_color_picker->addItem(colour[i]);

  ui->bg_color_picker->setCurrentIndex(bg_color);
  ui->edge_color_picker->setCurrentIndex(edge_color);
  ui->vertex_color_picker->setCurrentIndex(vertex_color);
  ui->projection_type->setCurrentIndex(
      settings->value("projection_type", 0).toInt());
  ui->point_shape->setCurrentIndex(point_shape);
  ui->line_shape->setCurrentIndex(line_shape);
  ui->slider_thickness->setValue(thickness_slider_position);
  ui->point_thickness_slider->setValue(point_thickness_slider_position);

  connect(&tmr_gif, SIGNAL(timeout()), this, SLOT(save_frame()));
  index_image_arr = 0;
}

MainWindow::~MainWindow() {
  save_settings();
  delete settings;
  delete ui;
}

void MainWindow::save_settings() {
  settings->setValue("projection_type", ui->glviewport->projection_type);
  settings->setValue("bg_color", bg_color);
  settings->setValue("edge_color", edge_color);
  settings->setValue("vertex_color", vertex_color);
  settings->setValue("thickness", thickness);
  settings->setValue("point_thickness", point_thickness);
  settings->setValue("point_shape", point_shape);
  settings->setValue("line_shape", line_shape);
  settings->setValue("thickness_slider_position", thickness_slider_position);
  settings->setValue("point_thickness_slider_position",
                     point_thickness_slider_position);
}

void MainWindow::load_settings() {
  ui->glviewport->projection_type =
      settings->value("projection_type", 0).toInt();

  bg_color = settings->value("bg_color", 0).toInt();
  edge_color = settings->value("edge_color", 1).toInt();
  vertex_color = settings->value("vertex_color", 3).toInt();
  thickness = settings->value("thickness", 2).toDouble();
  point_thickness = settings->value("point_thickness", 2).toDouble();
  point_shape = settings->value("point_shape", 1).toInt();
  line_shape = settings->value("line_shape", 1).toInt();
  thickness_slider_position =
      settings->value("thickness_slider_position", 1).toInt();
  point_thickness_slider_position =
      settings->value("point_thickness_slider_position", 1).toInt();

  ui->glviewport->updateSettings(bg_color, edge_color, vertex_color, thickness,
                                 point_thickness, point_shape, line_shape);
}

void MainWindow::on_button_file_chooser_clicked() {
  QString file_name = QFileDialog::getOpenFileName(
      this, "Open a file", "", "", nullptr, QFileDialog::DontUseNativeDialog);
  FileManager* fileManager = FileManager::getInstance();
  fileManager->setFileName(file_name.toStdString());

  if (fileManager->getFileName().empty() == 0) {
    controller.parseModel();
  } else {
    qDebug() << "INFO: Closed.";
  }
}

void MainWindow::updateResult(const QString& resultMessage) {
  FileManager* fileManager = FileManager::getInstance();
  fileManager->getFileName();
  ui->text_file__name->setText(
      QString::fromStdString(fileManager->getFileName()));

  reset_all_sliders();
  ui->glviewport->update();
  ui->label_vertexes->setText(QString::number(controller.getVertexCount()));
  ui->label_edges->setText(QString::number(controller.getPolygonCount()));

  qDebug() << resultMessage;
}

void MainWindow::updateError(const QString& errorMessage) {
  ui->text_file__name->setText(errorMessage);
  reset_all_sliders();
  qDebug() << errorMessage;
}

void MainWindow::on_slider_move_x_sliderMoved(int position) {
  ui->label_move_x->setText(QString::number(position));

  MoveCommand* moveCommand = new MoveCommand(
      ui->glviewport, &controller, (double)position - ui->glviewport->tx, 0, 0);
  moveCommand->execute();
}

void MainWindow::on_slider_move_y_sliderMoved(int position) {
  ui->label_move_y->setText(QString::number(position));

  MoveCommand* moveCommand = new MoveCommand(
      ui->glviewport, &controller, 0, (double)position - ui->glviewport->ty, 0);
  moveCommand->execute();
}

void MainWindow::on_slider_move_z_sliderMoved(int position) {
  ui->label_move_z->setText(QString::number(position));

  MoveCommand* moveCommand = new MoveCommand(
      ui->glviewport, &controller, 0, 0, (double)position - ui->glviewport->tz);
  moveCommand->execute();
}

void MainWindow::on_slider_rotate_x_sliderMoved(int position) {
  ui->label_rotate_x->setText(QString::number(position));

  RotateCommand* rotateCommand = new RotateCommand(
      ui->glviewport, &controller, position - ui->glviewport->rx, 0, 0);
  rotateCommand->execute();
  ui->glviewport->rx = (double)position;
}

void MainWindow::on_slider_rotate_y_sliderMoved(int position) {
  ui->label_rotate_y->setText(QString::number(position));

  RotateCommand* rotateCommand = new RotateCommand(
      ui->glviewport, &controller, 0, position - ui->glviewport->ry, 0);
  rotateCommand->execute();
  ui->glviewport->ry = (double)position;
}

void MainWindow::on_slider_rotate_z_sliderMoved(int position) {
  ui->label_rotate_z->setText(QString::number(position));

  RotateCommand* rotateCommand = new RotateCommand(
      ui->glviewport, &controller, 0, 0, position - ui->glviewport->rz);
  rotateCommand->execute();
  ui->glviewport->rz = (double)position;
}

void MainWindow::on_slider_scale_sliderMoved(int position) {
  double a = 1 + (double)position / 10;
  ui->label_scale->setText(QString::number(a));
  controller.scaleModel(a / ui->glviewport->scale);
  ui->glviewport->scale = a;
  ui->glviewport->update();
}

void MainWindow::reset_all_sliders() {
  ui->slider_move_x->setValue(0);
  ui->label_move_x->setText(QString::number(0));
  ui->glviewport->tx = 0;

  ui->slider_move_y->setValue(0);
  ui->label_move_y->setText(QString::number(0));
  ui->glviewport->ty = 0;

  ui->slider_move_z->setValue(0);
  ui->label_move_z->setText(QString::number(0));
  ui->glviewport->tz = 0;

  ui->slider_rotate_x->setValue(0);
  ui->label_rotate_x->setText(QString::number(0));
  ui->glviewport->rx = 0;

  ui->slider_rotate_y->setValue(0);
  ui->label_rotate_y->setText(QString::number(0));
  ui->glviewport->ry = 0;

  ui->slider_rotate_z->setValue(0);
  ui->label_rotate_z->setText(QString::number(0));
  ui->glviewport->rz = 0;

  ui->slider_scale->setValue(1);
  ui->label_scale->setText(QString::number(1));
  ui->glviewport->scale = 1;

  ui->label_edges->setText("0");
  ui->label_vertexes->setText("0");
}

void MainWindow::on_bg_color_picker_activated(int index) {
  bg_color = index;
  ui->glviewport->updateSettings(bg_color, edge_color, vertex_color, thickness,
                                 point_thickness, point_shape, line_shape);
}

void MainWindow::on_edge_color_picker_activated(int index) {
  edge_color = index;
  ui->glviewport->updateSettings(bg_color, edge_color, vertex_color, thickness,
                                 point_thickness, point_shape, line_shape);
}

void MainWindow::on_slider_thickness_sliderMoved(int position) {
  double a = 1 + (double)position / 10;
  thickness = a;
  thickness_slider_position = position;

  ui->glviewport->updateSettings(bg_color, edge_color, vertex_color, thickness,
                                 point_thickness, point_shape, line_shape);
}

void MainWindow::on_projection_type_activated(int index) {
  ui->glviewport->projection_type = index;
  ui->glviewport->update();
}

void MainWindow::on_point_thickness_slider_sliderMoved(int position) {
  double a = 1 + (double)position / 10;
  point_thickness = a;
  point_thickness_slider_position = position;

  ui->glviewport->updateSettings(bg_color, edge_color, vertex_color, thickness,
                                 point_thickness, point_shape, line_shape);
}

void MainWindow::on_vertex_color_picker_activated(int index) {
  vertex_color = index;
  ui->glviewport->updateSettings(bg_color, edge_color, vertex_color, thickness,
                                 point_thickness, point_shape, line_shape);
}

void MainWindow::on_point_shape_activated(int index) {
  point_shape = index;
  ui->glviewport->updateSettings(bg_color, edge_color, vertex_color, thickness,
                                 point_thickness, point_shape, line_shape);
}

void MainWindow::on_line_shape_activated(int index) {
  line_shape = index;
  ui->glviewport->updateSettings(bg_color, edge_color, vertex_color, thickness,
                                 point_thickness, point_shape, line_shape);
}

void MainWindow::on_screenshot_button_clicked() {
  QImage image = ui->glviewport->grabFramebuffer();
  QFileDialog::Options options;
  QString selectedFilter;

  QString fileName = "";

  fileName = QFileDialog::getSaveFileName(
      this, "Export Plot", ".", "Image (*.png);;Image (*.jpeg);;Image (*.bmp)",
      &selectedFilter, options);
  image.save(fileName);
}

void MainWindow::on_gif_button_clicked() {
  tmr_gif.start(100);
  index_image_arr = 0;
}

void MainWindow::save_frame() {
  QImage img = ui->glviewport->grabFramebuffer();
  img = img.scaled(ui->glviewport->w, ui->glviewport->h, Qt::KeepAspectRatio,
                   Qt::SmoothTransformation);
  image_arr[index_image_arr++] = img;
  if (index_image_arr >= 50) {
    tmr_gif.stop();
    index_image_arr = 0;
    create_gif();
  }
}

void MainWindow::create_gif() {
  QGifImage gif(QSize(640, 480));
  for (int i = 0; i < 50; ++i)
    gif.addFrame(image_arr[i].scaled(640, 480, Qt::KeepAspectRatio,
                                     Qt::SmoothTransformation),
                 0);
  QFileDialog::Options options;
  QString selectedFilter;
  QString fileName = "";
  fileName = QFileDialog::getSaveFileName(
      this, "Save gif", ".", "Images (*.gif)", &selectedFilter, options);
  gif.save(fileName);
}
