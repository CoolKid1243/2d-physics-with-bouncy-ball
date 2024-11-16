#pragma once
#include "Circle.h"
#include "Rectangle.h"
#include "Bounce.h"

class CollisionHandler {
public:
    static bool CheckCollision(Circle& circle, Rectangle& rectangle);
    static void HandleCollision(Circle& circle, Rectangle& rectangle);

private:
    static Bounce bounceHandler;
};
