#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include "settings.h"
#include "wallpaper.h"
#include <raygui.h>

int main(void) {
  InitWindow(W_WIDTH, W_HEIGHT, "Weather");
  SetTargetFPS(FPS);
  GuiLoadStyle("theme/style_cyber.rgs");
  Wallpaper wallpaper("assets/forest_default.jpg");
  wallpaper.Set(W_WIDTH, W_HEIGHT);

  bool showMessageBox = false;

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(GetColor(palette.dark));
    wallpaper.Draw();
    DrawText("App weather", 170, 30, 22, GetColor(palette.accent));
    //--- GIU
    if (GuiButton((Rectangle){24, 24, 120, 30}, "#191#Show Message"))
      showMessageBox = true;

    if (showMessageBox) {
      int result =
          GuiMessageBox((Rectangle){85, 70, 250, 100}, "#191#Message Box",
                        "Hi! This is a message!", "Nice;Cool");

      if (result >= 0)
        showMessageBox = false;
    }
    //---
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
