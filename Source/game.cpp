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

  graphics.addImages("Art/", {
    "character_left",
    "character_right",
    "basic_wall_corner_bottom_left",
    "basic_wall_corner_bottom_right",
    "basic_wall_corner_top_left",
    "basic_wall_corner_top_right",
    "basic_wall_horizontal",
    "basic_wall_vertical",
  });

  // Set a bunch of variables from configuration
  screen_color = hot_config.getString("layout", "screen_color");
  camera_y = hot_config.getInt("game", "starting_y");
  x_position = hot_config.getInt("game", "starting_x");
  y_position = hot_config.getInt("game", "starting_y");
  move_acceleration = hot_config.getFloat("game", "move_acceleration");
  move_decay = hot_config.getFloat("game", "move_decay");
  gravity = hot_config.getFloat("game", "gravity");
  terminal_velocity = hot_config.getFloat("game", "terminal_velocity");

  x_velocity = 0;
  y_velocity = 0;

  input.addActionKey("left", "left");
  input.addActionKey("right", "right");

  credit_text = new Textbox(
    hot_config.getString("layout", "credits_font_name"),
    hot_config.getInt("layout", "credits_font_size"),
    "a", origin, "#000000");

  font_base_x = hot_config.getInt("layout", "credits_font_base_x");
  font_base_y = hot_config.getInt("layout", "credits_font_base_y");
}

void Game::logic() {
  if (input.actionDown("left")) {
    x_velocity -= move_acceleration;
  }

  if (input.actionDown("right")) {
    x_velocity += move_acceleration;
  }

  x_position += x_velocity;

  x_velocity *= move_decay;

  y_velocity += gravity;
  if (y_velocity > terminal_velocity) {
    y_velocity = terminal_velocity;
  }
  y_position += y_velocity;

  if (y_position > (screens - 1) * 900) {
    y_position -= (screens - 2) * 900;
  }

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

  int camera_offset = camera_y - y_position;

  // Draw walls
  for (int i = 0; i < layout.size(); i++) {
    for (int j = 0; j < layout[i].size(); j++) {
      if (layout[i][j] > 0) {
        graphics.drawImage(wall[layout[i][j]], 180 * j, 180 * i + camera_offset);
      }
    }
  }

  // Draw credits
  for (int i = 0; i < credits.size(); i++) {
    for (int j = 0; j < credits[i].size(); j++) {
      credit_text->setPosition({
        font_base_x,
        900 * (2 * i + 2) + 120 * j + font_base_y + camera_offset,
      });
      credit_text->setText(credits[i][j]);
      credit_text->draw();
    }
  }

  // Draw character
  graphics.setColor("#FFFFFF", 1.0);
  if (x_velocity >= 0) {
    graphics.drawImage("character_right", x_position, camera_y);
  } else {
    graphics.drawImage("character_left", x_position, camera_y);
  }
}

Game::~Game() {
  delete credit_text;
}