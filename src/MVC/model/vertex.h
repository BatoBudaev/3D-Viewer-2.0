#ifndef __SRC_MVC_VERTEX_H__
#define __SRC_MVC_VERTEX_H__

namespace s21 {
class Vertex {
 public:
  Vertex();
  Vertex(double x, double y, double z);
  Vertex(double x, double y, double z, double w);

  // @brief X coordinate
  double x_;
  /// @brief Y coordinate
  double y_;
  /// @brief Z coordinate
  double z_;
  /// @brief W coordinate
  double w_;
};

}  // namespace s21

#endif  // __SRC_MVC_MODEL_H__
