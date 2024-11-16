#pragma once

class Velocity {
public:
    Velocity();
    Velocity(float speedX, float speedY);
    void setSpeed(float newSpeedX, float newSpeedY);
    void getSpeed(float& outSpeedX, float& outSpeedY) const;
    void updatePosition(float& posX, float& posY, float deltaTime) const;
    void logSpeed() const;

private:
    float speedX;
    float speedY;
};
