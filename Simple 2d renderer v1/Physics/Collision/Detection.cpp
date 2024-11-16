#include "Detection.h"
#include <algorithm>
#include <cmath>

bool CheckCollision(Circle& circle, Rectangle& rectangle) {
    // Find the closest point to the circle within the rectangle
    float rectLeft = rectangle.posX;
    float rectRight = rectangle.posX + rectangle.rectangle.getSize().x;
    float rectTop = rectangle.posY;
    float rectBottom = rectangle.posY + rectangle.rectangle.getSize().y;

    // Calculate the closest point on the rectangle to the circle's center
    float closestX = std::max(rectLeft, std::min(circle.posX, rectRight));
    float closestY = std::max(rectTop, std::min(circle.posY, rectBottom));

    // Calculate the distance between the circle's center and this closest point
    float distanceX = circle.posX - closestX;
    float distanceY = circle.posY - closestY;

    // Calculate the square of the distance
    float distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);

    // Check if the distance is less than the circle's radius
    return distanceSquared < (circle.circle.getRadius() * circle.circle.getRadius());

}
