#include "ui.h"
#include "settings.h"
// temporarily
#include <iostream>
//---

namespace Weather {

UI::UI(const City cities[], const unsigned short numberCities,
       const char *pathAtlas, const char *pathFontBold,
       const char *pathFontRegular, const char *pathFontBig,
       const char *pathCelsius) {
  atlas = LoadTexture(pathAtlas);
  celsius = LoadTexture(pathCelsius);
  fontSize = {22, 27, 47};
  fonts["regular"] = LoadFontEx(pathFontRegular, fontSize.s, 0, 0);
  fonts["bold"] = LoadFontEx(pathFontBold, fontSize.m, 0, 0);
  fonts["big"] = LoadFontEx(pathFontBig, fontSize.l, 0, 0);
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

void UI::WeatherHeroCard(const std::map<std::string, std::string> &data) {
  int idx = 0;
  std::string pic = data.at("pic");
  for (int i = 0; i < ATLAS_ATLAS_SPRITE_COUNT; ++i) {
    if (rtpDescAtlas[i].nameId == pic && i > 0) {
      idx = i;
      break;
    }
    continue;
  }
  DrawTexturePro(
      atlas,
      (Rectangle){
          (float)rtpDescAtlas[idx].positionX + (float)rtpDescAtlas[idx].padding,
          (float)rtpDescAtlas[idx].positionY + (float)rtpDescAtlas[idx].padding,
          (float)rtpDescAtlas[idx].sourceWidth,
          (float)rtpDescAtlas[idx].sourceHeight},
      (Rectangle){20.0f, 20.0f, (float)rtpDescAtlas[idx].sourceWidth,
                  (float)rtpDescAtlas[idx].sourceHeight},
      (Vector2){(float)rtpDescAtlas[idx].originX,
                (float)rtpDescAtlas[idx].originY},
      0.0f, WHITE);

  DrawTextEx(fonts.at("bold"), data.at("weather").c_str(),
             (Vector2){25.0f, 115.0f}, (float)fontSize.m, 2,
             GetColor(palette.light));
  DrawTextEx(fonts.at("regular"), data.at("city").c_str(),
             (Vector2){25.0f, 145.0f}, fontSize.s, 2, GetColor(palette.light));
  DrawTextEx(fonts.at("big"), data.at("temp").c_str(), (Vector2){25.0f, 170.0f},
             fontSize.l, 2, GetColor(palette.light));

  float posX = 95.0f;
  if (data.at("temp").length() == 1) {
    posX = 50.0f;
  } else if (data.at("temp").length() == 2) {
    posX = 73.0f;
  }

  DrawTexturePro(
      celsius,
      (Rectangle){0.0f, 0.0f, (float)celsius.width, (float)celsius.height},
      (Rectangle){posX, 180.0f, (float)celsius.width, (float)celsius.height},
      (Vector2){0.0f, 0.0f}, 0.0f, WHITE);
}

UI::~UI() {
  UnloadTexture(atlas);
  UnloadTexture(celsius);
  for (auto item : fonts) {
    UnloadFont(item.second);
  }
}

} // namespace Weather