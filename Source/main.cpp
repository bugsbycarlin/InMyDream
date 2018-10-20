/*!
  @In My Dream I Was Falling
  @author Matthew Carlin
  Copyright 2018
*/

#include <string>
#include <array>

#include "switcher.h"
#include "honey.h"

using namespace std;
using namespace Honey;

int main(int argc, char* args[]) {
  StartHoney("In My Dream I Was Falling");

  Switcher* switcher = new Switcher(); 

  while (!screenmanager.getQuit()) {
    input.processInput();

    screenmanager.loop();

    switcher->logic();
    switcher->render();

    // Put everything we've drawn on screen
    graphics.updateDisplay();
  }

  delete switcher;
}

