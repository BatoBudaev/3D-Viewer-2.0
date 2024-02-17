#include "movecommand.h"

namespace s21 {
MoveCommand::MoveCommand(MyGlWidget *glWidget, Controller *controller, double x,
                         double y, double z)
    : glWidget(glWidget),
      controller(controller),
      moveX(x),
      moveY(y),
      moveZ(z) {}

void MoveCommand::execute() {
  if (controller) {
    s21::Vertex a = {moveX, moveY, moveZ, 0};
    controller->moveModel(a);

    double currentTx = glWidget->getTx();
    double currentTy = glWidget->getTy();
    double currentTz = glWidget->getTz();

    glWidget->setTx(currentTx + moveX);
    glWidget->setTy(currentTy + moveY);
    glWidget->setTz(currentTz + moveZ);
    glWidget->update();
  }
}
}  // namespace s21
