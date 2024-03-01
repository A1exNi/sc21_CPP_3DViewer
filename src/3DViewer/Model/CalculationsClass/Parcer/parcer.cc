#include "parcer.h"

namespace s21 {

ModelFromParcer Parcer::get_model() const { return model_; }

void Parcer::ParseFile(std::string path_to_file) {
  ClearData();
  std::ifstream file(path_to_file);
  if (file.is_open()) {
    for (std::string str; getline(file, str);) {
      if (str[0] == 'v' && str[1] == ' ') {
        WriteVertex(str);
      } else if (str[0] == 'f' && str[1] == ' ') {
        WriteFacets(str);
      }
    }
    file.close();
    SendModel();
  } else {
    SendError();
  }
}

void Parcer::ClearData() {
  model_.vertex_.clear();
  model_.facets_.clear();
}

void Parcer::WriteVertex(std::string str) {
  VertexCoordinates vertex_сoordinates;
  std::string string;
  std::istringstream iss(str);
  iss >> string >> vertex_сoordinates.x >> vertex_сoordinates.y >>
      vertex_сoordinates.z;
  model_.vertex_.push_back(vertex_сoordinates);
}

void Parcer::WriteFacets(std::string str) {
  std::vector<int> vertex_in_facets;
  size_t count_vertex_now = model_.vertex_.size();
  for (size_t i = 0; i < str.length(); ++i) {
    if (str[i] == ' ' &&
        ((str[i + 1] >= '0' && str[i + 1] <= '9') || str[i + 1] == '-')) {
      std::istringstream iss(&(str[i]));
      int number_vertex;
      iss >> number_vertex;
      if (number_vertex < 0) {
        number_vertex += count_vertex_now;
      } else {
        number_vertex -= 1;
      }
      vertex_in_facets.push_back(number_vertex);
    }
  }
  model_.facets_.push_back(vertex_in_facets);
}

}  // namespace s21
