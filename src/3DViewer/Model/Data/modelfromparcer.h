#ifndef CPP4_3DVIEWER_V2_0_1_SRC_MODEL_DATA_MODELFROMPARCER_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_MODEL_DATA_MODELFROMPARCER_H_

#include <vector>

#include "Iterator/vertexiterator.h"
#include "vertexcoordinates.h"

namespace s21 {

class ModelFromParcer {
 public:
  ModelFromParcer() = default;
  s21::VertexIterator VertexBegin() {
    return vertex_.size() > 0 ? VertexIterator(vertex_.begin())
                              : VertexIterator(vertex_.end());
  };
  s21::VertexIterator VertexEnd() { return VertexIterator(vertex_.end()); };
  std::vector<VertexCoordinates> vertex_;
  std::vector<std::vector<int>> facets_;
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_MODEL_DATA_MODELFROMPARCER_H_
