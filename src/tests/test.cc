#include "../3DViewer/Model/CalculationsClass/Parcer/parcer.h"
#include "../3DViewer/Model/CalculationsClass/calculationsclass.h"
#include <gtest/gtest.h>

TEST(Parser, pars_cub) {
  std::string path = "tests/cub.obj";
  s21::Parcer parser;
  parser.ParseFile(path);
  s21::ModelFromParcer data = parser.get_model();
  std::vector<s21::VertexCoordinates> expected_vertex = {
      {1.000000, -1.000000, -1.000000}, {1.000000, -1.000000, 1.000000},
      {-1.000000, -1.000000, 1.000000}, {-1.000000, -1.000000, -1.000000},
      {1.000000, 1.000000, -0.999999},  {0.999999, 1.000000, 1.000001},
      {-1.000000, 1.000000, 1.000000},  {-1.000000, 1.000000, -1.000000}};
  std::vector<std::vector<int>> expected_facets = {
      {1, 2, 3}, {7, 6, 5}, {4, 5, 1}, {5, 6, 2}, {2, 6, 7}, {0, 3, 7},
      {0, 1, 3}, {4, 7, 5}, {0, 4, 1}, {1, 5, 2}, {3, 2, 7}, {4, 0, 7}};
  ASSERT_EQ(data.vertex_.size(), expected_vertex.size());
  auto s21_iter_vertex = data.vertex_.begin();
  auto expected_iter_vertex = expected_vertex.begin();
  while (s21_iter_vertex != data.vertex_.end() ||
         expected_iter_vertex != expected_vertex.end()) {
    ASSERT_NEAR((*s21_iter_vertex).x, (*expected_iter_vertex).x, 1e-6);
    ASSERT_NEAR((*s21_iter_vertex).y, (*expected_iter_vertex).y, 1e-6);
    ASSERT_NEAR((*s21_iter_vertex).z, (*expected_iter_vertex).z, 1e-6);
    ++s21_iter_vertex;
    ++expected_iter_vertex;
  }
  ASSERT_EQ(data.facets_.size(), expected_facets.size());
  auto s21_iter_facets = data.facets_.begin();
  auto expected_iter_facet = expected_facets.begin();
  while (s21_iter_facets != data.facets_.end() ||
         expected_iter_facet != expected_facets.end()) {
    ASSERT_EQ((*s21_iter_facets).size(), (*expected_iter_facet).size());
    auto s21_iter = (*s21_iter_facets).begin();
    auto expected_iter = (*expected_iter_facet).begin();
    while (s21_iter != (*s21_iter_facets).end() ||
           expected_iter != (*expected_iter_facet).end()) {
      ASSERT_EQ(*s21_iter, *expected_iter);
      ++s21_iter;
      ++expected_iter;
    }
    ++s21_iter_facets;
    ++expected_iter_facet;
  }
}

TEST(ParcerError, not_exist_file) {
  std::string path = "cub2.obj";
  s21::Parcer parser;
  parser.ParseFile(path);
  s21::ModelFromParcer data = parser.get_model();
  std::vector<s21::VertexCoordinates> expected_vertex;
  std::vector<std::vector<int>> expected_facets;
  ASSERT_EQ(data.vertex_.size(), expected_vertex.size());
  auto s21_iter_vertex = data.vertex_.begin();
  auto expected_iter_vertex = expected_vertex.begin();
  while (s21_iter_vertex != data.vertex_.end() ||
         expected_iter_vertex != expected_vertex.end()) {
    ASSERT_NEAR((*s21_iter_vertex).x, (*expected_iter_vertex).x, 1e-6);
    ASSERT_NEAR((*s21_iter_vertex).y, (*expected_iter_vertex).y, 1e-6);
    ASSERT_NEAR((*s21_iter_vertex).z, (*expected_iter_vertex).z, 1e-6);
    ++s21_iter_vertex;
    ++expected_iter_vertex;
  }
  ASSERT_EQ(data.facets_.size(), expected_facets.size());
  auto s21_iter_facets = data.facets_.begin();
  auto expected_iter_facet = expected_facets.begin();
  while (s21_iter_facets != data.facets_.end() ||
         expected_iter_facet != expected_facets.end()) {
    ASSERT_EQ((*s21_iter_facets).size(), (*expected_iter_facet).size());
    auto s21_iter = (*s21_iter_facets).begin();
    auto expected_iter = (*expected_iter_facet).begin();
    while (s21_iter != (*s21_iter_facets).end() ||
           expected_iter != (*expected_iter_facet).end()) {
      ASSERT_EQ(*s21_iter, *expected_iter);
      ++s21_iter;
      ++expected_iter;
    }
    ++s21_iter_facets;
    ++expected_iter_facet;
  }
}

TEST(VertexIterating, work) {
  std::string path = "tests/cub.obj";
  s21::Parcer parser;
  parser.ParseFile(path);
  s21::ModelFromParcer data = parser.get_model();
  std::vector<double> expected_vertex = {
      1.000000,  -1.000000, -1.000000, 1.000000,  -1.000000, 1.000000,
      -1.000000, -1.000000, 1.000000,  -1.000000, -1.000000, -1.000000,
      1.000000,  1.000000,  -0.999999, 0.999999,  1.000000,  1.000001,
      -1.000000, 1.000000,  1.000000,  -1.000000, 1.000000,  -1.000000};
  s21::VertexIterator s21_iter_vertex = data.VertexBegin();
  auto expected_iter_vertex = expected_vertex.begin();
  while (s21_iter_vertex != data.VertexEnd() &&
         expected_iter_vertex != expected_vertex.end()) {
    ASSERT_NEAR(*s21_iter_vertex, *expected_iter_vertex, 1e-6);
    ++s21_iter_vertex;
    ++expected_iter_vertex;
  }
}

