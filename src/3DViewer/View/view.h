#ifndef CPP4_3DVIEWER_V2_0_1_SRC_VIEW_VIEW_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_VIEW_VIEW_H_

#include <QColorDialog>
#include <QFileDialog>
#include <QMainWindow>

#include "../Controller/controller.h"
#include "GLModule/glmodule.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

namespace s21 {

class View : public QMainWindow {
  Q_OBJECT

 public:
  View(Controller *controller, QWidget *parent = nullptr);
  ~View();

  void SetLine(QColor colors);
  void SetPoint(QColor colors);
  void SetBack(QColor colors);

 private:
  Ui::View *ui;
  Controller *controller_;

 private slots:
  void on_open_file_Button_clicked();
  void on_color_Button_clicked();
  void on_line_spinBox_valueChanged(double value);
  void on_dot_spinBox_valueChanged(int value);
  void on_sqr_point_checkBox_currentIndexChanged();
  void on_checkLines_clicked(bool checked);
  void on_frustum_check_clicked(bool checked);
  void on_pushButton_moveXYZ_clicked();
  void on_pushButton_rotateXYZ_clicked();
  void on_doubleSpinBox_valueChanged(double value);
  void on_transl_x_SpinBox_valueChanged(double value);
  void on_trans_y_SpinBox_valueChanged(double value);
  void on_trans_z_SpinBox_valueChanged(double value);
  void on_rotate_x_SpinBox_valueChanged(double value);
  void on_rotate_y_SpinBox_valueChanged(double value);
  void on_rotate_z_SpinBox_valueChanged(double value);
  void on_save_jpeg_clicked();
  void on_save_bmp_clicked();
  void on_save_gif_clicked();
};

}  // namespace s21

#endif  // VIEW_H
