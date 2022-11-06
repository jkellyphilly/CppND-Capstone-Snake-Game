#include "gameobject.h"
#include "SDL.h"

void GameObject::setLocation(float x, float y) {
    head_x_f_ = x;
    head_y_f_ = y;
    head_.x = static_cast<int>(x);
    head_.y = static_cast<int>(y);
}

SDL_Point GameObject::getLocation() const { return head_; }

int GameObject::xLocation() const { return head_.x; }

int GameObject::yLocation() const { return head_.y; }

int GameObject::getGridWidth() const { return grid_width_; }

int GameObject::getGridHeight() const { return grid_height_; }

int GameObject::getSize() const { return size_; }

float GameObject::getHeadXFloat() const { return head_x_f_; }

float GameObject::getHeadYFloat() const { return head_y_f_; }

void GameObject::incrementSize() {
    size_ = size_ + 1;
}

bool GameObject::doesOverlap(SDL_Point pt) {
    for (auto const &item : this->body) {
        if (pt.x == item.x && pt.y == item.y) {
            return true;
        }
    }
    return false;
}