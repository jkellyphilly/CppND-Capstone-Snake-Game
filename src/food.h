#ifndef FOOD_H
#define FOOD_H

#include "gameobject.h"

class Food : public GameObject
{
public:
    Food(int x, int y) : GameObject(x, y) {};
    int getMultiplier() const;
    void setMultiplier(int);

private:
    int multiplier_{1};
};

#endif