#include "ui.h"
#include "settings.h"

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
  isRefresh = false;

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

void UI::drawCelsius(const PositionCelsius &positionCelsius,
                     const std::string &key) {
  float posX = positionCelsius.offsetXForOneDigit;
  if (key.length() == 2) {
    posX = positionCelsius.offsetXForTwoDigit;
  } else if (key.length() == 3) {
    posX = positionCelsius.offsetXForThreeDigit;
  }

  DrawTexturePro(
      celsius,
      (Rectangle){0.0f, 0.0f, (float)celsius.width, (float)celsius.height},
      (Rectangle){posX, positionCelsius.offsetY, (float)celsius.width,
                  (float)celsius.height},
      (Vector2){0.0f, 0.0f}, 0.0f, WHITE);
}

void UI::WeatherHeroCard(const std::map<std::string, std::string> &data) {
  int idx = 0;
  std::string pic = data.at("pic");
  for (int i = 0; i < ATLAS_ATLAS_SPRITE_COUNT; ++i) {
    if (rtpDescAtlas[i].nameId == pic) {
      idx = i;
      break;
    }
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

  PositionCelsius pc = {50.0f, 73.0f, 95.0f, 180.0f};
  drawCelsius(pc, data.at("temp"));
}

void UI::WeatherHourlyCard(
    const std::vector<std::map<std::string, std::string>> &data) {
  float posX = 30.0f;
  float step = 1.0f;
  float inc = 4.0f;
  PositionCelsius pc = {55.0f, 80.0f, 100.0f, 530.0f};

  for (const auto item : data) {
    DrawTextEx(fonts.at("regular"), item.at("time").c_str(),
               (Vector2){posX * step, 490.0f}, fontSize.s, 2,
               GetColor(palette.light));
    DrawTextEx(fonts.at("big"), item.at("temp").c_str(),
               (Vector2){posX * step, 520.0f}, fontSize.l, 2,
               GetColor(palette.light));
    drawCelsius(pc, item.at("temp"));
    pc.offsetXForThreeDigit += posX * inc;
    pc.offsetXForOneDigit += posX * inc;
    pc.offsetXForTwoDigit += posX * inc;
    step += inc;
  }
}

void UI::WeatherPredictionsCard(
    const std::vector<std::map<std::string, std::string>> &data) {
  float step = 1.0f;
  float inc = 4.0f;
  for (const auto item : data) {
    int idx = 0;
    std::string pic = item.at("pic");
    for (int i = 0; i < ATLAS_ATLAS_SPRITE_COUNT; ++i) {
      if (rtpDescAtlas[i].nameId == pic) {
        idx = i;
        break;
      }
    }
    Rectangle src = {
        (float)rtpDescAtlas[idx].positionX + (float)rtpDescAtlas[idx].padding,
        (float)rtpDescAtlas[idx].positionY + (float)rtpDescAtlas[idx].padding,
        (float)rtpDescAtlas[idx].sourceWidth,
        (float)rtpDescAtlas[idx].sourceHeight};

    Rectangle dst = {Window::WIDTH - 170.0f, 20.0f * step,
                     (float)rtpDescAtlas[idx].sourceWidth,
                     (float)rtpDescAtlas[idx].sourceHeight};

    Vector2 orig = {(float)rtpDescAtlas[idx].originX,
                    (float)rtpDescAtlas[idx].originY};

    DrawTexturePro(atlas, src, dst, orig, 0.0f, WHITE);
    DrawTextEx(fonts.at("regular"), item.at("title").c_str(),
               (Vector2){Window::WIDTH - 130.0f, 20.0f * step}, fontSize.s, 2,
               GetColor(palette.light));
    DrawTextEx(fonts.at("bold"), item.at("result").c_str(),
               (Vector2){Window::WIDTH - 130.0f, 20.0f * step + 25.0f},
               fontSize.m, 2, GetColor(palette.light));
    step += inc;
  }
}

void UI::ShowDayOfWeek(time_t timeCity) {
  char day[10];
  std::strftime(day, sizeof(day), "%A", std::gmtime(&timeCity));
  DrawTextEx(fonts.at("bold"), day, (Vector2){25.0f, 440.0f}, fontSize.m, 2,
             GetColor(palette.light));
}

void UI::ButtonRefresh(const int screenWidthSize, const int screenWHightSize) {
  float width = 125.0f;
  float height = 30.0f;
  Rectangle pos = {
      (float)screenWidthSize - width - 20.0f,
      (float)screenWHightSize - height - 43.0f,
      width,
      height,
  };
  if (GuiButton(pos, "Refresh")) {
    isRefresh = true;
  }
}

UI::~UI() {
  UnloadTexture(atlas);
  UnloadTexture(celsius);
  for (auto item : fonts) {
    UnloadFont(item.second);
  }
}
} // namespace Weather