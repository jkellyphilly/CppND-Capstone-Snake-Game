#ifndef FOOD_H
#define FOOD_H

#include "gameobject.h"

class Food : public GameObject
{
public:
    Food(int x, int y) : GameObject(x, y) {};
    int getSize() const;
    void setSize(int);

private:
    int size_{1};
};

#endif