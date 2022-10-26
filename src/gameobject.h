#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "SDL.h"

class GameObject
{
public:
    GameObject(int x, int y) : location_(SDL_Point{x, y}) {};
    SDL_Point getLocation() const;
    int xLocation() const;
    int yLocation() const;
    void setLocation(int, int);

private:
    // TODO: make a "size" attribute
    SDL_Point location_; // TODO: rename to be "centroid"
};

#endif
