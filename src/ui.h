#pragma once
// clang-format off
#include <raylib.h>
#include <raygui.h>
#include <map>
#include <string>
#include "settings.h"
#include "atlas.h"
// clang-format on

namespace Weather {
class UI {
public:
  struct FontSize {
    int s;
    int m;
    int l;
  };
  UI(const City cities[], const unsigned short numberCities,
     const char *pathAtlas, const char *pathFontBold,
     const char *pathFontRegular, const char *pathFontBig, const char *pathCelsius);
  ~UI();
  void DropdownMenu(const int screenWidthSize);
  int GetActiveItemDropdownMenu();
  void WeatherHeroCard(const std::map<std::string, std::string> &data);

private:
  std::map<const char *, int> dropdownMenuState;
  std::string dropdownMenuItems;
  Texture2D atlas;
  Texture2D celsius;
  std::map<std::string, Font> fonts;
  struct FontSize fontSize;
};
} // namespace Weather