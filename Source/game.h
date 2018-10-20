/*!
  @In My Dream I Was Falling
  @author Matthew Carlin
  Copyright 2018
*/

#pragma once

#include <string>
#include <array>
#include <vector>

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
  float y_velocity;
  int x_position;
  int y_position;

  int screen_width;
  int screen_height;

  std::string screen_color;

  int camera_y;

  float move_acceleration;
  float move_decay;
  float gravity;
  float terminal_velocity;

  int font_base_x;
  int font_base_y;

  Textbox* credit_text;

  const int screens = 12;

  const vector<vector<string>> credits = {
    {"In My Dream I Was Falling",},
    {"Original Dream", "Ben Bascom"},
    {"Programming", "and Design", "Matthew Carlin"},
    {"Art and Design", "Jin Cui"},
    {"Sound", "Trace Ronning"},
  };

  const vector<string> wall = {
    "nothing",
    "basic_wall_vertical",
    "basic_wall_horizontal",
    "basic_wall_corner_bottom_left",
    "basic_wall_corner_bottom_right",
    "basic_wall_corner_top_left",
    "basic_wall_corner_top_right",
  };

  const vector<vector<int>> layout = {
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},

    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},

    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},

    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},

    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},

    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 4, 2, 3, 0, 1},
    {1, 0, 0, 6, 2, 5, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},

    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},

    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 4, 3, 0, 0, 0, 0, 1},
    {1, 6, 5, 0, 0, 0, 0, 1},

    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},

    {1, 0, 0, 0, 4, 3, 0, 1},
    {1, 0, 0, 0, 1, 1, 0, 1},
    {1, 0, 4, 2, 5, 1, 0, 1},
    {1, 0, 1, 0, 0, 1, 0, 1},
    {1, 0, 6, 2, 2, 5, 0, 1},

    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},

    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
  };
};