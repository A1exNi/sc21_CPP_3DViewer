#ifndef CPP4_3DVIEWER_V2_0_1_SRC_MODEL_CALCULATIONSCLASS_PARCER_PARCER_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_MODEL_CALCULATIONSCLASS_PARCER_PARCER_H_

#include <fstream>
#include <sstream>

#include "../../Data/modelfromparcer.h"
#include "../../Observer/observer.h"

namespace s21 {

class Parcer : public Observable {
 public:
  Parcer() = default;
  void ParseFile(std::string PathToFile);
  ModelFromParcer get_model() const;

 private:
  ModelFromParcer model_;
  void ClearData();
  void WriteVertex(std::string str);
  void WriteFacets(std::string str);
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_MODEL_CALCULATIONSCLASS_PARCER_PARCER_H_
