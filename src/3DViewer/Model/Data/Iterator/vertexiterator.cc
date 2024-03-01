#include "vertexiterator.h"

namespace s21 {

double& VertexIterator::operator*() {
  return value_coordinate[current_coordinate_]();
}

VertexIterator& VertexIterator::operator++() {
  if (current_coordinate_ == Z) {
    ++vertex_index_;
    current_coordinate_ = X;
  } else {
    ++current_coordinate_;
  }
  return *this;
}

bool VertexIterator::operator==(const VertexIterator& other) {
  return (vertex_index_ == other.vertex_index_ &&
          current_coordinate_ == other.current_coordinate_);
}

bool VertexIterator::operator!=(const VertexIterator& other) {
  return (vertex_index_ != other.vertex_index_ ||
          current_coordinate_ != other.current_coordinate_);
}

}  // namespace s21
