#ifndef CPP4_3DVIEWER_V2_0_1_SRC_MODEL_CALCULATIONSCLASS_CALCULATIONSCLASS_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_MODEL_CALCULATIONSCLASS_CALCULATIONSCLASS_H_

#include <math.h>

#include <functional>
#include <map>

#include "Parcer/parcer.h"

namespace s21 {

class CalculationsClass : public Observer {
 public:
  CalculationsClass() { parcer_.AddObserver(this); };
  ~CalculationsClass() { parcer_.DeleteObserver(this); }
  void ParseFile(std::string path_to_file);
  ModelFromParcer ScaleObject(double scale);
  ModelFromParcer RotateObject(std::map<char, double> pair);
  ModelFromParcer MoveObject(double x, double y, double z);
  size_t GetNumberVertex();
  size_t GetNumberEdge();
  double LoadLineSize();
  double LoadPointSize();
  void SaveLineSize(double lSize);
  void SavePointSize(double pSize);
  bool LoadDrawLine();
  bool LoadDottedLine();
  bool LoadDrawPoint();
  bool LoadCirclePoint();
  bool LoadCentralProjection();
  void SaveDrawLine(bool drawLine);
  void SaveDottedLine(bool dottedLine);
  void SaveDrawPoint(bool drawPoint);
  void SaveCirclePoint(bool circlePoint);
  void SaveCentralProjection(bool centralProjection);
  ModelFromParcer get_model() const;
  bool get_error() const;

 private:
  Parcer parcer_;
  ModelFromParcer object_;
  bool error_ = true;
  std::map<char, std::function<void(VertexCoordinates &, double)>>
      func_for_rotate = {
          {'x',
           [&](VertexCoordinates &vertex, double radian) -> void {
             double y = vertex.y;
             double z = vertex.z;
             vertex.y = y * cos(radian) - sin(radian) * z;
             vertex.z = y * sin(radian) + cos(radian) * z;
           }},
          {'y',
           [&](VertexCoordinates &vertex, double radian) -> void {
             double x = vertex.x;
             double z = vertex.z;
             vertex.x = x * cos(radian) + sin(radian) * z;
             vertex.z = -x * sin(radian) + cos(radian) * z;
           }},
          {'z',
           [&](VertexCoordinates &vertex, double radian) -> void {
             double x = vertex.x;
             double y = vertex.y;
             vertex.x = x * cos(radian) - sin(radian) * y;
             vertex.y = x * sin(radian) + cos(radian) * y;
           }},
      };

  void SendModel() override;
  void SendError() override;
  void Normalize(ModelFromParcer &model);
  std::pair<double, double> SearchRangeAndCenterCoordinate(
      std::list<double> coordinates);
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_MODEL_CALCULATIONSCLASS_CALCULATIONSCLASS_H_
