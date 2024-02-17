/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

#include "myglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
 public:
  QWidget *centralwidget;
  QLabel *label;
  QLabel *label_2;
  QSlider *slider_rotate_y;
  QSlider *slider_rotate_x;
  QSlider *slider_rotate_z;
  QLabel *label_3;
  QSlider *slider_scale;
  MyGlWidget *glviewport;
  QPushButton *button_file_chooser;
  QLineEdit *text_file__name;
  QLabel *label_4;
  QLabel *label_5;
  QLabel *label_6;
  QLabel *label_7;
  QSlider *slider_move_x;
  QSlider *slider_move_z;
  QLabel *label_8;
  QSlider *slider_move_y;
  QLabel *label_9;
  QLabel *label_move_x;
  QLabel *label_move_y;
  QLabel *label_move_z;
  QLabel *label_rotate_x;
  QLabel *label_rotate_y;
  QLabel *label_rotate_z;
  QLabel *label_scale;
  QLabel *label_10;
  QLabel *label_11;
  QLabel *label_edges;
  QLabel *label_vertexes;
  QComboBox *bg_color_picker;
  QComboBox *edge_color_picker;
  QSlider *slider_thickness;
  QComboBox *projection_type;
  QComboBox *vertex_color_picker;
  QLabel *label_12;
  QLabel *label_13;
  QLabel *label_14;
  QLabel *label_15;
  QLabel *label_16;
  QLabel *label_17;
  QSlider *point_thickness_slider;
  QLabel *label_18;
  QLabel *label_19;
  QComboBox *point_shape;
  QComboBox *line_shape;
  QLabel *label_20;
  QLabel *label_21;
  QLabel *label_22;
  QPushButton *screenshot_button;
  QPushButton *gif_button;

  void setupUi(QMainWindow *MainWindow) {
    if (MainWindow->objectName().isEmpty())
      MainWindow->setObjectName("MainWindow");
    MainWindow->resize(930, 652);
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName("centralwidget");
    label = new QLabel(centralwidget);
    label->setObjectName("label");
    label->setGeometry(QRect(30, 130, 151, 31));
    QFont font;
    font.setPointSize(24);
    label->setFont(font);
    label_2 = new QLabel(centralwidget);
    label_2->setObjectName("label_2");
    label_2->setGeometry(QRect(34, 270, 191, 31));
    label_2->setFont(font);
    slider_rotate_y = new QSlider(centralwidget);
    slider_rotate_y->setObjectName("slider_rotate_y");
    slider_rotate_y->setGeometry(QRect(30, 342, 181, 21));
    slider_rotate_y->setMinimum(-90);
    slider_rotate_y->setMaximum(90);
    slider_rotate_y->setOrientation(Qt::Horizontal);
    slider_rotate_x = new QSlider(centralwidget);
    slider_rotate_x->setObjectName("slider_rotate_x");
    slider_rotate_x->setGeometry(QRect(31, 302, 181, 25));
    slider_rotate_x->setAcceptDrops(false);
    slider_rotate_x->setMinimum(-90);
    slider_rotate_x->setMaximum(90);
    slider_rotate_x->setOrientation(Qt::Horizontal);
    slider_rotate_x->setTickPosition(QSlider::NoTicks);
    slider_rotate_z = new QSlider(centralwidget);
    slider_rotate_z->setObjectName("slider_rotate_z");
    slider_rotate_z->setGeometry(QRect(30, 382, 181, 25));
    slider_rotate_z->setMinimum(-90);
    slider_rotate_z->setMaximum(90);
    slider_rotate_z->setSingleStep(1);
    slider_rotate_z->setOrientation(Qt::Horizontal);
    slider_rotate_z->setInvertedAppearance(false);
    label_3 = new QLabel(centralwidget);
    label_3->setObjectName("label_3");
    label_3->setGeometry(QRect(34, 410, 121, 31));
    label_3->setFont(font);
    slider_scale = new QSlider(centralwidget);
    slider_scale->setObjectName("slider_scale");
    slider_scale->setGeometry(QRect(30, 442, 181, 25));
    slider_scale->setMinimum(-9);
    slider_scale->setMaximum(20);
    slider_scale->setSingleStep(1);
    slider_scale->setPageStep(10);
    slider_scale->setValue(0);
    slider_scale->setTracking(true);
    slider_scale->setOrientation(Qt::Horizontal);
    slider_scale->setInvertedAppearance(false);
    slider_scale->setInvertedControls(false);
    glviewport = new MyGlWidget(centralwidget);
    glviewport->setObjectName("glviewport");
    glviewport->setGeometry(QRect(280, 10, 640, 480));
    QPalette palette;
    QBrush brush(QColor(0, 0, 0, 255));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
    QBrush brush1(QColor(255, 255, 255, 255));
    brush1.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Button, brush1);
    palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
    QBrush brush2(QColor(127, 127, 127, 255));
    brush2.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
    QBrush brush3(QColor(170, 170, 170, 255));
    brush3.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
    palette.setBrush(QPalette::Active, QPalette::Text, brush);
    palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
    palette.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
    QBrush brush4(QColor(255, 255, 220, 255));
    brush4.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
    QBrush brush5(QColor(0, 0, 0, 128));
    brush5.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
    QBrush brush6(QColor(0, 0, 0, 216));
    brush6.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
    QBrush brush7(QColor(236, 236, 236, 255));
    brush7.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Inactive, QPalette::Button, brush7);
    QBrush brush8(QColor(245, 245, 245, 255));
    brush8.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush8);
    QBrush brush9(QColor(191, 191, 191, 255));
    brush9.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Inactive, QPalette::Dark, brush9);
    QBrush brush10(QColor(169, 169, 169, 255));
    brush10.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Inactive, QPalette::Mid, brush10);
    palette.setBrush(QPalette::Inactive, QPalette::Text, brush6);
    palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Window, brush7);
    palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush8);
    palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush1);
    QBrush brush11(QColor(0, 0, 0, 128));
    brush11.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush11);
