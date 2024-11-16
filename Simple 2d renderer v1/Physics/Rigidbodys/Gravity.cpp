#include "Gravity.h"

Gravity::Gravity(float gravity, float maxGravity)
    : gravity(gravity), maxGravity(maxGravity) {}

void Gravity::applyGravity(float& posY, float& speedY, float deltaTime) {
    speedY += gravity * deltaTime;
    if (speedY > maxGravity) {
        speedY = maxGravity;
    }
    posY += speedY * deltaTime;
}

float Gravity::getMaxGravity() const {
    return maxGravity;
}
