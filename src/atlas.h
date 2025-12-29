//////////////////////////////////////////////////////////////////////////////////
//                                                                              //
// rTexpacker v5.5 Atlas Descriptor Code exporter v5.0 //
//                                                                              //
// more info and bugs-report:  github.com/raylibtech/rtools // feedback and
// support:       ray[at]raylibtech.com                            //
//                                                                              //
// Copyright (c) 2019-2025 raylib technologies (@raylibtech) //
//                                                                              //
//////////////////////////////////////////////////////////////////////////////////

#define ATLAS_ATLAS_IMAGE_PATH "atlas.png"
#define ATLAS_ATLAS_SPRITE_COUNT 20

// Atlas sprite properties
typedef struct rtpAtlasSprite {
  const char *nameId;
  const char *tag;
  int originX, originY;
  int positionX, positionY;
  int sourceWidth, sourceHeight;
  int padding;
  bool trimmed;
  int trimRecX, trimRecY, trimRecWidth, trimRecHeight;
  int colliderType;
  int colliderPosX, colliderPosY, colliderSizeX, colliderSizeY;
} rtpAtlasSprite;

// Atlas sprites array
static rtpAtlasSprite rtpDescAtlas[20] = {
    {"day_clear", "", 0, 0, 401, 1, 97, 97, 1, false, 0, 0, 97, 97, 0, 0, 0, 0,
     0},
    {"day_cloudy", "", 0, 0, 601, 106, 97, 62, 1, false, 0, 0, 97, 62, 0, 0, 0,
     0, 0},
    {"day_heavy_rain", "", 0, 0, 101, 106, 97, 84, 1, false, 0, 0, 97, 84, 0, 0,
     0, 0, 0},
    {"day_heavy_snow", "", 0, 0, 766, 1, 97, 90, 1, false, 0, 0, 97, 90, 0, 0,
     0, 0, 0},
    {"day_little_rain", "", 0, 0, 301, 1, 97, 98, 1, false, 0, 0, 97, 98, 0, 0,
     0, 0, 0},
    {"day_overcast", "", 0, 0, 901, 106, 97, 52, 1, false, 0, 0, 97, 52, 0, 0,
     0, 0, 0},
    {"day_partly_cloudy", "", 0, 0, 501, 106, 97, 65, 1, false, 0, 0, 97, 65, 0,
     0, 0, 0, 0},
    {"day_snow", "", 0, 0, 866, 1, 97, 89, 1, false, 0, 0, 97, 89, 0, 0, 0, 0,
     0},
    {"day_storm", "", 0, 0, 1, 1, 97, 102, 1, false, 0, 0, 97, 102, 0, 0, 0, 0,
     0},
    {"night_clear", "", 0, 0, 501, 1, 97, 97, 1, false, 0, 0, 97, 97, 0, 0, 0,
     0, 0},
    {"night_cloudy", "", 0, 0, 701, 106, 97, 62, 1, false, 0, 0, 97, 62, 0, 0,
     0, 0, 0},
    {"night_heavy_rain", "", 0, 0, 201, 106, 97, 84, 1, false, 0, 0, 97, 84, 0,
     0, 0, 0, 0},
    {"night_heavy_snow", "", 0, 0, 666, 1, 97, 90, 1, false, 0, 0, 97, 90, 0, 0,
     0, 0, 0},
    {"night_little_rain", "", 0, 0, 201, 1, 97, 98, 1, false, 0, 0, 97, 98, 0,
     0, 0, 0, 0},
    {"night_overcast", "", 0, 0, 801, 106, 97, 52, 1, false, 0, 0, 97, 52, 0, 0,
     0, 0, 0},
    {"night_partly_cloudy", "", 0, 0, 301, 106, 97, 84, 1, false, 0, 0, 97, 84,
     0, 0, 0, 0, 0},
    {"night_snow", "", 0, 0, 1, 106, 97, 89, 1, false, 0, 0, 97, 89, 0, 0, 0, 0,
     0},
    {"night_storm", "", 0, 0, 101, 1, 97, 102, 1, false, 0, 0, 97, 102, 0, 0, 0,
     0, 0},
    {"water", "", 0, 0, 601, 1, 62, 97, 1, false, 0, 0, 62, 97, 0, 0, 0, 0, 0},
    {"windy", "", 0, 0, 401, 106, 97, 79, 1, false, 0, 0, 97, 79, 0, 0, 0, 0,
     0},
};
