#include "wallpaper.h"
#include <raylib.h>

Wallpaper::Wallpaper(const char *fileName) { this->fileName = fileName; }

void Wallpaper::Set(int w_width, int w_height) {
  image = LoadTexture((this->fileName));
  image.width = w_width;
  image.height = w_height;
}

void Wallpaper::Draw() { DrawTexture(image, 0, 0, WHITE); }
