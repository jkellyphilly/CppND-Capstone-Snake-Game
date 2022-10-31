#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "SDL.h"

class GameObject
{
public:
    GameObject(int x, int y, int grid_w, int grid_h) : 
        head_(SDL_Point{x, y}),
        grid_width_(grid_w),
        grid_height_(grid_h)
        {};
    SDL_Point getLocation() const;
    int xLocation() const;
    int yLocation() const;
    void setLocation(int, int);

private:
    SDL_Point head_;
    int grid_width_;
    int grid_height_;
    // size_{1};
};

#endif
