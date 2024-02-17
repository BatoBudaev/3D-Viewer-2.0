#ifndef CPP4_3DVIEWER_V2_0_1_MOVECOMMAND_H
#define CPP4_3DVIEWER_V2_0_1_MOVECOMMAND_H

#include "../MVC/controller/controller.h"
#include "../MVC/model/model.h"
#include "../MVC/view/myglwidget.h"
#include "icommand.h"

namespace s21 {
class MoveCommand : public ICommand {
 public:
  MoveCommand(MyGlWidget *glWidget, Controller *controller, double moveX,
              double moveY, double moveZ);

  void execute() override;

 private:
  MyGlWidget *glWidget;
  Controller *controller;
  double moveX, moveY, moveZ;
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_MOVECOMMAND_H
