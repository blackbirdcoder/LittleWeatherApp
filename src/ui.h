#pragma once
// clang-format off
#include <bits/types/time_t.h>
#include <raylib.h>
#include <raygui.h>
#include <map>
#include <string>
#include "settings.h"
#include "atlas.h"
#include <list>
#include <ctime>
#include <vector>
// clang-format on

namespace Weather {
class UI {
public:
  bool isRefresh;
  struct FontSize {
    int s;
    int m;
    int l;
  };
  struct PositionCelsius {
    float offsetXForOneDigit;
    float offsetXForTwoDigit;
    float offsetXForThreeDigit;
    float offsetY;
  };
  UI(const City cities[], const unsigned short numberCities,
     const char *pathAtlas, const char *pathFontBold,
     const char *pathFontRegular, const char *pathFontBig,
     const char *pathCelsius);
  ~UI();
  void DropdownMenu(const int screenWidthSize);
  int GetActiveItemDropdownMenu();
  void WeatherHeroCard(const std::map<std::string, std::string> &data);
  void
  WeatherHourlyCard(const std::vector<std::map<std::string, std::string>> &data);
  void WeatherPredictionsCard(
      const std::vector<std::map<std::string, std::string>> &data);
  void ShowDayOfWeek(time_t timeCity);
  void ButtonRefresh(const int screenWidthSize, const int screenWHightSize);

private:
  std::map<const char *, int> dropdownMenuState;
  std::string dropdownMenuItems;
  Texture2D atlas;
  Texture2D celsius;
  std::map<std::string, Font> fonts;
  struct FontSize fontSize;
  struct PositionCelsius positionCelsius;
  void drawCelsius(const PositionCelsius &positionCelsius,
                   const std::string &key);
};
} // namespace Weather