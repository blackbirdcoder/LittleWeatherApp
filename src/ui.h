#pragma once
// clang-format off
#include <raygui.h>
#include <map>
// clang-format on

class UI {
public:
  UI(const char *cities);
  void DropdownMenu(const int screenWidthSize);
  int GetActiveItemDropdownMenu();

private:
  std::map<const char *, int> stateDropdownMenu;
  const char *cities;
};