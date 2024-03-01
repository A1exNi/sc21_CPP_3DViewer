#ifndef CPP4_3DVIEWER_V2_0_1_SRC_CONTROLLER_CONTROLLER_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_CONTROLLER_CONTROLLER_H_

#include "../Model/model.h"
#include "Converter/converter.h"

namespace s21 {

class Controller {
 public:
  Controller(Model* m);

  UiObjectModel GetModel();
  void ParseFile(std::string path_to_file);
  UiObjectModel ScaleObject(double scale);
  UiObjectModel RotateObject(std::map<char, double> pair);
  UiObjectModel MoveObject(double x, double y, double z);
  size_t GetNumberVertex();
  size_t GetNumberEdge();
  bool IsError();
  void SaveImage(QImage image, QString file_name);
  void SaveGif(std::list<QImage> image_list, QString file_name);
  QColor LoadBgColor();
  QColor LoadLineColor();
  QColor LoadPointColor();
  void SaveBgColor(QColor bg_color);
  void SaveLineColor(QColor l_color);
  void SavePointColor(QColor p_color);
  double LoadLineSize();
  double LoadPointSize();
  void SaveLineSize(double l_size);
  void SavePointSize(double p_size);
  bool LoadDrawLine();
  bool LoadDottedLine();
  bool LoadDrawPoint();
  bool LoadCirclePoint();
  bool LoadCentralProjection();
  void SaveDrawLine(bool draw_line);
  void SaveDottedLine(bool dotted_line);
  void SaveDrawPoint(bool draw_point);
  void SaveCirclePoint(bool circle_point);
  void SaveCentralProjection(bool central_projection);

 private:
  Model* model_;
  Converter& converter_ = Converter::getInstance();
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_CONTROLLER_CONTROLLER_H_
