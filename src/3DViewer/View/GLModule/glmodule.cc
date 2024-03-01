#include "glmodule.h"

void GLModule::SetLine(QColor colors) {
  red_line_ = colors.redF();
  green_line_ = colors.greenF();
  blue_line_ = colors.blueF();
  controller_->SaveLineColor(colors);
}

void GLModule::SetPoint(QColor colors) {
  red_point_ = colors.redF();
  green_point_ = colors.greenF();
  blue_point_ = colors.blueF();
  controller_->SavePointColor(colors);
}

void GLModule::SetBack(QColor colors) {
  red_background_ = colors.redF();
  green_background_ = colors.greenF();
  blue_background_ = colors.blueF();
  controller_->SaveBgColor(colors);
}

void GLModule::MoveObject(double x, double y, double z) {
  this->controller_->MoveObject(x, y, z);
}

void GLModule::RotateObject(double x, double y, double z) {
  this->controller_->RotateObject({{'x', x}, {'y', y}, {'z', z}});
}

void GLModule::ScaleObject(double scale) {
  this->controller_->ScaleObject(1 / prev_scale_);
  this->controller_->ScaleObject(scale);
  prev_scale_ = scale;
}

void GLModule::SetTransl(double change, char coord) {
  if (coord == 'x') {
    this->controller_->MoveObject(-x_pos_ + change, 0, 0);
    x_pos_ = change;
  } else if (coord == 'y') {
    this->controller_->MoveObject(0, -y_pos_ + change, 0);
    y_pos_ = change;
  } else {
    this->controller_->MoveObject(0, 0, -z_pos_ + change);
    z_pos_ = change;
  }
}

void GLModule::SetTranslRotate(double change, char coord) {
  if (coord == 'x') {
    this->controller_->RotateObject({{'x', -x_rot_single_ + change}});
    x_rot_single_ = change;
  } else if (coord == 'y') {
    this->controller_->RotateObject({{'y', -y_rot_single_ + change}});
    y_rot_single_ = change;
  } else {
    this->controller_->RotateObject({{'z', -z_rot_single_ + change}});
    z_rot_single_ = change;
  }
}

void GLModule::initializeGL() {
  glEnable(GL_DEPTH_TEST);
  LoadSettings();
}

void GLModule::resizeGL(int w, int h) { glViewport(0, 0, w, h); }

void GLModule::paintGL() {
  float size = 3, fov = 60.0 * M_PI / 180,
        far = 15;  // far можно задать любым, лишь бы все умещалось.
  float heap_height = size / (2 * tan(fov / 2));
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (type_projection_ == 0) {
    glOrtho(-size, size, -size, size, -far, far);
  } else {
    glFrustum(-size, size, -size, size, heap_height, far);
  }
  glClearColor(red_background_, green_background_, blue_background_, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0, 0, -3 * heap_height);

  DrawObj();
}

void GLModule::mousePressEvent(QMouseEvent *mo) {
  m_pos_ = mo->pos();
  start_x_ = mo->pos().x();
  start_y_ = mo->pos().y();
}

void GLModule::mouseMoveEvent(QMouseEvent *mo) {
  x_rot_ = 1 / M_PI * (mo->pos().y() - start_y_);
  y_rot_ = 1 / M_PI * (mo->pos().x() - start_x_);
  controller_->RotateObject(
      std::map<char, double>{{'x', x_rot_}, {'y', y_rot_}});
  start_x_ = mo->pos().x();
  start_y_ = mo->pos().y();
  update();
}

void GLModule::DrawObj() {
  s21::UiObjectModel model = controller_->GetModel();
  glVertexPointer(3, GL_DOUBLE, 0, model.vertex.data());
  glEnableClientState(GL_VERTEX_ARRAY);
  if (dot_type_) {
    if (dot_type_ == 1) glEnable(GL_POINT_SMOOTH);
    glColor3d(red_point_, green_point_, blue_point_);
    glPointSize(dot_depth_);
    glDrawArrays(GL_POINTS, 0, model.vertex.size() / 3);
  }
  glEnable(GL_LINE_STIPPLE);
  glLineWidth(line_depth_);
  glColor3d(red_line_, green_line_, blue_line_);
  glLineStipple(2, dotted_line_ ? 0x00FF : 0xFFFF);
  for (std::vector<int> facet : model.facets) {
    glDrawElements(GL_LINE_LOOP, facet.size(), GL_UNSIGNED_INT, facet.data());
  }
  if (dot_type_ == 1) glDisable(GL_POINT_SMOOTH);
  glDisable(GL_LINE_STIPPLE);
  glDisableClientState(GL_VERTEX_ARRAY);
}

void GLModule::set_controller(s21::Controller *c) { controller_ = c; }

void GLModule::set_line_depth(double depth) {
  line_depth_ = depth;
  controller_->SaveLineSize(depth);
}

void GLModule::set_dot_depth(double depth) {
  dot_depth_ = depth;
  controller_->SavePointSize(depth);
}

void GLModule::set_dot_type(int type) {
  dot_type_ = type;
  if (dot_type_ == 1) controller_->SaveCirclePoint(true);  // круг
  if (dot_type_ == 2) {
    controller_->SaveCirclePoint(false);  // квадрат
  }
  if (dot_type_ == 0) {
    controller_->SaveDrawPoint(false);  // отсутствует
  } else {
    controller_->SaveDrawPoint(true);
  }
}

void GLModule::set_dotted_line(bool checked) {
  dotted_line_ = checked;
  controller_->SaveDottedLine(checked);
}

void GLModule::set_type_projection(bool checked) {
  type_projection_ = checked;
  controller_->SaveCentralProjection(checked);
}

void GLModule::Record() {
  gif_image = new QGifImage();
  timer_ = new QTimer();
  check_timer_ = 0;
  timer_->start(50);
  connect(timer_, SIGNAL(timeout()), this, SLOT(Gif()));
}

void GLModule::Gif() {
  index_time_++;
  gif_image->addFrame(GLModule::grabFramebuffer());
  if (index_time_ == 50) {
    timer_->stop();
    gif_image->save(name_gif_);
    index_time_ = 0;
    check_timer_ = 1;
    delete timer_;
    delete gif_image;
  }
}

void GLModule::LoadSettings() {
  dotted_line_ = controller_->LoadDottedLine();
  SetBack(controller_->LoadBgColor());
  SetPoint(controller_->LoadPointColor());
  SetLine(controller_->LoadLineColor());
  line_depth_ = controller_->LoadLineSize();
  dot_depth_ = controller_->LoadPointSize();
  if (controller_->LoadCirclePoint()) {
    dot_type_ = 1;
  } else {
    dot_type_ = 2;
  }
  if (!controller_->LoadDrawPoint()) dot_type_ = 0;
  type_projection_ = controller_->LoadCentralProjection();
}
