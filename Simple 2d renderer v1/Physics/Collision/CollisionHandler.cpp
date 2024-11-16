#include "CollisionHandler.h"
#include <iostream>
#include <algorithm>
#include <cmath>

Bounce CollisionHandler::bounceHandler(0.8f); // Example bounce factor

bool CollisionHandler::CheckCollision(Circle& circle, Rectangle& rectangle) {
    float rectLeft = rectangle.posX;
    float rectRight = rectangle.posX + rectangle.rectangle.getSize().x;
    float rectTop = rectangle.posY;
    float rectBottom = rectangle.posY + rectangle.rectangle.getSize().y;

    float closestX = std::max(rectLeft, std::min(circle.posX, rectRight));
    float closestY = std::max(rectTop, std::min(circle.posY, rectBottom));

    float distanceX = circle.posX - closestX;
    float distanceY = circle.posY - closestY;

    float distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);
    return distanceSquared < (circle.circle.getRadius() * circle.circle.getRadius());
}

void CollisionHandler::HandleCollision(Circle& circle, Rectangle& rectangle) {
    if (CheckCollision(circle, rectangle)) {
        //std::cout << "Collision" << std::endl;

        float circleRadius = circle.circle.getRadius();

        float overlapLeft = circle.posX + circleRadius - rectangle.posX;
        float overlapRight = rectangle.posX + rectangle.rectangle.getSize().x - (circle.posX - circleRadius);
        float overlapTop = circle.posY + circleRadius - rectangle.posY;
        float overlapBottom = rectangle.posY + rectangle.rectangle.getSize().y - (circle.posY - circleRadius);

        float overlapX = (overlapLeft < overlapRight) ? overlapLeft : overlapRight;
        float overlapY = (overlapTop < overlapBottom) ? overlapTop : overlapBottom;

        bool horizontal = false;
        bool vertical = false;

        if (overlapX < overlapY) {
            if (overlapLeft < overlapRight) {
                circle.posX = rectangle.posX - circleRadius;
            }
            else {
                circle.posX = rectangle.posX + rectangle.rectangle.getSize().x + circleRadius;
            }
            horizontal = true;
        }
        else {
            if (overlapTop < overlapBottom) {
                circle.posY = rectangle.posY - circleRadius;
            }
            else {
                circle.posY = rectangle.posY + rectangle.rectangle.getSize().y + circleRadius;
            }
            vertical = true;
        }

        float speedX, speedY;
        circle.getVelocity(speedX, speedY);
        bounceHandler.applyBounce(speedX, speedY, horizontal, vertical);
        circle.setVelocity(speedX, speedY);
    }
}
