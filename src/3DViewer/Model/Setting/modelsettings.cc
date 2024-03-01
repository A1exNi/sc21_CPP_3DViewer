#include "modelsettings.h"

#include <iostream>

namespace s21 {

ModelSettings* ModelSettings::getInstance() {
  if (!p_) p_ = new ModelSettings();
  return p_;
}

ModelSettings* ModelSettings::p_ = nullptr;

ModelSettings::ModelSettings() {
  settings_ = new QSettings("School21", "3DViewer2.0");
  bgColor = new ColorSettings("bgColor", settings_);
  lColor = new ColorSettings("lColor", settings_);
  pColor = new ColorSettings("pColor", settings_);
  lSize = new SizeSettings("lSize", settings_);
  pSize = new SizeSettings("pSize", settings_);
  drawLine = new BoolSettings("drawLine", settings_);
  dottedLine = new BoolSettings("dottedLine", settings_);
  drawPoint = new BoolSettings("drawPoint", settings_);
  circlePoint = new BoolSettings("circlePoint", settings_);
  centralProjection = new BoolSettings("centralProjection", settings_);
  SetDefaultSettings();
}

void ModelSettings::SetDefaultSettings() {
  if (!settings_->contains("bgColor")) bgColor->set(QColor(Qt::black));
  if (!settings_->contains("lColor")) lColor->set(QColor(Qt::green));
  if (!settings_->contains("pColor")) pColor->set(QColor(Qt::green));
  if (!settings_->contains("lSize")) lSize->set(1.0);
  if (!settings_->contains("pSize")) pSize->set(5.0);
  if (!settings_->contains("drawLine")) drawLine->set(true);
  if (!settings_->contains("dottedLine")) dottedLine->set(false);
  if (!settings_->contains("drawPoint")) drawPoint->set(true);
  if (!settings_->contains("circlePoint")) circlePoint->set(true);
  if (!settings_->contains("centralProjection")) centralProjection->set(false);
}

}  // namespace s21
