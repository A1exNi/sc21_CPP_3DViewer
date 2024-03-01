#include "converter.h"

namespace s21 {

Converter& Converter::getInstance() {
  static Converter converter;
  return converter;
}

UiObjectModel Converter::MapToUiObject(ModelFromParcer model) {
  std::vector<double> vertex;
  VertexIterator end = model.VertexEnd();
  for (VertexIterator iterator = model.VertexBegin(); iterator != end;
       ++iterator) {
    vertex.push_back(*iterator);
  }
  return UiObjectModel{
      .vertex = vertex,
      .facets = model.facets_,
  };
}

}  // namespace s21