TEST(Calculation, Normalize) {
  std::vector<s21::VertexCoordinates> expected_vertex = {
      {2.000000, 0.000000, -2.000000},
      {2.000000, 0.000000, 2.000000},
      {-2.000000, 0.000000, 2.000000},
  };
  std::string path = "tests/calc.obj";
  s21::CalculationsClass calc;
  calc.ParseFile(path);
  s21::ModelFromParcer data = calc.get_model();
  ASSERT_EQ(data.vertex_.size(), expected_vertex.size());
  auto s21_iter_vertex = data.vertex_.begin();
  auto expected_iter_vertex = expected_vertex.begin();
  while (s21_iter_vertex != data.vertex_.end() ||
         expected_iter_vertex != expected_vertex.end()) {
    ASSERT_NEAR((*s21_iter_vertex).x, (*expected_iter_vertex).x, 1e-6);
    ASSERT_NEAR((*s21_iter_vertex).y, (*expected_iter_vertex).y, 1e-6);
    ASSERT_NEAR((*s21_iter_vertex).z, (*expected_iter_vertex).z, 1e-6);
    ++s21_iter_vertex;
    ++expected_iter_vertex;
  }
}

TEST(Calculation, ScaleObject) {
  std::vector<s21::VertexCoordinates> expected_vertex = {
      {4.000000, 0.000000, -4.000000},
      {4.000000, 0.000000, 4.000000},
      {-4.000000, 0.000000, 4.000000},
  };
  std::string path = "tests/calc.obj";
  s21::CalculationsClass calc;
  calc.ParseFile(path);
  s21::ModelFromParcer data1 = calc.get_model();
  calc.ScaleObject(2);
  s21::ModelFromParcer data = calc.get_model();
  ASSERT_EQ(data.vertex_.size(), expected_vertex.size());
  auto s21_iter_vertex = data.vertex_.begin();
  auto expected_iter_vertex = expected_vertex.begin();
  while (s21_iter_vertex != data.vertex_.end() ||
         expected_iter_vertex != expected_vertex.end()) {
    ASSERT_NEAR((*s21_iter_vertex).x, (*expected_iter_vertex).x, 1e-6);
    ASSERT_NEAR((*s21_iter_vertex).y, (*expected_iter_vertex).y, 1e-6);
    ASSERT_NEAR((*s21_iter_vertex).z, (*expected_iter_vertex).z, 1e-6);
    ++s21_iter_vertex;
    ++expected_iter_vertex;
  }
}

TEST(Calculation, RotateObject) {
  std::vector<s21::VertexCoordinates> expected_vertex = {
      {2.000000, 0.000000, -2.000000},
      {2.000000, 0.000000, 2.000000},
      {-2.000000, 0.000000, 2.000000},
  };
  std::string path = "tests/calc.obj";
  s21::CalculationsClass calc;
  calc.ParseFile(path);
  //    std::map<char, double> coordinate = {{'x', 360.0}};
  calc.RotateObject({{'x', 360.0}});
  s21::ModelFromParcer data = calc.get_model();
  ASSERT_EQ(data.vertex_.size(), expected_vertex.size());
  auto s21_iter_vertex = data.vertex_.begin();
  auto expected_iter_vertex = expected_vertex.begin();
  while (s21_iter_vertex != data.vertex_.end() ||
         expected_iter_vertex != expected_vertex.end()) {
    ASSERT_NEAR((*s21_iter_vertex).x, (*expected_iter_vertex).x, 1e-6);
    ASSERT_NEAR((*s21_iter_vertex).y, (*expected_iter_vertex).y, 1e-6);
    ASSERT_NEAR((*s21_iter_vertex).z, (*expected_iter_vertex).z, 1e-6);
    ++s21_iter_vertex;
    ++expected_iter_vertex;
  }
}

TEST(Calculation, MoveObject) {
  std::vector<s21::VertexCoordinates> expected_vertex = {
      {4.000000, 2.000000, 0.000000},
      {4.000000, 2.000000, 4.000000},
      {0.000000, 2.000000, 4.000000},
  };
  std::string path = "tests/calc.obj";
  s21::CalculationsClass calc;
  calc.ParseFile(path);
  calc.MoveObject(2, 2, 2);
  s21::ModelFromParcer data = calc.get_model();
  ASSERT_EQ(data.vertex_.size(), expected_vertex.size());
  auto s21_iter_vertex = data.vertex_.begin();
  auto expected_iter_vertex = expected_vertex.begin();
  while (s21_iter_vertex != data.vertex_.end() ||
         expected_iter_vertex != expected_vertex.end()) {
    ASSERT_NEAR((*s21_iter_vertex).x, (*expected_iter_vertex).x, 1e-6);
    ASSERT_NEAR((*s21_iter_vertex).y, (*expected_iter_vertex).y, 1e-6);
    ASSERT_NEAR((*s21_iter_vertex).z, (*expected_iter_vertex).z, 1e-6);
    ++s21_iter_vertex;
    ++expected_iter_vertex;
  }
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
