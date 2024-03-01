#ifndef CPP4_3DVIEWER_V2_0_1_SRC_VIEW_UIOBJECTMODEL_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_VIEW_UIOBJECTMODEL_H_

#include <vector>

namespace s21 {

struct UiObjectModel {
  std::vector<double> vertex;
  std::vector<std::vector<int>> facets;
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_VIEW_UIOBJECTMODEL_H_
