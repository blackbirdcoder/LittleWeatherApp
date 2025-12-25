#pragma once
#include "httplib.h"
#include "settings.h"
#include <map>
#include <string>

namespace WeatherApp {
class Client {
public:
  Client(const char *host);
  int Request( std::map<Token, std::string> path,
    const City cities[], int menuCurrentItem);

private:
  const char *host;
  std::string query;
};
} // namespace WeatherApp