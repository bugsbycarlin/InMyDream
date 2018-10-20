/*!
  @In My Dream I Was Falling
  @author Matthew Carlin
  Copyright 2018
*/

#include "game.h"

using namespace std;
using namespace Honey;

Game::Game() {
}

void Game::loop() {
  logic();
  render();
}

void Game::initialize() {
  screen_width = hot_config.getInt("layout", "screen_width");
  screen_height = hot_config.getInt("layout", "screen_height");

  graphics.addImage("character_right", "Art/character_right.png");
  graphics.addImage("character_left", "Art/character_left.png");

  // Set a bunch of variables from configuration
  screen_color = hot_config.getString("layout", "screen_color");
  x_position = hot_config.getInt("game", "starting_x");
  y_position = hot_config.getInt("game", "starting_y");
  move_speed = hot_config.getFloat("game", "move_speed");
  move_decay = hot_config.getFloat("game", "move_decay");

  input.addActionKey("left", "left");
  input.addActionKey("right", "right");
}

void Game::logic() {
  if (input.actionDown("left")) {
    x_velocity -= move_speed;
  }

  if (input.actionDown("right")) {
    x_velocity += move_speed;
  }

  x_position += x_velocity;

  x_velocity *= move_decay;

  // To do: quit when the quit button is pressed. Sheesh.
  if (input.threeQuickKey("escape")) {
    screenmanager.setQuit();
  }
}

void Game::render() {
  // Clear the screen to a soft white color
  graphics.clearScreen(screen_color);

  // Switch to 2D drawing mode
  graphics.draw2D();

  if (x_velocity >= 0) {
    graphics.drawImage("character_right", x_position, y_position);
  } else {
    graphics.drawImage("character_left", x_position, y_position);
  }
}

Game::~Game() {

}