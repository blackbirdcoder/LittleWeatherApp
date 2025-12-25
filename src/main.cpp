// clang-format off
#include <raylib.h>
#include "settings.h"
#include "wallpaper.h"
#define RAYGUI_IMPLEMENTATION
#include "ui.h"
#include <iostream>
// clang-format on

int main(void) {
  InitWindow(W_WIDTH, W_HEIGHT, TITLE);
  SetTargetFPS(FPS);
  GuiLoadStyle("theme/style_cyber.rgs");
  GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, palette.light);
  Wallpaper wallpaper("assets/forest_default.jpg");
  wallpaper.Set(W_WIDTH, W_HEIGHT);
  UI ui(CITIES);

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(GetColor(palette.dark));
    wallpaper.Draw();
    //--- GIU
    ui.DropdownMenu(W_WIDTH);
    //---
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
