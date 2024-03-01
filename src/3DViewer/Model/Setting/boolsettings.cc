#include "boolsettings.h"

namespace s21 {

bool BoolSettings::get() {
  bool setting = settings_->value(name_setting_).toBool();
  return setting;
}

void BoolSettings::set(bool setting) {
  settings_->setValue(name_setting_, setting);
}

}  // namespace s21
