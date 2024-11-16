#include "Grabbing.h"
#include <iostream>

Grabbing::Grabbing() : isGrabbing(false), previousMousePos(0.f, 0.f) {}

void Grabbing::update(sf::RenderWindow& window, Circle& circle, float deltaTime) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mouseWorldPos = window.mapPixelToCoords(mousePos);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (!isGrabbing) {
            if (circle.circle.getGlobalBounds().contains(mouseWorldPos)) {
                isGrabbing = true;
                offset = circle.getPosition() - mouseWorldPos;
                previousMousePos = mouseWorldPos;
            }
        }
        else {
            sf::Vector2f newPos = mouseWorldPos + offset;
            sf::Vector2f mouseVelocity = (mouseWorldPos - previousMousePos) / deltaTime;

            circle.setPosition(newPos.x, newPos.y);
            circle.setVelocity(mouseVelocity.x, mouseVelocity.y);
            previousMousePos = mouseWorldPos;
        }
    }
    else {
        if (isGrabbing) {
            // When releasing the circle, keep the velocity based on the last known mouse movement
            sf::Vector2f mouseVelocity = (mouseWorldPos - previousMousePos) / deltaTime;
            circle.setVelocity(mouseVelocity.x, mouseVelocity.y);
        }
        isGrabbing = false;
    }
}
