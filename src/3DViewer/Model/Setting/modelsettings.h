#ifndef CPP4_3DVIEWER_V2_0_1_SRC_MODEL_SETTING_MODELSETTINGS_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_MODEL_SETTING_MODELSETTINGS_H_

#include "boolsettings.h"
#include "colorsettings.h"
#include "sizesettings.h"

namespace s21 {

class ModelSettings {
 public:
  static ModelSettings *getInstance();
  ColorSettings *bgColor;
  ColorSettings *lColor;
  ColorSettings *pColor;
  SizeSettings *lSize;
  SizeSettings *pSize;
  BoolSettings *drawLine;
  BoolSettings *dottedLine;
  BoolSettings *drawPoint;
  BoolSettings *circlePoint;
  BoolSettings *centralProjection;

 private:
  static ModelSettings *p_;
  QSettings *settings_;
  ModelSettings();
  ModelSettings(const ModelSettings &other) = delete;
  ModelSettings(ModelSettings &&other) = delete;
  ModelSettings &operator=(const ModelSettings &other) = delete;
  ModelSettings &operator=(ModelSettings &&other) = delete;
  void SetDefaultSettings();
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_MODEL_SETTING_MODELSETTINGS_H_
