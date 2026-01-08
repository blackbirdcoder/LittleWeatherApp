#pragma once
#include <map>
#include <string>

namespace Weather {

namespace Window {
extern const int WIDTH;
extern const int HEIGHT;
extern const char *TITLE;
extern const int FPS;
} // namespace Window

extern const unsigned short NUMBER_CITIES;

struct Palette {
  unsigned int dark;
  unsigned int accent;
  unsigned int light;
  unsigned int pleasant;
};

extern const Palette palette;

struct City {
  unsigned short id;
  std::string name;
  double latitude;
  double longitude;
};

enum Cities { KHARKOV, KYIV, MIAMI };
enum Token { PART_ONE, PART_TWO, PART_THREE };

extern const City CITIES[];

extern const char *HOST;
extern const std::map<Token, std::string> REQUEST_PATH;
extern const unsigned short NUMBER_CARDS;
} // namespace Weather