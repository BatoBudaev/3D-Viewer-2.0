#ifndef __CPP4_3DVIEWER_V2_0_1_CONTROLLER_H__
#define __CPP4_3DVIEWER_V2_0_1_CONTROLLER_H__

#include <QDebug>
#include <QObject>

#include "../../patterns/singleton.h"
#include "../../patterns/subject.h"
#include "../model/model.h"

namespace s21 {

/// @brief Controller class to link view and model
class Controller : public QObject, public Subject {
  Q_OBJECT

 public:
  /// @brief Basic controller constructor
  /// @param model Model entity
  explicit Controller(Model &model);

 public slots:

  void parseModel();

  void moveModel(Vertex offset);

  void rotateModelX(double angle);

  void rotateModelY(double angle);

  void rotateModelZ(double angle);

  void scaleModel(double value);

  size_t getVertexCount() const;

  const std::vector<double> &getVertexData() const;

  size_t getPolygonCount() const;

  const std::vector<int> &getPolygonData() const;

 private:
  Model &model;
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_CONTROLLER_H
