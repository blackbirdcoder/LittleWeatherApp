#include "parser.h"
#include <cmath>
// temporarily
#include <ctime>
#include <iostream>
#include <string>

namespace Weather {
Parser::Parser() { timeNow = std::time(nullptr); };

void Parser::Parse(std::string &rowData, const City cities[],
                   int itemCityActive) {

  nlohmann::json data = nlohmann::json::parse(rowData);

  int offset = data["utc_offset_seconds"];
  std::tm *gmt = std::gmtime(&timeNow);
  int hourlyIdx = (gmt->tm_hour + offset / 3600) % 24;
  timeCity = timeNow + offset;

  // Data Hero Card
  dataHero["city"] = cities[itemCityActive].name + " City";
  float temp = data["hourly"]["temperature_2m"][hourlyIdx];
  dataHero["temp"] = std::to_string((int)std::round(temp));

  int weatherCode = data["hourly"]["weather_code"][hourlyIdx];
  int isDay = data["hourly"]["is_day"][hourlyIdx];

  if (weatherCode == 0) {
    dataHero["pic"] = isDay ? "day_clear" : "night_clear";
    dataHero["weather"] = "Clear";
  } else if (weatherCode == 1) {
    dataHero["pic"] = isDay ? "day_partly_cloudy" : "night_partly_cloudy";
    dataHero["weather"] = "Partly Cloudy";
  } else if (weatherCode == 2) {
    dataHero["pic"] = isDay ? "day_cloudy" : "night_cloudy";
    dataHero["weather"] = "Cloudy";
  } else if (weatherCode == 3) {
    dataHero["pic"] = isDay ? "day_overcast" : "night_overcast";
    dataHero["weather"] = "Overcast";
  } else if (weatherCode == 45 || weatherCode == 48) {
    dataHero["pic"] = isDay ? "day_overcast" : "night_overcast";
    dataHero["weather"] = "Fog";
  } else if (weatherCode == 51 || weatherCode == 53 || weatherCode == 55 ||
             weatherCode == 56 || weatherCode == 57) {
    dataHero["pic"] = isDay ? "day_little_rain" : "night_little_rain";
    dataHero["weather"] = "Drizzle";
  } else if (weatherCode == 61 || weatherCode == 80) {
    dataHero["pic"] = isDay ? "day_little_rain" : "night_little_rain";
    dataHero["weather"] = "Little Rain";
  } else if (weatherCode == 63 || weatherCode == 81) {
    dataHero["pic"] = isDay ? "day_little_rain" : "night_little_rain";
    dataHero["weather"] = "Rain";
  } else if (weatherCode == 65 || weatherCode == 85) {
    dataHero["pic"] = isDay ? "day_heavy_rain" : "night_heavy_rain";
    dataHero["weather"] = "Heavy Rain";
  } else if (weatherCode == 66 || weatherCode == 67) {
    dataHero["pic"] = isDay ? "day_little_rain" : "night_little_rain";
    dataHero["weather"] = "Freezing Rain";
  } else if (weatherCode == 71) {
    dataHero["pic"] = isDay ? "day_snow" : "night_snow";
    dataHero["weather"] = "Little Snow";
  } else if (weatherCode == 73) {
    dataHero["pic"] = isDay ? "day_snow" : "night_snow";
    dataHero["weather"] = "Snow";
  } else if (weatherCode == 75 || weatherCode == 86) {
    dataHero["pic"] = isDay ? "day_heavy_snow" : "night_heavy_snow";
    dataHero["weather"] = "Heavy Snow";
  } else if (weatherCode == 95 || weatherCode == 96 || weatherCode == 99) {
    dataHero["pic"] = isDay ? "day_storm" : "night_storm";
    dataHero["weather"] = "Storm";
  } else {
    dataHero["pic"] = isDay ? "day_clear" : "night_clear";
    dataHero["weather"] = "To be confirmed";
  }
  //---
  // Data hourly
  // TODO: Continue data hourly implementation
  std::cout << rowData << '\n';

  //---
}

const std::map<std::string, std::string> &Parser::GetDataHero() const {
  return dataHero;
}

const time_t &Parser::GetTimeCity() const {
  return timeCity;
}
} // namespace Weather