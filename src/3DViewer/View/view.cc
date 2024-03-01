#include "view.h"

#include "ui_view.h"

namespace s21 {

View::View(Controller *c, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::View), controller_(c) {
  ui->setupUi(this);
  setFixedSize(size());
  this->ui->glwidget->set_controller(controller_);
  this->ui->checkLines->setChecked(controller_->LoadDottedLine());
  this->ui->frustum_check->setChecked(controller_->LoadCentralProjection());
  if (!controller_->LoadDrawPoint()) {
    this->ui->sqr_point_checkBox->setCurrentIndex(1);
  } else {
    if (controller_->LoadCirclePoint()) {
      this->ui->sqr_point_checkBox->setCurrentIndex(0);
    } else {
      this->ui->sqr_point_checkBox->setCurrentIndex(2);
    }
  }
  this->ui->line_spinBox->setValue(controller_->LoadLineSize());
  this->ui->dot_spinBox->setValue(controller_->LoadPointSize());
}

View::~View() { delete ui; }

void View::on_open_file_Button_clicked() {
  QString filters("OBJ (*.obj)");
  QString file_name = QFileDialog::getOpenFileName(this, "Open file",
                                                   "../../../../obj", filters);
  if (file_name.isEmpty() == false) {
    controller_->ParseFile(file_name.toStdString());
    if (controller_->IsError() == true) {
      ui->labelFileName->setText("Ошибка открытия");
    } else {
      ui->labelCountOfVertex->setText(
          QString::number(controller_->GetNumberVertex()));
      ui->labelCountOfFacets->setText(
          QString::number(controller_->GetNumberEdge()));
      this->ui->glwidget->update();
      ui->labelFileName->setText(file_name.section("/", -1, -1));
    }
  }
}

void View::on_color_Button_clicked() {
  QColor colors;
  colors = QColorDialog::getColor(Qt::white, this);
  if (ui->comboBox->currentIndex() == 0) {
    SetLine(colors);
  } else if (ui->comboBox->currentIndex() == 1) {
    SetPoint(colors);
  } else if (ui->comboBox->currentIndex() == 2) {
    SetBack(colors);
  }
  this->ui->glwidget->update();
}

void View::SetLine(QColor colors) { this->ui->glwidget->SetLine(colors); }

void View::SetPoint(QColor colors) { this->ui->glwidget->SetPoint(colors); }

void View::SetBack(QColor colors) { this->ui->glwidget->SetBack(colors); }

void View::on_line_spinBox_valueChanged(double value) {
  this->ui->glwidget->set_line_depth(value);
  this->ui->glwidget->update();
}

void View::on_dot_spinBox_valueChanged(int value) {
  this->ui->glwidget->set_dot_depth(value);
  this->ui->glwidget->update();
}

void View::on_sqr_point_checkBox_currentIndexChanged() {
  if (ui->sqr_point_checkBox->currentIndex() == 0) {
    this->ui->glwidget->set_dot_type(1);
  } else if (ui->sqr_point_checkBox->currentIndex() == 1) {
    this->ui->glwidget->set_dot_type(0);
  } else if (ui->sqr_point_checkBox->currentIndex() == 2) {
    this->ui->glwidget->set_dot_type(2);
  }
  this->ui->glwidget->update();
}

void View::on_checkLines_clicked(bool checked) {
  this->ui->glwidget->set_dotted_line(checked);
  this->ui->glwidget->update();
}

void View::on_frustum_check_clicked(bool checked) {
  this->ui->glwidget->set_type_projection(checked);
  this->ui->glwidget->update();
}
void View::on_pushButton_moveXYZ_clicked() {
  this->ui->glwidget->MoveObject(ui->transl_x_SpinBox->value(),
                                 ui->trans_y_SpinBox->value(),
                                 ui->trans_z_SpinBox->value());
  this->ui->glwidget->update();
}

void View::on_pushButton_rotateXYZ_clicked() {
  this->ui->glwidget->RotateObject(ui->rotate_x_SpinBox->value(),
                                   ui->rotate_y_SpinBox->value(),
                                   ui->rotate_z_SpinBox->value());
  this->ui->glwidget->update();
}

void View::on_doubleSpinBox_valueChanged(double value) {
  this->ui->glwidget->ScaleObject(value);
  this->ui->glwidget->update();
}

void View::on_transl_x_SpinBox_valueChanged(double value) {
  this->ui->glwidget->SetTransl(value, 'x');
  this->ui->glwidget->update();
}

void View::on_trans_y_SpinBox_valueChanged(double value) {
  this->ui->glwidget->SetTransl(value, 'y');
  this->ui->glwidget->update();
}

void View::on_trans_z_SpinBox_valueChanged(double value) {
  this->ui->glwidget->SetTransl(value, 'z');
  this->ui->glwidget->update();
}

void View::on_rotate_x_SpinBox_valueChanged(double value) {
  this->ui->glwidget->SetTranslRotate(value, 'x');
  this->ui->glwidget->update();
}

void View::on_rotate_y_SpinBox_valueChanged(double value) {
  this->ui->glwidget->SetTranslRotate(value, 'y');
  this->ui->glwidget->update();
}

void View::on_rotate_z_SpinBox_valueChanged(double value) {
  this->ui->glwidget->SetTranslRotate(value, 'z');
  this->ui->glwidget->update();
}

void View::on_save_jpeg_clicked() {
  QString file = QFileDialog::getSaveFileName(
      this, "Save as...", "~/ourViewer/saved/name.jpeg", tr("JPEG (*.jpeg)"));
  QImage image = ui->glwidget->grabFramebuffer();
  controller_->SaveImage(image, file);
}

void View::on_save_bmp_clicked() {
  QString file = QFileDialog::getSaveFileName(
      this, "Save as...", "../saved/name.bmp", tr("BMP (*.bmp)"));
  QImage image = ui->glwidget->grabFramebuffer();
  controller_->SaveImage(image, file);
}

void View::on_save_gif_clicked() {
  QString name = QFileDialog::getSaveFileName(
      this, "Save as...", "../saved/name.gif", tr("GIF (*.gif)"));
  if (!name.isEmpty() && this->ui->glwidget->check_timer_ == 1) {
    this->ui->glwidget->name_gif_ = name;
    this->ui->glwidget->Record();
  }
}

}  // namespace s21
