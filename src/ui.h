#pragma once
// clang-format off
#include <raygui.h>
#include <map>
#include <string>
#include "settings.h"
// clang-format on

namespace Weather {
class UI {
public:
  UI(const City cities[], const unsigned short numberCities);
  void DropdownMenu(const int screenWidthSize);
  int GetActiveItemDropdownMenu();

private:
  std::map<const char *, int> dropdownMenuState;
  std::string dropdownMenuItems;
};
} // namespace WeatherApp