#endif
    palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
    palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
    palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
    palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
    palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush8);
    palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush1);
    QBrush brush12(QColor(0, 0, 0, 128));
    brush12.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
    palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush12);
#endif
    glviewport->setPalette(palette);
    button_file_chooser = new QPushButton(centralwidget);
    button_file_chooser->setObjectName("button_file_chooser");
    button_file_chooser->setGeometry(QRect(200, 15, 61, 31));
    text_file__name = new QLineEdit(centralwidget);
    text_file__name->setObjectName("text_file__name");
    text_file__name->setGeometry(QRect(12, 20, 181, 21));
    text_file__name->setFrame(false);
    text_file__name->setReadOnly(true);
    label_4 = new QLabel(centralwidget);
    label_4->setObjectName("label_4");
    label_4->setGeometry(QRect(10, 302, 16, 21));
    QFont font1;
    font1.setPointSize(18);
    label_4->setFont(font1);
    label_5 = new QLabel(centralwidget);
    label_5->setObjectName("label_5");
    label_5->setGeometry(QRect(10, 342, 16, 21));
    label_5->setFont(font1);
    label_6 = new QLabel(centralwidget);
    label_6->setObjectName("label_6");
    label_6->setGeometry(QRect(10, 382, 16, 21));
    label_6->setFont(font1);
    label_7 = new QLabel(centralwidget);
    label_7->setObjectName("label_7");
    label_7->setGeometry(QRect(10, 242, 16, 21));
    label_7->setFont(font1);
    slider_move_x = new QSlider(centralwidget);
    slider_move_x->setObjectName("slider_move_x");
    slider_move_x->setGeometry(QRect(31, 162, 181, 25));
    slider_move_x->setAcceptDrops(false);
    slider_move_x->setMinimum(-15);
    slider_move_x->setMaximum(15);
    slider_move_x->setTracking(true);
    slider_move_x->setOrientation(Qt::Horizontal);
    slider_move_x->setInvertedAppearance(false);
    slider_move_x->setInvertedControls(false);
    slider_move_x->setTickPosition(QSlider::NoTicks);
    slider_move_z = new QSlider(centralwidget);
    slider_move_z->setObjectName("slider_move_z");
    slider_move_z->setGeometry(QRect(30, 242, 181, 25));
    slider_move_z->setMinimum(-5);
    slider_move_z->setMaximum(5);
    slider_move_z->setSliderPosition(0);
    slider_move_z->setOrientation(Qt::Horizontal);
    label_8 = new QLabel(centralwidget);
    label_8->setObjectName("label_8");
    label_8->setGeometry(QRect(10, 200, 16, 21));
    label_8->setFont(font1);
    slider_move_y = new QSlider(centralwidget);
    slider_move_y->setObjectName("slider_move_y");
    slider_move_y->setGeometry(QRect(30, 198, 181, 31));
    slider_move_y->setMinimum(-15);
    slider_move_y->setMaximum(15);
    slider_move_y->setOrientation(Qt::Horizontal);
    label_9 = new QLabel(centralwidget);
    label_9->setObjectName("label_9");
    label_9->setGeometry(QRect(10, 162, 16, 21));
    label_9->setFont(font1);
    label_move_x = new QLabel(centralwidget);
    label_move_x->setObjectName("label_move_x");
    label_move_x->setGeometry(QRect(220, 162, 41, 21));
    label_move_x->setFont(font1);
    label_move_y = new QLabel(centralwidget);
    label_move_y->setObjectName("label_move_y");
    label_move_y->setGeometry(QRect(220, 200, 41, 21));
    label_move_y->setFont(font1);
    label_move_z = new QLabel(centralwidget);
    label_move_z->setObjectName("label_move_z");
    label_move_z->setGeometry(QRect(220, 242, 41, 21));
    label_move_z->setFont(font1);
    label_rotate_x = new QLabel(centralwidget);
    label_rotate_x->setObjectName("label_rotate_x");
    label_rotate_x->setGeometry(QRect(220, 302, 41, 21));
    label_rotate_x->setFont(font1);
    label_rotate_y = new QLabel(centralwidget);
    label_rotate_y->setObjectName("label_rotate_y");
    label_rotate_y->setGeometry(QRect(220, 340, 41, 21));
    label_rotate_y->setFont(font1);
    label_rotate_z = new QLabel(centralwidget);
    label_rotate_z->setObjectName("label_rotate_z");
    label_rotate_z->setGeometry(QRect(220, 382, 41, 21));
    label_rotate_z->setFont(font1);
    label_scale = new QLabel(centralwidget);
    label_scale->setObjectName("label_scale");
    label_scale->setGeometry(QRect(220, 440, 41, 21));
    label_scale->setFont(font1);
    label_10 = new QLabel(centralwidget);
    label_10->setObjectName("label_10");
    label_10->setGeometry(QRect(30, 60, 151, 21));
    label_10->setFont(font1);
    label_11 = new QLabel(centralwidget);
    label_11->setObjectName("label_11");
    label_11->setGeometry(QRect(30, 90, 111, 21));
    label_11->setFont(font1);
    label_edges = new QLabel(centralwidget);
    label_edges->setObjectName("label_edges");
    label_edges->setGeometry(QRect(160, 90, 111, 21));
    label_edges->setFont(font1);
    label_vertexes = new QLabel(centralwidget);
    label_vertexes->setObjectName("label_vertexes");
    label_vertexes->setGeometry(QRect(160, 60, 111, 21));
    label_vertexes->setFont(font1);
    bg_color_picker = new QComboBox(centralwidget);
    bg_color_picker->setObjectName("bg_color_picker");
    bg_color_picker->setGeometry(QRect(460, 580, 91, 23));
    edge_color_picker = new QComboBox(centralwidget);
    edge_color_picker->setObjectName("edge_color_picker");
    edge_color_picker->setGeometry(QRect(460, 550, 91, 23));
    slider_thickness = new QSlider(centralwidget);
    slider_thickness->setObjectName("slider_thickness");
    slider_thickness->setGeometry(QRect(120, 540, 160, 31));
    slider_thickness->setMaximum(99);
    slider_thickness->setOrientation(Qt::Horizontal);
    projection_type = new QComboBox(centralwidget);
    projection_type->addItem(QString());
    projection_type->addItem(QString());
    projection_type->setObjectName("projection_type");
    projection_type->setGeometry(QRect(180, 610, 101, 23));
    vertex_color_picker = new QComboBox(centralwidget);
    vertex_color_picker->setObjectName("vertex_color_picker");
    vertex_color_picker->setGeometry(QRect(460, 610, 91, 23));
    label_12 = new QLabel(centralwidget);
    label_12->setObjectName("label_12");
    label_12->setGeometry(QRect(40, 540, 71, 31));
    QFont font2;
    font2.setPointSize(14);
    label_12->setFont(font2);
    label_13 = new QLabel(centralwidget);
    label_13->setObjectName("label_13");
    label_13->setGeometry(QRect(360, 550, 91, 21));
    label_13->setFont(font2);
    label_14 = new QLabel(centralwidget);
    label_14->setObjectName("label_14");
    label_14->setGeometry(QRect(360, 510, 191, 22));
    label_14->setFont(font1);
    label_15 = new QLabel(centralwidget);
    label_15->setObjectName("label_15");
    label_15->setGeometry(QRect(360, 580, 111, 21));
    label_15->setFont(font2);
    label_16 = new QLabel(centralwidget);
    label_16->setObjectName("label_16");
    label_16->setGeometry(QRect(360, 610, 91, 21));
    label_16->setFont(font2);
    label_17 = new QLabel(centralwidget);
    label_17->setObjectName("label_17");
    label_17->setGeometry(QRect(40, 610, 151, 21));
    label_17->setFont(font2);
    point_thickness_slider = new QSlider(centralwidget);
    point_thickness_slider->setObjectName("point_thickness_slider");
    point_thickness_slider->setGeometry(QRect(120, 575, 160, 31));
    point_thickness_slider->setOrientation(Qt::Horizontal);
    label_18 = new QLabel(centralwidget);
    label_18->setObjectName("label_18");
    label_18->setGeometry(QRect(40, 580, 71, 16));
    label_18->setFont(font2);
    label_19 = new QLabel(centralwidget);
    label_19->setObjectName("label_19");
    label_19->setGeometry(QRect(40, 510, 231, 21));
    label_19->setFont(font1);
    point_shape = new QComboBox(centralwidget);
    point_shape->addItem(QString());
    point_shape->addItem(QString());
    point_shape->addItem(QString());
    point_shape->setObjectName("point_shape");
    point_shape->setGeometry(QRect(668, 590, 91, 23));
    line_shape = new QComboBox(centralwidget);
    line_shape->addItem(QString());
    line_shape->addItem(QString());
    line_shape->setObjectName("line_shape");
    line_shape->setGeometry(QRect(668, 560, 91, 23));
    label_20 = new QLabel(centralwidget);
    label_20->setObjectName("label_20");
    label_20->setGeometry(QRect(610, 510, 151, 22));
    label_20->setFont(font1);
    label_21 = new QLabel(centralwidget);
    label_21->setObjectName("label_21");
    label_21->setGeometry(QRect(610, 560, 51, 21));
    label_21->setFont(font2);
    label_22 = new QLabel(centralwidget);
    label_22->setObjectName("label_22");
    label_22->setGeometry(QRect(610, 590, 81, 21));
    label_22->setFont(font2);
    screenshot_button = new QPushButton(centralwidget);
    screenshot_button->setObjectName("screenshot_button");
    screenshot_button->setGeometry(QRect(820, 530, 80, 41));
    gif_button = new QPushButton(centralwidget);
    gif_button->setObjectName("gif_button");
    gif_button->setGeometry(QRect(820, 580, 80, 41));
    MainWindow->setCentralWidget(centralwidget);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
  }  // setupUi

  void retranslateUi(QMainWindow *MainWindow) {
    MainWindow->setWindowTitle(
        QCoreApplication::translate("MainWindow", "3D Viewer v1.0", nullptr));
    label->setText(QCoreApplication::translate("MainWindow", "Move", nullptr));
    label_2->setText(
        QCoreApplication::translate("MainWindow", "Rotate", nullptr));
    label_3->setText(
        QCoreApplication::translate("MainWindow", "Scale", nullptr));
    button_file_chooser->setText(
        QCoreApplication::translate("MainWindow", "Browse", nullptr));
    label_4->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
    label_5->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
    label_6->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
    label_7->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
    label_8->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
    label_9->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
    label_move_x->setText(
        QCoreApplication::translate("MainWindow", "0", nullptr));
    label_move_y->setText(
        QCoreApplication::translate("MainWindow", "0", nullptr));
    label_move_z->setText(
        QCoreApplication::translate("MainWindow", "0", nullptr));
    label_rotate_x->setText(
        QCoreApplication::translate("MainWindow", "0", nullptr));
    label_rotate_y->setText(
        QCoreApplication::translate("MainWindow", "0", nullptr));
    label_rotate_z->setText(
        QCoreApplication::translate("MainWindow", "0", nullptr));
    label_scale->setText(
        QCoreApplication::translate("MainWindow", "1", nullptr));
    label_10->setText(
        QCoreApplication::translate("MainWindow", "Vertices :", nullptr));
    label_11->setText(
        QCoreApplication::translate("MainWindow", "Edges :", nullptr));
    label_edges->setText(
        QCoreApplication::translate("MainWindow", "0", nullptr));
    label_vertexes->setText(
        QCoreApplication::translate("MainWindow", "0", nullptr));
    projection_type->setItemText(
        0, QCoreApplication::translate("MainWindow", "central", nullptr));
    projection_type->setItemText(
        1, QCoreApplication::translate("MainWindow", "parallel", nullptr));

    label_12->setText(
        QCoreApplication::translate("MainWindow", "edge ", nullptr));
    label_13->setText(
        QCoreApplication::translate("MainWindow", "edges", nullptr));
    label_14->setText(
        QCoreApplication::translate("MainWindow", "Colors", nullptr));
    label_15->setText(
        QCoreApplication::translate("MainWindow", "background", nullptr));
    label_16->setText(
        QCoreApplication::translate("MainWindow", "vertex", nullptr));
    label_17->setText(
        QCoreApplication::translate("MainWindow", "Projection type", nullptr));
    label_18->setText(
        QCoreApplication::translate("MainWindow", "vertex", nullptr));
    label_19->setText(
        QCoreApplication::translate("MainWindow", "Thickness", nullptr));
    point_shape->setItemText(
        0, QCoreApplication::translate("MainWindow", "none", nullptr));
    point_shape->setItemText(
        1, QCoreApplication::translate("MainWindow", "square", nullptr));
    point_shape->setItemText(
        2, QCoreApplication::translate("MainWindow", "cicrle", nullptr));

    line_shape->setItemText(
        0, QCoreApplication::translate("MainWindow", "simple", nullptr));
    line_shape->setItemText(
        1, QCoreApplication::translate("MainWindow", "dash-dotted", nullptr));

    label_20->setText(
        QCoreApplication::translate("MainWindow", "Shape", nullptr));
    label_21->setText(
        QCoreApplication::translate("MainWindow", "edge ", nullptr));
    label_22->setText(
        QCoreApplication::translate("MainWindow", "vertex", nullptr));
    screenshot_button->setText(
        QCoreApplication::translate("MainWindow", "screeshot", nullptr));
    gif_button->setText(
        QCoreApplication::translate("MainWindow", "GIF", nullptr));
  }  // retranslateUi
};

namespace Ui {
class MainWindow : public Ui_MainWindow {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_MAINWINDOW_H
