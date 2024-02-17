#include "vertex.h"
using namespace s21;

Vertex::Vertex() {
  x_ = 0;
  y_ = 0;
  z_ = 0;
  w_ = 0;
}

Vertex::Vertex(double x, double y, double z) {
  x_ = x;
  y_ = y;
  z_ = z;
  w_ = 0;
}

Vertex::Vertex(double x, double y, double z, double w) {
  x_ = x;
  y_ = y;
  z_ = z;
  w_ = w;
}
