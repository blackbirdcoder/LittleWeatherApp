// clang-format off
#include <raylib.h>
#include "settings.h"
#include "wallpaper.h"
#define RAYGUI_IMPLEMENTATION
#include "ui.h"
#include "httplib.h"
#include "client.h"
#include <map>
#include "parser.h"
#include <vector>
//temporarily
#include <iostream>
#include <list>
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
  std::map<std::string, std::string> response =
      client.Request(Weather::REQUEST_PATH, Weather::CITIES, activeItem);
  Weather::Parser parser;
  parser.Parse(response.at("body"), Weather::CITIES,
               ui.GetActiveItemDropdownMenu());

  // std::map<std::string, std::string> dataHeroCard = {
  //     {"pic", "day_overcast"},
  //     {"weather", "Overcast"},
  //     {"city", "Kharkiv City"},
  //     {"temp", "-10"},
  // };

  std::vector<std::map<std::string, std::string>> dataHourlyCard = {
      {{"time", "3PM"}, {"temp", "1"}},  {{"time", "4PM"}, {"temp", "-3"}},
      {{"time", "5PM"}, {"temp", "3"}},  {{"time", "6PM"}, {"temp", "-4"}},
      {{"time", "7PM"}, {"temp", "-2"}},
  };

  std::list<std::map<std::string, std::string>> dataPredictions = {
      {{"pic", "mini_cloud"}, {"title", "Cloud"}, {"result", "100%"}},
      {{"pic", "mini_visibility"}, {"title", "Visibility"}, {"result", "100%"}},
      {{"pic", "mini_water"}, {"title", "Humidity"}, {"result", "1%"}},
      {{"pic", "mini_windy"}, {"title", "Wind speed"}, {"result", "110km/h"}},
  };

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(GetColor(Weather::palette.dark));
    wallpaper.Draw();
    //--- GUI
    ui.DropdownMenu(Weather::Window::WIDTH);
    if (activeItem != ui.GetActiveItemDropdownMenu()) {
      activeItem = ui.GetActiveItemDropdownMenu();
      response =
          client.Request(Weather::REQUEST_PATH, Weather::CITIES, activeItem);
      parser.Parse(response.at("body"), Weather::CITIES,
                   ui.GetActiveItemDropdownMenu());
    }
    ui.ShowDayOfWeek(parser.GetTimeCity());
    ui.WeatherHeroCard(parser.GetDataHero());
    ui.WeatherHourlyCard(parser.GetDataHourly());
    ui.WeatherPredictionsCard(dataPredictions);
    ui.ButtonRefresh(Weather::Window::WIDTH, Weather::Window::HEIGHT);
    if (ui.isRefresh) {
      response = client.Request(Weather::REQUEST_PATH, Weather::CITIES,
                                ui.GetActiveItemDropdownMenu());
      parser.Parse(response.at("body"), Weather::CITIES,
                   ui.GetActiveItemDropdownMenu());
      ui.isRefresh = false;
    }
    //---
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
