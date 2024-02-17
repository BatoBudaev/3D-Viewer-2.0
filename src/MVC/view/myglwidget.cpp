#include "myglwidget.h"

#include "3rdparty/QtGifImage/src/gifimage/qgifimage.h"

#define COLOR_NUM 6

///// @brief Структура вершин и ребер для функций отрисовки OpenGL
MyGlWidget::MyGlWidget(QWidget* parent) : QOpenGLWidget{parent} {
  scale = 1;
  bg_color = 1;
  edge_color = 0;
  vertex_color = 3;
  projection_type = 0;
  point_shape = 0;
}

void MyGlWidget::setController(Controller* ctrl) { controller = ctrl; }

void MyGlWidget::initializeGL() {
  initializeOpenGLFunctions();
  glEnable(GL_DEPTH_TEST);
  tmr.start(100);
}

void MyGlWidget::resizeGL(int w, int h) {
  this->w = w;
  this->h = h;
  glViewport(0, 0, w, h);
}

void MyGlWidget::paintGL() {
  const Qt::GlobalColor colour_qt[COLOR_NUM] = {Qt::gray,     Qt::white,
                                                Qt::darkBlue, Qt::darkRed,
                                                Qt::darkCyan, Qt::darkYellow};
  QColor bg_qcolor = QColor(colour_qt[bg_color]);
  QColor edge_qcolor = QColor(colour_qt[edge_color]);
  QColor vertex_qcolor = QColor(colour_qt[vertex_color]);
  double width = 3 * thickness;
  double point_size = 3 * point_thickness;

  glClearColor(bg_qcolor.redF(), bg_qcolor.greenF(), bg_qcolor.blueF(), 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (projection_type == 0)
    glFrustum(-1, 1, -1, 1, 1, 10);
  else
    glOrtho(-1, 1, -1, 1, 1, 10);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  double scale = 0.2;
  if (projection_type == 1) {
    glScaled(scale, scale, scale);
    glTranslated(0, 0, -10);
  } else {
    glTranslated(0, 0, -5);
  }

  glVertexPointer(3, GL_DOUBLE, 0, controller->getVertexData().data());
  glLineStipple(6, 0x3333);

  glLineStipple(6, 0x3333);

  glEnableClientState(GL_VERTEX_ARRAY);

  glColor3d(vertex_qcolor.redF(), vertex_qcolor.greenF(),
            vertex_qcolor.blueF());
  glPointSize(point_size);
  if (line_shape == 1) glEnable(GL_LINE_STIPPLE);
  if (point_shape == 2) glEnable(GL_POINT_SMOOTH);
  if (point_shape != 0) {
    glDrawArrays(GL_POINTS, 0, controller->getVertexCount() / 3);
  }
  if (point_shape == 2) glDisable(GL_POINT_SMOOTH);
  if (line_shape == 0) glDisable(GL_LINE_STIPPLE);

  glColor3d(edge_qcolor.redF(), edge_qcolor.greenF(), edge_qcolor.blueF());
  glLineWidth(width);
  glDrawElements(GL_LINES, controller->getPolygonCount() * 2, GL_UNSIGNED_INT,
                 controller->getPolygonData().data());
  glDisableClientState(GL_VERTEX_ARRAY);
}

void MyGlWidget::updateSettings(int bg_color, int edge_color, int vertex_color,
                                double thickness, double point_thickness,
                                int point_shape, int line_shape) {
  this->bg_color = bg_color;
  this->edge_color = edge_color;
  this->vertex_color = vertex_color;
  this->thickness = thickness;
  this->point_thickness = point_thickness;
  this->point_shape = point_shape;
  this->line_shape = line_shape;

  update();
  repaint();
}
