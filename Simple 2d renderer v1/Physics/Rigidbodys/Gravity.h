#pragma once

class Gravity {
public:
    Gravity(float gravity, float maxGravity);

    void applyGravity(float& posY, float& speedY, float deltaTime);
    float getMaxGravity() const;

private:
    float gravity;
    float maxGravity;
};

