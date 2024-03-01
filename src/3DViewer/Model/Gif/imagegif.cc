#include "imagegif.h"

#include "qgifimage.h"

namespace s21 {

void ImageGif::SaveImage(QImage image, QString file_name) {
  image.save(file_name);
}

void ImageGif::SaveGif(std::list<QImage> image_list, QString file_name) {
  QSize gif_size(640, 480);
  QGifImage gif(gif_size);
  for (auto&& image : image_list) {
    gif.addFrame(image.scaled(gif_size));
  }
  gif.save(file_name);
}

}  // namespace s21
