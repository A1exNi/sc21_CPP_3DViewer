#ifndef CPP4_3DVIEWER_V2_0_1_SRC_MODEL_GIF_IMAGEGIF_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_MODEL_GIF_IMAGEGIF_H_

#include <QImage>
#include <QString>
#include <list>

namespace s21 {

class ImageGif {
 public:
  void SaveImage(QImage image, QString file_name);
  void SaveGif(std::list<QImage> image_list, QString file_name);
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_MODEL_GIF_IMAGEGIF_H_
