/*!
  @In My Dream I Was Falling
  @author Matthew Carlin
  Copyright 2018
*/

#pragma once

#include <string>
#include <array>

#include "honey.h"

using namespace Honey;
using namespace std;

class Game : public Screen {
 public:
  Game();

  void loop();

  void initialize();

  void logic();
  void render();

  ~Game();

  float x_velocity;
  int x_position;
  int y_position;

  int screen_width;
  int screen_height;

  std::string screen_color;

  float move_speed;
  float move_decay;
};