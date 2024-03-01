#include "controller.h"

namespace s21 {

Controller::Controller(Model* m) : model_(m) {}

UiObjectModel Controller::GetModel() {
  ModelFromParcer data = model_->GetModel();
  return converter_.MapToUiObject(data);
}

void Controller::ParseFile(std::string path_to_file) {
  model_->ParseFile(path_to_file);
}

UiObjectModel Controller::ScaleObject(double scale) {
  ModelFromParcer data = model_->ScaleObject(scale);
  return converter_.MapToUiObject(data);
}

UiObjectModel Controller::RotateObject(std::map<char, double> pair) {
  ModelFromParcer data = model_->RotateObject(pair);
  return converter_.MapToUiObject(data);
}

UiObjectModel Controller::MoveObject(double x, double y, double z) {
  ModelFromParcer data = model_->MoveObject(x, y, z);
  return converter_.MapToUiObject(data);
}

size_t Controller::GetNumberVertex() { return model_->GetNumberVertex(); }

size_t Controller::GetNumberEdge() { return model_->GetNumberEdge(); }

bool Controller::IsError() { return model_->IsError(); }

void Controller::SaveImage(QImage image, QString file_name) {
  model_->SaveImage(image, file_name);
}

void Controller::SaveGif(std::list<QImage> image_list, QString file_name) {
  model_->SaveGif(image_list, file_name);
}

QColor Controller::LoadBgColor() { return model_->LoadBgColor(); }
QColor Controller::LoadLineColor() { return model_->LoadLineColor(); }
QColor Controller::LoadPointColor() { return model_->LoadPointColor(); }
void Controller::SaveBgColor(QColor bg_color) { model_->SaveBgColor(bg_color); }
void Controller::SaveLineColor(QColor l_color) {
  model_->SaveLineColor(l_color);
}
void Controller::SavePointColor(QColor p_color) {
  model_->SavePointColor(p_color);
}
double Controller::LoadLineSize() { return model_->LoadLineSize(); }
double Controller::LoadPointSize() { return model_->LoadPointSize(); }
void Controller::SaveLineSize(double l_size) { model_->SaveLineSize(l_size); }
void Controller::SavePointSize(double p_size) { model_->SavePointSize(p_size); }
bool Controller::LoadDrawLine() { return model_->LoadDrawLine(); }
bool Controller::LoadDottedLine() { return model_->LoadDottedLine(); }
bool Controller::LoadDrawPoint() { return model_->LoadDrawPoint(); }
bool Controller::LoadCirclePoint() { return model_->LoadCirclePoint(); }
bool Controller::LoadCentralProjection() {
  return model_->LoadCentralProjection();
}
void Controller::SaveDrawLine(bool draw_line) {
  model_->SaveDrawLine(draw_line);
}
void Controller::SaveDottedLine(bool dotted_line) {
  model_->SaveDottedLine(dotted_line);
}
void Controller::SaveDrawPoint(bool draw_point) {
  model_->SaveDrawPoint(draw_point);
}
void Controller::SaveCirclePoint(bool circle_point) {
  model_->SaveCirclePoint(circle_point);
}
void Controller::SaveCentralProjection(bool central_projection) {
  model_->SaveCentralProjection(central_projection);
}

}  // namespace s21
