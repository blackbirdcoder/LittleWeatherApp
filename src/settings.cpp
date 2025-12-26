#include "settings.h"

namespace Weather {

namespace Window {
const int WIDTH = 800;
const int HEIGHT = 600;
const char *TITLE = "Weather";
const int FPS = 60;
} // namespace Window

const unsigned short NUMBER_CITIES = 2;

const Palette palette = {
    0x00303BFF,
    0xFF7777FF,
    0xF1F2DAFF,
    0xFFCE96FF,
};

const City kharkiv = {
    0,
    "Kharkiv",
    49.9808,
    36.2527,
};

const City kyiv = {
    1,
    "Kyiv",
    50.4547,
    30.5238,
};

const City CITIES[NUMBER_CITIES] = {kharkiv, kyiv};

const char *HOST = "api.open-meteo.com";
const std::map<Token, std::string> REQUEST_PATH = {
    {PART_ONE, "/v1/forecast?latitude="},
    {PART_TWO, "&longitude="},
    {PART_THREE, "&hourly=temperature_2m,rain,cloud_cover,snowfall,"
                 "precipitation,wind_speed_10m,wind_direction_10m,"
                 "relativehumidity_2m&forecast_days=1&format=json"}};
} // namespace Weather