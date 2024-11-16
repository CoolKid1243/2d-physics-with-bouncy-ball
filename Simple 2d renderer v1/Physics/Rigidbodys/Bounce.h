#pragma once

class Bounce {
public:
    Bounce(float bounceFactor);

    void applyBounce(float& speedX, float& speedY, bool horizontal, bool vertical);

private:
    float bounceFactor;
};
