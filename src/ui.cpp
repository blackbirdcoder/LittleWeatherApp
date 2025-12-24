#include "ui.h"
#include <raylib.h>

UI::UI(const char *cities) {
  stateDropdownMenu["item"] = 0;
  stateDropdownMenu["show"] = 1;
  this->cities = cities;
}

void UI::DropdownMenu(const int screenWidth) {
  float width = 125.0f;
  Rectangle pos = {
      (screenWidth / 2.0f) - (width / 2.0f),
      20.0f,
      width,
      30.0f,
  };

  if (stateDropdownMenu["show"]) {
    GuiLock();
  }
  if (GuiDropdownBox(pos, cities, &stateDropdownMenu["item"],
                     (bool)stateDropdownMenu["show"])) {
    stateDropdownMenu["show"] = !stateDropdownMenu["show"];
  }
  GuiUnlock();
}

int UI::GetActiveItemDropdownMenu() { return stateDropdownMenu["item"]; }