#ifndef CPP4_3DVIEWER_V2_0_1_SRC_MODEL_SETTING_BOOLSETTINGS_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_MODEL_SETTING_BOOLSETTINGS_H_

#include <QColor>
#include <QSettings>

namespace s21 {

class BoolSettings {
 public:
  BoolSettings(QString n, QSettings *s) : name_setting_(n), settings_(s){};
  bool get();
  void set(bool setting);

 private:
  QString name_setting_;
  QSettings *settings_;
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_MODEL_SETTING_BOOLSETTINGS_H_
