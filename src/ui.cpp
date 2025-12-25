#include "ui.h"
#include <raylib.h>

namespace WeatherApp {

UI::UI(const City cities[], const unsigned short numberCities) {
  dropdownMenuState["item"] = 0;
  dropdownMenuState["show"] = 1;

  for (int i = 0; i < numberCities; ++i) {
    if (i < numberCities - 1) {
      dropdownMenuItems += cities[i].name + ";";
    } else {
      dropdownMenuItems += cities[i].name;
    }
  }
}

void UI::DropdownMenu(const int screenWidth) {
  float width = 125.0f;
  Rectangle pos = {
      (screenWidth / 2.0f) - (width / 2.0f),
      20.0f,
      width,
      30.0f,
  };

  if (dropdownMenuState["show"]) {
    GuiLock();
  }
  if (GuiDropdownBox(pos, dropdownMenuItems.c_str(), &dropdownMenuState["item"],
                     (bool)dropdownMenuState["show"])) {
    dropdownMenuState["show"] = !dropdownMenuState["show"];
  }
  GuiUnlock();
}

int UI::GetActiveItemDropdownMenu() { return dropdownMenuState["item"]; }
} // namespace WeatherApp