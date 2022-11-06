#include "snake.h"
#include <cmath>
#include <iostream>

void Snake::Update() {
  // capture previous cell as an SDL point, as well as current cell, 
  // using the getLocation mechanism for gameObjects
  SDL_Point prev_cell = this->getLocation(); // We first capture the head's cell before updating.
  UpdateHead();
  SDL_Point current_cell = this->getLocation();  // Capture the head's cell after updating.

  // Update all of the body vector items if the snake head has moved to a new
  // cell.
  if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) {
    UpdateBody(current_cell, prev_cell);
  }
}

void Snake::UpdateHead() {
  // Cast head_x and head_y to floats
  float head_x = this->getHeadXFloat();
  float head_y = this->getHeadYFloat();

  switch (direction) {
    case Direction::kUp:
      head_y -= speed;
      break;

    case Direction::kDown:
      head_y += speed;
      break;

    case Direction::kLeft:
      head_x -= speed;
      break;

    case Direction::kRight:
      head_x += speed;
      break;
  }

  // Wrap the Snake around to the beginning if going off of the screen.
  head_x = fmod(head_x + this->getGridWidth(), this->getGridWidth());
  head_y = fmod(head_y + this->getGridHeight(), this->getGridHeight());

  // Convert back to int and set the x/y location of the head
  // TODO: rounding down here hurts us. 
  this->setLocation(head_x, head_y);
}

void Snake::UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell) {
  // Add previous head location to vector
  body.push_back(prev_head_cell);

  if (!growing) {
    // Remove the tail from the vector.
    body.erase(body.begin());
  } else {
    growing = false;
    this->incrementSize();
  }

  // Check if the snake has died.
  // Implement collision checker here
  for (auto const &item : body) {
    if (current_head_cell.x == item.x && current_head_cell.y == item.y) {
      alive = false;
    }
  }
}

void Snake::GrowBody() { growing = true; }

// Inefficient method to check if cell is occupied by snake.
bool Snake::SnakeCell(int x, int y) {
  if (x == this->xLocation() && y == this->yLocation()) {
    return true;
  }
  for (auto const &item : body) {
    if (x == item.x && y == item.y) {
      return true;
    }
  }
  return false;
}