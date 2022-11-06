#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"
#include "gameobject.h"

class Snake : public GameObject {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Snake(int x, int y, int grid_w, int grid_h)
      : GameObject(x, y, grid_w, grid_h) {}

  void Update();

  void GrowBody();

  Direction direction = Direction::kUp;

  float speed{0.1f};
  bool alive{true};

 private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
};

#endif