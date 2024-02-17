#include "controller.h"

namespace s21 {
Controller::Controller(Model &model) : model(model) {}

void Controller::parseModel() {
  FileManager *fileManager = FileManager::getInstance();
  model.parser(fileManager->getFileName());

  if (model.error_code() == 0) {
    model.start_frame();
    notifyObserversAboutResult("LOG: Load success.");
  } else {
    notifyObserversAboutError("Failed to load object.");
  }
}

void Controller::moveModel(Vertex offset) { model.move(offset); }

void Controller::rotateModelX(double angle) { model.rotateX(angle); }

void Controller::rotateModelY(double angle) { model.rotateY(angle); }

void Controller::rotateModelZ(double angle) { model.rotateZ(angle); }

void Controller::scaleModel(double value) { model.scale(value); }

size_t Controller::getVertexCount() const { return model.object_.count_vertex; }

const std::vector<double> &Controller::getVertexData() const {
  return model.object_.array_vertex;
}

size_t Controller::getPolygonCount() const {
  return model.object_.count_polygons;
}

const std::vector<int> &Controller::getPolygonData() const {
  return model.object_.array_polygon;
}
}  // namespace s21
