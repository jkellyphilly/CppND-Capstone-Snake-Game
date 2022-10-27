#include "gameobject.h"
#include "SDL.h"

void GameObject::setLocation(int x, int y) {
    // TODO: do error handling here (i.e. don't go off the board)
    head_.x = x;
    head_.y = y;
}

SDL_Point GameObject::getLocation() const { return head_; }

int GameObject::xLocation() const { return head_.x; }

int GameObject::yLocation() const { return head_.y; }