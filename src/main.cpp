// clang-format off
#include <raylib.h>
#include "settings.h"
#include "wallpaper.h"
#define RAYGUI_IMPLEMENTATION
#include "ui.h"
#include "httplib.h"
#include <iostream>
#include "client.h"
// clang-format on

int main(void) {
  InitWindow(W_WIDTH, W_HEIGHT, TITLE);
  SetTargetFPS(FPS);
  GuiLoadStyle("theme/style_cyber.rgs");
  GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, palette.light);
  Wallpaper wallpaper("assets/forest_default.jpg");
  wallpaper.Set(W_WIDTH, W_HEIGHT);
  WeatherApp::UI ui(CITIES, NUMBER_CITIES);
  int activeItem = ui.GetActiveItemDropdownMenu();
  WeatherApp::Client client(HOST);
  client.Request(REQUEST_PATH, CITIES, activeItem);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(GetColor(palette.dark));
    wallpaper.Draw();
    //--- GIU
    ui.DropdownMenu(W_WIDTH);
    if (activeItem != ui.GetActiveItemDropdownMenu()) {
      activeItem = ui.GetActiveItemDropdownMenu();
      client.Request(REQUEST_PATH, CITIES, activeItem);
    }
    //---
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
