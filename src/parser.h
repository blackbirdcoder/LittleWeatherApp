#pragma once
#include "json.hpp"
#include "settings.h"
#include <ctime>
#include <map>
#include <string>
#include <list>

namespace Weather {
class Parser {
public:
  Parser();
  void Parse(std::string &rowData, const City cities[], int itemCityActive);
  const std::map<std::string, std::string> &GetDataHero() const;
  const std::time_t &GetTimeCity() const;

private:
  std::time_t timeNow;
  std::time_t timeCity;
  std::map<std::string, std::string> dataHero;
  std::list<std::map<std::string, std::string>> dataHourly;
};
} // namespace Weather
