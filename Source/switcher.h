/*!
  @In My Dream I Was Falling
  @author Matthew Carlin
  Copyright 2018
*/

#pragma once

#include <string>
#include <array>

#include "honey.h"
#include "game.h"

using namespace Honey;
using namespace std;

class Switcher {
 public:
  Switcher();

  void render();
  void logic();

  void makeOrSet(string screen_name);

  ~Switcher();
};