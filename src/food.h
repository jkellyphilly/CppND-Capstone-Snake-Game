#ifndef FOOD_H
#define FOOD_H

#include "gameobject.h"

class Food : public GameObject
{
public:
    Food(int x, int y, int grid_w, int grid_h) : GameObject(x, y, grid_w, grid_h) {};
    int getMultiplier() const;
    void setMultiplier(int);

private:
    int multiplier_{1};
};

#endif