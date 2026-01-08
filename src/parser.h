#pragma once
#include "json.hpp"
#include "settings.h"
#include <ctime>
#include <list>
#include <map>
#include <string>
#include <vector>

namespace Weather {
class Parser {
public:
  Parser();
  void Parse(std::string &rowData, const City cities[], int itemCityActive);
  const std::map<std::string, std::string> &GetDataHero() const;
  const std::time_t &GetTimeCity() const;
  const std::vector<std::map<std::string, std::string>> &GetDataHourly() const;

private:
  std::time_t timeNow;
  std::time_t timeCity;
  std::map<std::string, std::string> dataHero;
  std::vector<std::map<std::string, std::string>> dataHourly;
};
} // namespace Weather
