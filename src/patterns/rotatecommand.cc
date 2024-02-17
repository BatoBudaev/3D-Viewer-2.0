#include "rotatecommand.h"

namespace s21 {
RotateCommand::RotateCommand(MyGlWidget *glWidget, Controller *controller,
                             double angleX, double angleY, double angleZ)
    : glWidget(glWidget),
      controller(controller),
      angleX(angleX),
      angleY(angleY),
      angleZ(angleZ) {}

void RotateCommand::execute() {
  controller->rotateModelX(angleX);
  controller->rotateModelY(angleY);
  controller->rotateModelZ(angleZ);
  glWidget->update();
}
}  // namespace s21
