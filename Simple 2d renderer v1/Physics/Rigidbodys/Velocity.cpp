#include "Velocity.h"
#include <iostream>
#include <cmath>

Velocity::Velocity()
    : speedX(0.f), speedY(0.f) {}

Velocity::Velocity(float speedX, float speedY)
    : speedX(speedX), speedY(speedY) {}

void Velocity::setSpeed(float newSpeedX, float newSpeedY) {
    speedX = newSpeedX;
    speedY = newSpeedY;
}

void Velocity::getSpeed(float& outSpeedX, float& outSpeedY) const {
    outSpeedX = speedX;
    outSpeedY = speedY;
}

void Velocity::updatePosition(float& posX, float& posY, float deltaTime) const {
    posX += speedX * deltaTime;
    posY += speedY * deltaTime;
}

void Velocity::logSpeed() const {
    std::cout << "SpeedX: " << speedX << ", SpeedY: " << speedY << std::endl;
}
