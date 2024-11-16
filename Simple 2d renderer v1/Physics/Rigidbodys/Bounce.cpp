#include "Bounce.h"

Bounce::Bounce(float bounceFactor)
    : bounceFactor(bounceFactor) {}

void Bounce::applyBounce(float& speedX, float& speedY, bool horizontal, bool vertical) {
    if (horizontal) {
        speedX = -speedX * bounceFactor;
    }
    if (vertical) {
        speedY = -speedY * bounceFactor;
    }
}
