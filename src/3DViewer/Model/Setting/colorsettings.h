#ifndef CPP4_3DVIEWER_V2_0_1_SRC_MODEL_SETTING_COLORSETTINGS_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_MODEL_SETTING_COLORSETTINGS_H_

#include <QColor>
#include <QSettings>

namespace s21 {

class ColorSettings {
 public:
  ColorSettings(QString n, QSettings *s) : name_setting_(n), settings_(s){};
  QColor get();
  void set(QColor color);

 private:
  QString name_setting_;
  QSettings *settings_;
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_MODEL_SETTING_COLORSETTINGS_H_
