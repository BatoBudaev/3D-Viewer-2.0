#include <QApplication>

#include "../controller/controller.h"
#include "../model/model.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::Model model;
  Controller controller(model);
  MainWindow w(controller);
  w.show();
  return a.exec();
}
