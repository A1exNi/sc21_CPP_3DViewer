#ifndef CPP4_3DVIEWER_V2_0_1_SRC_MODEL_DATA_ITERATOR_VERTEXITERATOR_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_MODEL_DATA_ITERATOR_VERTEXITERATOR_H_

#include <functional>
#include <map>
#include <vector>

#include "../vertexcoordinates.h"

namespace s21 {

enum Coordinate { X = 0, Y = 1, Z = 2 };

class VertexIterator {
 public:
  VertexIterator() = default;
  VertexIterator(std::vector<VertexCoordinates>::iterator other)
      : vertex_index_(other){};
  double& operator*();
  VertexIterator& operator++();
  bool operator==(const VertexIterator& other);
  bool operator!=(const VertexIterator& other);

 private:
  std::vector<VertexCoordinates>::iterator vertex_index_;
  int current_coordinate_ = X;
  std::map<int, std::function<double&()>> value_coordinate = {
      {X, [&]() -> double& { return (*vertex_index_).x; }},
      {Y, [&]() -> double& { return (*vertex_index_).y; }},
      {Z, [&]() -> double& { return (*vertex_index_).z; }},
  };
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_MODEL_DATA_ITERATOR_VERTEXITERATOR_H_
