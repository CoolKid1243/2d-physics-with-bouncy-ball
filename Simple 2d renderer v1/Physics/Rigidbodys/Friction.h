#pragma once

class FrictionHandler {
public:
    FrictionHandler(float frictionCoefficient);
    void applyFriction(float& speedX, float& speedY, float deltaTime) const;

private:
    float frictionCoefficient;
};
