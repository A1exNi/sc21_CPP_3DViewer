#include <QApplication>

#include "View/view.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::Model m;
  s21::Controller c(&m);
  s21::View w(&c);
  w.setWindowTitle("3D_Viewer v2.0");
  w.show();
  return a.exec();
}
