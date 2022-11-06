#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
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
    void setLocation(float, float);
    int getSize() const;
    void incrementSize();
    int getGridWidth() const;
    int getGridHeight() const;
    float getHeadXFloat() const;
    float getHeadYFloat() const;
    std::vector<SDL_Point> body;

private:
    SDL_Point head_;
    int grid_width_;
    int grid_height_;
    int size_{1};
    float head_x_f_;
    float head_y_f_;
};

#endif
