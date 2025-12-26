#pragma once
#include <raylib.h>

namespace Weather {

class Wallpaper {
public:
  Wallpaper(const char *fileName);
  void Set(int w_width, int w_height);
  void Draw();

private:
  const char *fileName;
  Texture2D image;
};
} // namespace WeatherApp