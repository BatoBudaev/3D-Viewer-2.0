
#include "tests.h"

#include <vector>
using namespace s21;

TEST(Primary, Move_1) {
  Model model = Model();
  model.object_.count_vertex = 9;
  model.object_.array_vertex = {-2.0, -2.0, -2.0, -1.0, -1.0,
                                -1.0, 0.0,  0.0,  0.0};
  Vertex ver(-2.0, -1.0, 0.0, 1.0);
  model.move(ver);
  std::vector<double> etalon = {-4.0, -3.0, -2.0, -3.0, -2.0,
                                -1.0, -2.0, -1.0, 0.0};
  EXPECT_EQ(model.object_.array_vertex.size(), etalon.size());
  for (size_t i = 0; i < etalon.size(); i++)
    EXPECT_DOUBLE_EQ(etalon.at(i), model.object_.array_vertex.at(i));
}

TEST(Primary, Move_2) {
  Model model = Model();
  model.object_.count_vertex = 9;
  model.object_.array_vertex = {-2.0, -2.0, -2.0, -1.0, -1.0, -1.0, -1.0, 0.0};
  Vertex ver(-2.0, -1.0, 0.0, 1.0);
  model.move(ver);
  EXPECT_EQ(model.error_code(), ERROR);
}

TEST(Primary, Move_3) {
  Model model = Model();
  model.object_.count_vertex = 2;
  model.object_.array_vertex = {-2.0, -2.0};
  Vertex ver(-2.0, -1.0, 0.0, 1.0);
  model.move(ver);
  EXPECT_EQ(model.error_code(), ERROR);
}

TEST(Primary, Parser_1) {
  Model model = Model();
  model.parser("tests/models/cube.obj");
  EXPECT_EQ(model.error_code(), OK);
}

TEST(Primary, Parser_2) {
  Model model = Model();
  model.parser("tests/models/glass.obj");
  EXPECT_EQ(model.error_code(), OK);
}

TEST(Primary, Parser_3) {
  Model model = Model();
  model.parser("tests/models/error.obj");
  EXPECT_EQ(model.error_code(), ERROR);
}

TEST(Primary, Parser_4) {
  Model model = Model();
  model.parser("tests/models/cube_bad_1.obj");
  EXPECT_EQ(model.error_code(), ERROR);
}

TEST(Primary, Parser_5) {
  Model model = Model();
  model.parser("tests/models/cube_bad_2.obj");
  EXPECT_EQ(model.error_code(), ERROR);
}

TEST(Primary, Parser_6) {
  Model model = Model();
  model.parser("tests/models/cube_bad_3.obj");
  EXPECT_EQ(model.error_code(), ERROR);
}

TEST(Primary, Rotate_1) {
  Model model = Model();
  model.object_.array_vertex = {-2.0, -2.0, -2.0, -1.0, -1.0,
                                -1.0, 0.0,  0.0,  0.0};
  Vertex ver(-2.0, -1.0, 0.0, 1.0);
  model.rotateX(1);
  std::vector<double> etalon = {-2.000000,
                                -1.9647905774382155,
                                -2.0346002031873494,
                                -1.000000,
                                -0.98239528871910775,
                                -1.0173001015936747,
                                0.000000,
                                0.000000,
                                0.000000};
  EXPECT_EQ(model.object_.array_vertex.size(), etalon.size());
  for (size_t i = 0; i < etalon.size(); i++)
    EXPECT_DOUBLE_EQ(etalon.at(i), model.object_.array_vertex.at(i));
}

TEST(Primary, Rotate_2) {
  Model model = Model();
  model.object_.array_vertex = {-2.0, -2.0, -2.0, -1.0, -1.0,
                                -1.0, 0.0,  0.0,  0.0};
  Vertex ver(-2.0, -1.0, 0.0, 1.0);
  model.rotateY(1);
  std::vector<double> etalon = {-2.0346002031873494,
                                -2.000000,
                                -1.9647905774382155,
                                -1.0173001015936747,
                                -1.000000,
                                -0.98239528871910775,
                                0.000000,
                                0.000000,
                                0.000000};
  for (size_t i = 0; i < etalon.size(); i++)
    EXPECT_DOUBLE_EQ(etalon.at(i), model.object_.array_vertex.at(i));
}

TEST(Primary, Rotate_3) {
  Model model = Model();
  model.object_.array_vertex = {-2.0, -2.0, -2.0, -1.0, -1.0,
                                -1.0, 0.0,  0.0,  0.0};
  Vertex ver(-2.0, -1.0, 0.0, 1.0);
  model.rotateZ(1);
  std::vector<double> etalon = {-1.9647905774382155,
                                -2.0346002031873494,
                                -2.000000,
                                -0.98239528871910775,
                                -1.0173001015936747,
                                -1.000000,
                                0.000000,
                                0.000000,
                                0.000000};
  EXPECT_EQ(model.object_.array_vertex.size(), etalon.size());
  for (size_t i = 0; i < etalon.size(); i++)
    EXPECT_DOUBLE_EQ(etalon.at(i), model.object_.array_vertex.at(i));
}

TEST(Primary, Rotate_4) {
  Model model = Model();
  model.object_.array_vertex = {-2.0, -2.0, -2.0, 0.0};
  Vertex ver(-2.0, -1.0, 0.0);
  model.rotateX(1);
  model.rotateY(1);
  model.rotateZ(1);
  EXPECT_EQ(model.error_code(), ERROR);
}

TEST(Primary, Scale_1) {
  Model model = Model();
  model.object_.array_vertex = {-2.0, -2.0, -2.0, -1.0, -1.0,
                                -1.0, 0.0,  0.0,  0.0};
  model.scale(3.0);
  std::vector<double> etalon = {-6.0, -6.0, -6.0, -3.0, -3.0,
                                -3.0, 0.0,  0.0,  0.0};
  EXPECT_EQ(model.object_.array_vertex.size(), etalon.size());
  for (size_t i = 0; i < etalon.size(); i++)
    EXPECT_DOUBLE_EQ(etalon.at(i), model.object_.array_vertex.at(i));
}

TEST(Primary, Scale_2) {
  Model model = Model();
  model.object_.array_vertex = {-2.0, -2.0};
  Vertex ver;
  model.scale(30);
  EXPECT_EQ(model.error_code(), ERROR);
}

TEST(Primary, Start_Frame_1) {
  Model model = Model();
  model.object_.array_vertex = {3.0, 2.0, 1.0, 1.0, 2.0, 3.0, 2.0, 1.0, 3.0};
  model.start_frame();
  std::vector<double> etalon = {
      2.00000000000000000, 1.33333333333333331, 0.66666666666666663,
      0.66666666666666663, 1.33333333333333333, 2.00000000000000000,
      1.33333333333333333, 0.66666666666666663, 2.00000000000000000};
  EXPECT_EQ(model.object_.array_vertex.size(), etalon.size());
  for (size_t i = 0; i < etalon.size(); i++)
    EXPECT_DOUBLE_EQ(etalon.at(i), model.object_.array_vertex.at(i));
}

TEST(Primary, Start_Frame_2) {
  Model model = Model();
  model.object_.array_vertex = {-2.0, -2.0};
  model.start_frame();
  EXPECT_EQ(model.error_code(), ERROR);
}