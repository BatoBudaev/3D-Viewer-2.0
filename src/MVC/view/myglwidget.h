/**
\file
\brief Заголовочный файл с описанием функций OpenGL

Данный файл содержит в себе определения основных
классов, используемых в демонстрационной программе
*/

#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <stdlib.h>

#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QSettings>
#include <QTimer>
#include <iostream>

#include "../controller/controller.h"
#include "../model/model.h"

using namespace s21;

/// @brief Виджет OpenGL для отрисовки трехмерных моделей
class MyGlWidget : public QOpenGLWidget, public QOpenGLFunctions {
  Q_OBJECT
 public:
  /// @brief Виджет для отрисовки объектов через функции OpenGL
  /// @param parent
  MyGlWidget(QWidget* parent);
  friend class MainWindow;
  double getTx() const { return tx; }
  double getTy() const { return ty; }
  double getTz() const { return tz; }

  void setTx(double value) { tx = value; }
  void setTy(double value) { ty = value; }
  void setTz(double value) { tz = value; }

  void setController(Controller* controller);

 protected:
  /// @brief Инициализация виджета OpenGL
  void initializeGL() override;
  /// @brief Отрисовка в виджете OpenGL
  void paintGL() override;
  /// @brief Изменение масштаба OpenGL
  /// @param[in] w Ширина
  /// @param[in] h Высота
  void resizeGL(int w, int h) override;
  /// @brief значения со слайдеров интерфейса (move x, y, z)
  double tx, ty, tz;
  /// @brief значения со слайдеров интерфейса (rotate x, y, z)
  double rx, ry, rz;
  /// @brief значения со слайдера интерфейса scale
  double scale;

  void updateSettings(int bg_color, int edge_color, int vertex_color,
                      double thickness, double point_thickness, int point_shape,
                      int line_shape);

 private:
  Controller* controller;

  QTimer tmr;
  /// @brief Индекс массива цветов определяющий цвет фона
  int bg_color;
  /// @brief Индекс массива цветов определяющий цвет граней
  int edge_color;
  /// @brief  Тип проекции  0 - центральная, 1 - параллельная
  int projection_type;
  /// @brief Индекс массива цветов определяющий цвет вершин
  int vertex_color;
  /// @brief Толщина граней
  double thickness;
  /// @brief Размер вершин
  double point_thickness;
  /// @brief Форма вершин
  int point_shape;
  /// @brief Тип линии граней 0 - сплошная, 1 - штриховая
  int line_shape;
  /// @brief Параметры ширины и высоты
  int w, h;
  QSettings settings;
};
#endif  // MYGLWIDGET_H
