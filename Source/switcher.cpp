/*!
  @In My Dream I Was Falling
  @author Matthew Carlin
  Copyright 2018
*/

#include "switcher.h"

using namespace std;
using namespace Honey;

Switcher::Switcher() {
  makeOrSet("game");
}

void Switcher::logic() {
}

void Switcher::render() {
}

void Switcher::makeOrSet(string screen_name) {
  if (!screenmanager.checkScreen(screen_name)) {
    if (screen_name == "game") {
      unique_ptr<Screen> game(new Game());
      screenmanager.addScreen("game", game);
      screenmanager.setCurrentScreen("game");
    }

    screenmanager.initialize();
  }

  screenmanager.setCurrentScreen(screen_name);
}

Switcher::~Switcher() {
}