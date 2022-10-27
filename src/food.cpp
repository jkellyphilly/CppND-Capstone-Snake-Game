#include "food.h"

int Food::getMultiplier() const { return multiplier_; }

void Food::setMultiplier(int size) {
    multiplier_ = size;
}