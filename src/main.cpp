#include <raylib.h>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

int main(void) {
  const int screenWidth = 800;
  const int screenHeight = 600;
  InitWindow(screenWidth, screenHeight, "Weather");
  SetTargetFPS(60);
  GuiLoadStyle("theme/style_cyber.rgs");

  bool showMessageBox = false;

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(GetColor(0x00303BFF));
    DrawText("App weather", 170, 30, 22, RED);
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
