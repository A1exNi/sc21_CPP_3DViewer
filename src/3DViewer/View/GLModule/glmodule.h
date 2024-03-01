#ifndef CPP4_3DVIEWER_V2_0_1_SRC_VIEW_GLMODULE_GLMODULE_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_VIEW_GLMODULE_GLMODULE_H_

#include <QMouseEvent>
#include <QOpenGLWidget>
#include <QTimer>

#include "Controller/controller.h"
#include "qgifimage.h"

class GLModule : public QOpenGLWidget {
  Q_OBJECT
 public:
  explicit GLModule(QWidget *parent = nullptr) : QOpenGLWidget{parent} {};
  void SetLine(QColor colors);
  void SetPoint(QColor colors);
  void SetBack(QColor colors);
  void MoveObject(double x, double y, double z);
  void RotateObject(double x, double y, double z);
  void ScaleObject(double scale);
  void SetTransl(double change, char coord);
  void SetTranslRotate(double change, char coord);

  void set_controller(s21::Controller *c);
  void set_line_depth(double depth);
  void set_dot_depth(double depth);
  void set_dot_type(int type);
  void set_dotted_line(bool checked);
  void set_type_projection(bool checked);
  void LoadSettings();
  void Record();

  int check_timer_ = 1;
  QString name_gif_;

 private:
  s21::Controller *controller_;
  int type_projection_ = 0;  // 0 - Ортографическая, 1 - Перспективная проекции
  double red_background_ = 0.0, green_background_ = 0.0, blue_background_ = 0.0;
  double red_line_ = 1.0, green_line_ = 0.0, blue_line_ = 1.0;
  double red_point_ = 0.0, green_point_ = 1.0, blue_point_ = 1.0;
  double x_rot_ = 0.0, y_rot_ = 0.0, z_rot_ = 0.0;
  double x_rot_single_ = 0.0, y_rot_single_ = 0.0, z_rot_single_ = 0.0;
  QPoint m_pos_;
  double x_pos_ = 0.0, y_pos_ = 0.0, z_pos_ = 0.0;
  double start_x_ = 0.0, start_y_ = 0.0;
  double prev_scale_ = 1;
  double line_depth_ = 2.0, dot_depth_ = 1.0;
  int dotted_line_ = 0;  // 0 - сплошная, 1 - пунктир
  int dot_type_ =
      1;  // 0 - отсутствует отображение точек, 1 - круг, 2 - квадрат
  int save_ = 0;

  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;
  void mousePressEvent(QMouseEvent *) override;
  void mouseMoveEvent(QMouseEvent *) override;
  void DrawObj();

  int index_time_ = 0;
  QGifImage *gif_image = NULL;
  QTimer *timer_ = NULL;

 public slots:
  void Gif();
};

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_VIEW_GLMODULE_GLMODULE_H_
