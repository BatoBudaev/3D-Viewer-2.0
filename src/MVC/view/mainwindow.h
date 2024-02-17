/**
\file
\brief Заголовочный файл с описанием функций QT

Данный файл содержит в себе определения основных
классов, используемых в демонстрационной программе
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QTimer>

#include "../../patterns/movecommand.h"
#include "../../patterns/observer.h"
#include "../../patterns/rotatecommand.h"
#include "../../patterns/singleton.h"
#include "../controller/controller.h"
#include "../model/model.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public Observer {
  Q_OBJECT

 public:
  /// @brief Главное окно
  MainWindow(Controller &controller, QWidget *parent = nullptr);
  ~MainWindow();

 public:
  /// @brief Функция сохранения настроек при закрытии программы
  void save_settings();
  /// @brief Функция чтения настроек при открытии программы
  void load_settings();

 private:
  //   void save_frame();
  void create_gif();
  Controller &controller;

 private slots:
  /// @brief Функция выбора файла
  void on_button_file_chooser_clicked();
  /// @brief Функция движения слайдера X
  /// @param [in] position хранится величина, выбранная с помощью слайдера
  void on_slider_move_x_sliderMoved(int position);
  /// @brief Функция движения слайдера Y
  /// @param [in] position хранится величина, выбранная с помощью слайдера
  void on_slider_move_y_sliderMoved(int position);
  /// @brief Функция движения слайдера Z
  /// @param [in] position хранится величина, выбранная с помощью слайдера
  void on_slider_move_z_sliderMoved(int position);
  /// @brief Функция поворота слайдера X
  /// @param [in] position хранится величина, выбранная с помощью слайдера
  void on_slider_rotate_x_sliderMoved(int position);
  /// @brief Функция поворота слайдера Y
  /// @param [in] position хранится величина, выбранная с помощью слайдера
  void on_slider_rotate_y_sliderMoved(int position);
  /// @brief Функция поворота слайдера Z
  /// @param [in] position хранится величина, выбранная с помощью слайдера
  void on_slider_rotate_z_sliderMoved(int position);
  /// @brief Функция масштабирования
  /// @param [in] position хранится величина, выбранная с помощью слайдера
  void on_slider_scale_sliderMoved(int position);
  /// @brief Функция выбора цвета фона
  /// @param [in] position хранится величина, выбранная с помощью слайдера
  void on_bg_color_picker_activated(int index);
  /// @brief Функция выбора цвета ребер
  /// @param [in] index хранится номер выбранного поля в combox
  void on_edge_color_picker_activated(int index);
  /// @brief Функция выбора толщины граней
  /// @param [in] index хранится номер выбранного поля в combox
  void on_slider_thickness_sliderMoved(int position);
  /// @brief Функция выбора типа проекции
  /// @param [in] position хранится величина, выбранная с помощью слайдера
  void on_projection_type_activated(int index);
  /// @brief Передаёт значение величины выбранной с помощью слайдера в поле
  /// объекта виджета, определяющего значение толщины граней
  /// @param [in] index хранится номер выбранного поля в combox
  void on_point_thickness_slider_sliderMoved(int position);
  /// @brief Передаёт значение величины выбранной с помощью выпадающего списка в
  /// поле объекта виджета, определяющего индекс массива цветов
  /// @param [in] index хранится номер выбранного поля в combox
  void on_vertex_color_picker_activated(int index);
  /// @brief Передаёт  величину выбранную с помощью выпадающего списка в поле
  /// объекта виджета, флага, который определяет тип формы вершины
  /// @param [in] index хранится номер выбранного поля в combox
  void on_point_shape_activated(int index);
  /// @brief Передаёт  величину выбранную с помощью выпадающего списка в поле
  /// объекта виджета, флага, который определяет тип линии граней модели
  /// @param [in] index хранится номер выбранного поля в combox
  void on_line_shape_activated(int index);
  /// @brief Функция, по нажатию кнопки сохраняет буфер экрана в виде
  /// изображения
  void on_screenshot_button_clicked();
  /// @brief По нажатию кнопки создаёт .gif файл, содержащий запись
  /// происходящего на экране в течении последующих 5 секунд
  void on_gif_button_clicked();
  /// @brief Вызывается с помощью переменной QTimer tmr_gif каждые 100
  /// миллисекунд и заполняет массив типа QImage изображениями, из которых будет
  /// сформирован gif файл
  void save_frame();
  void updateResult(const QString &message) override;
  void updateError(const QString &error) override;

 private:
  /// @brief Сброс всех слайдеров в значения по умолчанию
  void reset_all_sliders();
  /// @brief Переменная Qt по умолчанию для взаимодействия с графическим
  /// интерфейсом
  Ui::MainWindow *ui;
  /// @brief Класс qt отвечает за сохранение значений параметров элементов
  /// интерфейса выбранных пользователем
  QSettings *settings;
  /// @brief Таймер, используется для создания .gif файлов
  QTimer tmr_gif;
  /// @brief Хранит изображения для .gif файла
  QImage image_arr[50];
  /// @brief Хранит текущий элемент массива, в который будет сохранено
  /// изображение
  int index_image_arr;
  /// @brief Индекс массива цветов определяющий цвет фона
  int bg_color;
  /// @brief Индекс массива цветов определяющий цвет граней
  int edge_color;
  /// @brief  Тип проекции  0 - центральная, 1 - параллельная
  int vertex_color;
  /// @brief Толщина граней
  double thickness;
  /// @brief Размер вершин
  double point_thickness;
  /// @brief Форма вершин
  int thickness_slider_position;
  int point_thickness_slider_position;
  int point_shape;
  /// @brief Тип линии граней 0 - сплошная, 1 - штриховая
  int line_shape;
};
#endif  // MAINWINDOW_H
