#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"
#include "gameobject.h"

class Snake : public GameObject {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  // TODO: change constructor. Just pass in x/y that's already halved from main
  // this inherits the GameObject's class
  // TODO: change GameObject to also have private attributes for grid width and height?
  Snake(int x, int y, int grid_w, int grid_h)
      : GameObject(x, y, grid_w, grid_h) {}

  void Update();

  void GrowBody();

  // TODO: this needs to become updated to a template function CollisionCheck 
  bool SnakeCell(int x, int y);

  Direction direction = Direction::kUp;

  float speed{0.1f};
  bool alive{true};
  std::vector<SDL_Point> body; // only snake and obstacle will need this. so maybe on them to define.

 private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
};

#endif