#include "colorsettings.h"

namespace s21 {

QColor ColorSettings::get() {
  QColor color = settings_->value(name_setting_).value<QColor>();
  return color;
}

void ColorSettings::set(QColor color) {
  settings_->setValue(name_setting_, color);
}

}  // namespace s21
