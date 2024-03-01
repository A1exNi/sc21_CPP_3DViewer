#include "calculationsclass.h"

#include <set>

namespace s21 {

void CalculationsClass::ParseFile(std::string path_to_file) {
  parcer_.ParseFile(path_to_file);
}

ModelFromParcer CalculationsClass::ScaleObject(double scale) {
  if (!error_) {
    for (VertexCoordinates &vertex : object_.vertex_) {
      vertex.x *= scale;
      vertex.y *= scale;
      vertex.z *= scale;
    }
  }
  return object_;
}

ModelFromParcer CalculationsClass::RotateObject(std::map<char, double> pair) {
  for (std::pair<const char, double> &radian : pair) {
    radian.second *= M_PI / 180;
  }
  if (!error_) {
    for (VertexCoordinates &vertex : object_.vertex_) {
      for (std::pair<char, double> radian : pair) {
        func_for_rotate[radian.first](vertex, radian.second);
      }
    }
  }
  return object_;
}

ModelFromParcer CalculationsClass::MoveObject(double x, double y, double z) {
  if (!error_) {
    for (VertexCoordinates &vertex : object_.vertex_) {
      vertex.x += x;
      vertex.y += y;
      vertex.z += z;
    };
  }
  return object_;
}

size_t CalculationsClass::GetNumberVertex() {
  return (error_) ? 0 : object_.vertex_.size();
}

size_t CalculationsClass::GetNumberEdge() {
  if (error_) return 0;
  std::set<std::pair<int, int>> edge;
  for (std::vector<int> facet : object_.facets_) {
    if (facet.size() > 1) {
      std::vector<int>::iterator end = facet.end();
      for (std::vector<int>::iterator it = facet.begin(); it != end; ++it) {
        int num1 = *it;
        int num2 = ((it + 1) != facet.end()) ? *(it + 1) : *facet.begin();
        if (num1 < num2) {
          edge.insert({num1, num2});
        } else {
          edge.insert({num2, num1});
        }
      }
    }
  }
  return edge.size();
}

void CalculationsClass::SendModel() {
  ModelFromParcer model = parcer_.get_model();
  error_ = false;
  if (!model.vertex_.empty()) Normalize(model);
  object_ = model;
}

void CalculationsClass::SendError() { error_ = true; }

void CalculationsClass::Normalize(ModelFromParcer &model) {
  std::list<double> coordinate_x;
  std::list<double> coordinate_y;
  std::list<double> coordinate_z;
  for (VertexCoordinates vertex : model.vertex_) {
    coordinate_x.push_back(vertex.x);
    coordinate_y.push_back(vertex.y);
    coordinate_z.push_back(vertex.z);
  }
  std::pair<double, double> x = SearchRangeAndCenterCoordinate(coordinate_x);
  std::pair<double, double> y = SearchRangeAndCenterCoordinate(coordinate_y);
  std::pair<double, double> z = SearchRangeAndCenterCoordinate(coordinate_z);
  double dmax = std::max({x.first, y.first, z.first});
  double scale = (1 - (1 * (-3))) / dmax;  // подгоняет его под рамки поля
  for (VertexCoordinates &vertex : model.vertex_) {
    vertex.x = (vertex.x - x.second) * scale;
    vertex.y = (vertex.y - y.second) * scale;
    vertex.z = (vertex.z - z.second) * scale;
  }
}

std::pair<double, double> CalculationsClass::SearchRangeAndCenterCoordinate(
    std::list<double> coordinates) {
  double min = *std::min_element(coordinates.begin(), coordinates.end());
  double max = *std::max_element(coordinates.begin(), coordinates.end());
  double range = max - min;
  double center = min + (max - min) / 2;
  return std::pair<double, double>(range, center);
}

ModelFromParcer CalculationsClass::get_model() const { return object_; }

bool CalculationsClass::get_error() const { return error_; }

}  // namespace s21
