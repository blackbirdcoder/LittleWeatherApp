// clang-format off
#include <raylib.h>
#include "settings.h"
#include "wallpaper.h"
#define RAYGUI_IMPLEMENTATION
#include "ui.h"
#include "httplib.h"
#include "client.h"
//temporarily
#include <iostream>
#include <map>
//---
// clang-format on

int main(void) {
  InitWindow(Weather::Window::WIDTH, Weather::Window::HEIGHT,
             Weather::Window::TITLE);
  SetTargetFPS(Weather::Window::FPS);
  GuiLoadStyle("theme/style_cyber.rgs");
  GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, Weather::palette.light);
  Weather::Wallpaper wallpaper("assets/forest_default.jpg");
  wallpaper.Set(Weather::Window::WIDTH, Weather::Window::HEIGHT);
  Weather::UI ui(Weather::CITIES, Weather::NUMBER_CITIES, "assets/atlas.png",
                 "assets/Roboto_Bold.ttf", "assets/Roboto_Regular.ttf",
                 "assets/Roboto_Big.ttf", "assets/celsius.png");
  int activeItem = ui.GetActiveItemDropdownMenu();
  Weather::Client client(Weather::HOST);
  client.Request(Weather::REQUEST_PATH, Weather::CITIES, activeItem);

  std::map<std::string, std::string> d = {
      {"pic", "day_heavy_snow"},
      {"weather", "Heavy Snow"},
      {"city", "Kharkiv City"},
      {"temp", "-2"},
  };

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(GetColor(Weather::palette.dark));
    wallpaper.Draw();
    //--- GIU
    ui.DropdownMenu(Weather::Window::WIDTH);
    if (activeItem != ui.GetActiveItemDropdownMenu()) {
      activeItem = ui.GetActiveItemDropdownMenu();
      client.Request(Weather::REQUEST_PATH, Weather::CITIES, activeItem);
    }
    ui.WeatherHeroCard(d);
    //---
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
