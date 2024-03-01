#include "sizesettings.h"

namespace s21 {

double SizeSettings::get() {
  double size = settings_->value(name_setting_).toDouble();
  return size;
}

void SizeSettings::set(double size) {
  settings_->setValue(name_setting_, size);
}

}  // namespace s21
