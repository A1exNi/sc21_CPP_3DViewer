#include "model.h"

namespace s21 {

ModelFromParcer Model::GetModel() { return calc_.get_model(); }

void Model::ParseFile(std::string path_to_file) {
  calc_.ParseFile(path_to_file);
}

ModelFromParcer Model::ScaleObject(double scale) {
  return calc_.ScaleObject(scale);
}

ModelFromParcer Model::RotateObject(std::map<char, double> pair) {
  return calc_.RotateObject(pair);
}

ModelFromParcer Model::MoveObject(double x, double y, double z) {
  return calc_.MoveObject(x, y, z);
}

size_t Model::GetNumberVertex() { return calc_.GetNumberVertex(); }

size_t Model::GetNumberEdge() { return calc_.GetNumberEdge(); }

bool Model::IsError() { return calc_.get_error(); }

void Model::SaveImage(QImage image, QString fileName) {
  saver_.SaveImage(image, fileName);
}

void Model::SaveGif(std::list<QImage> imageList, QString fileName) {
  saver_.SaveGif(imageList, fileName);
}

QColor Model::LoadBgColor() { return settings_->bgColor->get(); }
QColor Model::LoadLineColor() { return settings_->lColor->get(); }
QColor Model::LoadPointColor() { return settings_->pColor->get(); }
void Model::SaveBgColor(QColor bg_color) { settings_->bgColor->set(bg_color); }
void Model::SaveLineColor(QColor l_color) { settings_->lColor->set(l_color); }
void Model::SavePointColor(QColor p_color) { settings_->pColor->set(p_color); }
double Model::LoadLineSize() { return settings_->lSize->get(); }
double Model::LoadPointSize() { return settings_->pSize->get(); }
void Model::SaveLineSize(double l_size) { settings_->lSize->set(l_size); }
void Model::SavePointSize(double p_size) { settings_->pSize->set(p_size); }
bool Model::LoadDrawLine() { return settings_->drawLine->get(); }
bool Model::LoadDottedLine() { return settings_->dottedLine->get(); }
bool Model::LoadDrawPoint() { return settings_->drawPoint->get(); }
bool Model::LoadCirclePoint() { return settings_->circlePoint->get(); }
bool Model::LoadCentralProjection() {
  return settings_->centralProjection->get();
}
void Model::SaveDrawLine(bool draw_line) {
  settings_->drawLine->set(draw_line);
}
void Model::SaveDottedLine(bool dotted_line) {
  settings_->dottedLine->set(dotted_line);
}
void Model::SaveDrawPoint(bool draw_point) {
  settings_->drawPoint->set(draw_point);
}
void Model::SaveCirclePoint(bool circle_point) {
  settings_->circlePoint->set(circle_point);
}
void Model::SaveCentralProjection(bool central_projection) {
  settings_->centralProjection->set(central_projection);
}

}  // namespace s21
