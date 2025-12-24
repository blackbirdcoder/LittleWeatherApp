#pragma once

extern const int W_WIDTH;
extern const int W_HEIGHT;
extern const char *TITLE;
extern const int FPS;
extern const char* CITIES;

struct Palette {
   unsigned int dark;
   unsigned int accent;
   unsigned int light;
   unsigned int pleasant;
};

extern const Palette palette;
