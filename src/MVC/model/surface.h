#ifndef __SRC_MVC_SURFACE_H__
#define __SRC_MVC_SURFACE_H__

typedef long unsigned int size_t;

#include <vector>

namespace s21 {

class Surface {
 public:
  Surface();
  /// @brief Count of vertex
  size_t count_vertex;
  /// @brief Vertex array for OpenGL
  std::vector<double> array_vertex;
  /// @brief Polygons count
  size_t count_polygons;
  /// @brief Polygons array for OpenGL
  std::vector<int> array_polygon;
};

}  // namespace s21

#endif  // __SRC_MVC_SURFACE_H__
