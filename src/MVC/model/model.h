/**
@file
@brief Заголовочный файл с описанием функций

Для установи программы выполните команду make находясь в папке src.
Для создания дистрибутива выполните команду make dist находясь в папке src.

Графический пользовательский интерфейс содержит:

Кнопку для выбора файла с моделью и поле для вывода его названия.
Зону визуализации каркасной модели.
Кнопку/кнопки и поля ввода для перемещения модели.
Кнопку/кнопки и поля ввода для поворота модели.
Кнопку/кнопки и поля ввода для масштабирования модели.
Информацию о загруженной модели - название файла, кол-во вершин и ребер.

Программа позволяет настраивать тип проекции (параллельная и центральная)
Программа позволяет настраивать тип (сплошная, пунктирная), цвет и толщину
ребер, способ отображения (отсутствует, круг, квадрат), цвет и размер вершин
Программа позволяет выбирать цвет фона
Настройки сохраняются между перезапусками программы

Программа сохраняет  полученные ("отрендеренные") изображения в файл в форматах
bmp и jpeg Программа позволяет по специальной кнопке записывать небольшие
"скринкасты" - текущие пользовательские аффинные преобразования загруженного
объекта в gif-анимацию (640x480, 10fps, 5s)
*/

#ifndef __SRC_MVC_MODEL_H__
#define __SRC_MVC_MODEL_H__
/// @brief подключение дополнительных библиотек для корректной работы getline
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#define OK 0
#define ERROR 1

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "surface.h"
#include "vertex.h"

namespace s21 {
class Model {
 public:
  Model();

  /// @brief Parser to fill Surface with data from file
  /// @param filename Name of source file
  void parser(std::string filename);
  /// @brief Move whole object by offset
  /// @param offset XYZ offset values
  void move(Vertex offset);
  /// @brief Rotate object allong the X axis
  /// @param angle Angle of ratation
  void rotateX(double angle);
  /// @brief Rotate object allong the X axis
  /// @param angle Angle of ratation
  void rotateY(double angle);
  /// @brief Rotate object allong the X axis
  /// @param angle Angle of ratation
  void rotateZ(double angle);
  /// @brief Scale object
  /// @param value value of scale (i.e. x1.0, x30)
  void scale(double value);
  /// @brief Center an object
  void start_frame();

  /// @brief Get current error_code
  /// @return error_value OK or ERROR
  int error_code();

  /// @brief Object data structure
  Surface object_;

 private:
  void parse_count(std::string filename);
  size_t parse_f_count(std::string);
  void parse_f(std::string line);
  void reset_data();
  int error_code_;
};

}  // namespace s21

#endif  // __SRC_MVC_MODEL_H__
