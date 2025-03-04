#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width / 2.0, grid_height / 2.0, grid_width, grid_height),
      // initial x/y is irrelevant because the food is immediately moved anyway
      food_(0.0, 0.0, grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)),
      random_s(1, 2) {
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food_);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y, multiper;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // TODO: make this random between 1 and 2, usually 1
    // also, come back and render on-screen when there's a multiplier
    multiper = random_s(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    SDL_Point new_point = SDL_Point{static_cast<int>(x), static_cast<int>(y)};
    if (!snake.doesOverlap(new_point)) {
      food_.setLocation(x, y);
      food_.setMultiplier(multiper);
      return;
    }
  }
}

void Game::Update() {
  if (!snake.alive) return;

  snake.Update();

  // Check if the snake overlaps with the food
  if (food_.xLocation() == snake.xLocation() && food_.yLocation() == snake.yLocation()) {
    score += food_.getMultiplier();
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.getSize(); }