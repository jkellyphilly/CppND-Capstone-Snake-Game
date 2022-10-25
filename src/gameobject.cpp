#include "gameobject.h"
#include "SDL.h"

void GameObject::setLocation(int x, int y) {
    // TODO: do error handling here (i.e. don't go off the board)
    location_.x = x;
    location_.y = y;
}

SDL_Point GameObject::getLocation() const { return location_; }

int GameObject::xLocation() const { return location_.x; }

int GameObject::yLocation() const { return location_.y; }