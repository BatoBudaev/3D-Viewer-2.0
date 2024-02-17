#ifndef CPP4_3DVIEWER_V2_0_1_ROTATECOMMAND_H
#define CPP4_3DVIEWER_V2_0_1_ROTATECOMMAND_H

#include "../MVC/controller/controller.h"
#include "../MVC/model/model.h"
#include "../MVC/view/myglwidget.h"
#include "icommand.h"

namespace s21 {
class RotateCommand : public ICommand {
 public:
  RotateCommand(MyGlWidget *glWidget, Controller *controller, double angleX,
                double angleY, double angleZ);

  void execute() override;

 private:
  MyGlWidget *glWidget;
  s21::Controller *controller;
  double angleX;
  double angleY;
  double angleZ;
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_ROTATECOMMAND_H
