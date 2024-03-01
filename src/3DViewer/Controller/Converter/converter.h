#ifndef CPP4_3DVIEWER_V2_0_1_SRC_CONTROLLER_CONVERTER_CONVERTER_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_CONTROLLER_CONVERTER_CONVERTER_H_

#include "../../Model/CalculationsClass/Parcer/parcer.h"
#include "../../View/uiobjectmodel.h"

namespace s21 {

class Converter {
 public:
  static Converter& getInstance();
  Converter(const Converter&) = delete;
  Converter(Converter&&) = delete;
  Converter& operator=(const Converter&) = delete;
  Converter& operator=(Converter&&) = delete;
  UiObjectModel MapToUiObject(ModelFromParcer model);

 private:
  Converter() = default;
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_CONTROLLER_CONVERTER_CONVERTER_H_
