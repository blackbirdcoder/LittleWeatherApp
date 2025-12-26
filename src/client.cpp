#include "client.h"
#include "settings.h"
#include <iostream>
#include <sstream>
#include <string>

namespace Weather {

Client::Client(const char *host) { this->host = host; };

int Client::Request(const std::map<Token, std::string> path,
                    const City cities[], int menuCurrentItem) {
  httplib::Client cli(host);

  std::stringstream strBuild;
  strBuild << path.at(PART_ONE) << cities[menuCurrentItem].latitude
           << path.at(PART_TWO) << cities[menuCurrentItem].longitude
           << path.at(PART_THREE);
  query = strBuild.str();

  if (auto res = cli.Get(query)) {
    std::cout << "[*]RESULT:" << std::endl;
    std::cout << res->status << std::endl;
    std::cout << res->body << std::endl;
    return res->status;
  }
  return -1;
};

} // namespace WeatherApp
