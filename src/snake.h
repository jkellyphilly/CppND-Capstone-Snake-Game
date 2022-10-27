#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"
#include "gameobject.h"

class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  // TODO: change constructor. Just pass in x/y that's already halved from main
  // this inherits the GameObject's class
  // TODO: change GameObject to also have private attributes for grid width and height?
  Snake(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2) {}

  void Update();

  void GrowBody();

  // TODO: this needs to become updated to a template function CollisionCheck 
  bool SnakeCell(int x, int y);

  Direction direction = Direction::kUp;

  float speed{0.1f};
  int size{1}; // this gets handled by GameObject
  bool alive{true};
  float head_x; // also gets handled by GameObject
  float head_y; // also gets handled by GameObject
  std::vector<SDL_Point> body; // only snake and obstacle will need this. so maybe on them to define.

 private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
  int grid_width; // becomes a property of GameObject
  int grid_height; // becomes a property of GameObject
};

#endif