#pragma once
#include "json.hpp"
#include "settings.h"
#include <ctime>
#include <map>
#include <string>

namespace Weather {
class Parser {
public:
  Parser();
  void Parse(std::string &rowData, const City cities[], int itemCityActive);
  const std::map<std::string, std::string> &GetDataHero() const;

private:
  std::time_t timeNow;
  std::map<std::string, std::string> dataHero;
};
} // namespace Weather
