#include "Friction.h"

FrictionHandler::FrictionHandler(float frictionCoefficient) : frictionCoefficient(frictionCoefficient) {}

void FrictionHandler::applyFriction(float& speedX, float& speedY, float deltaTime) const {
    speedX -= speedX * frictionCoefficient * deltaTime;
    speedY -= speedY * frictionCoefficient * deltaTime;
}
