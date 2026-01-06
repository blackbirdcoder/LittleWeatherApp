#include "client.h"
#include "settings.h"
#include <iostream>
#include <sstream>
#include <string>

namespace Weather {

Client::Client(const char *host) { this->host = host; };

std::map<std::string, std::string>
Client::Request(const std::map<Token, std::string> &path, const City cities[],
                int menuCurrentItem) {
  std::map<std::string, std::string> answer = {
      {"status", ""},
      {"body", ""},
  };
  httplib::Client cli(host);

  std::stringstream strBuild;
  strBuild << path.at(PART_ONE) << cities[menuCurrentItem].latitude
           << path.at(PART_TWO) << cities[menuCurrentItem].longitude
           << path.at(PART_THREE);
  query = strBuild.str();

  if (auto res = cli.Get(query)) {
    answer.at("status") = std::to_string(res->status);
    answer.at("body") = res->body;
  }

  return answer;
};

} // namespace Weather
