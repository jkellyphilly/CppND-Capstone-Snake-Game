#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "SDL.h"

class GameObject
{
public:
    GameObject(int x, int y) : head_(SDL_Point{x, y}) {};
    SDL_Point getLocation() const;
    int xLocation() const;
    int yLocation() const;
    void setLocation(int, int);

private:
    SDL_Point head_; 
    // size_{1};
};

#endif
