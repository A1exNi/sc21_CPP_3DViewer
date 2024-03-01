#ifndef CPP4_3DVIEWER_V2_0_1_SRC_MODEL_SETTING_SIZESETTINGS_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_MODEL_SETTING_SIZESETTINGS_H_

#include <QColor>
#include <QSettings>

namespace s21 {

class SizeSettings {
 public:
  SizeSettings(QString n, QSettings *s) : name_setting_(n), settings_(s){};
  double get();
  void set(double size);

 private:
  QString name_setting_;
  QSettings *settings_;
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_MODEL_SETTING_SIZESETTINGS_H_
