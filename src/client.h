#pragma once
#include "httplib.h"
#include "settings.h"
#include <map>
#include <string>

namespace Weather {
class Client {
public:
  Client(const char *host);
  std::map<std::string, std::string> Request(const std::map<Token, std::string> &path,
    const City cities[], int menuCurrentItem);

private:
  const char *host;
  std::string query;
};
} // namespace WeatherApp