#include "Circle.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Friction.h"

Circle::Circle() :
    circle(55.f),
    posX(400.f),
    posY(300.f),
    gravityHandler(650.f, 2850.f), // gravity
    velocity(0.f, 0.f),
    bounceHandler(0.8f),
    frictionHandler(0.5f) {

    std::string imagePath = "D:/All Game Stuff And Softwhere/VS Games/Simple 2d renderer/Simple 2d renderer v1/Renderer/Textures/AwesomeFace.png";

    if (!texture.loadFromFile(imagePath)) {
        std::cerr << "Error loading png" << std::endl;
    }
    else {
        circle.setTexture(&texture);
    }

    circle.setPosition(posX - circle.getRadius(), posY - circle.getRadius());
}

void Circle::update(float deltaTime) {
    float speedX, speedY;
    velocity.getSpeed(speedX, speedY);

    // Apply gravity only if the circle is not on the ground
    if (posY + circle.getRadius() < 600.f) {
        gravityHandler.applyGravity(posY, speedY, deltaTime);
        frictionHandler.applyFriction(speedX, speedY, deltaTime);
        // Ensure speedY does not exceed maxGravity
        if (speedY >= gravityHandler.getMaxGravity()) {
            speedY = gravityHandler.getMaxGravity();
        }
    }
    else {
        // Reset vertical speed if on the ground
        speedY = 0.f;
    }

    velocity.setSpeed(speedX, speedY);

    // Update position of the circle using velocity
    velocity.updatePosition(posX, posY, deltaTime);

    circle.setPosition(posX - circle.getRadius(), posY - circle.getRadius());

    // Log the current velocity
    logVelocity();
}

void Circle::draw(sf::RenderWindow& window) {
    window.draw(circle);
}

void Circle::setVelocity(float newSpeedX, float newSpeedY) {
    velocity.setSpeed(newSpeedX, newSpeedY);
}

void Circle::getVelocity(float& outSpeedX, float& outSpeedY) const {
    velocity.getSpeed(outSpeedX, outSpeedY);
}

void Circle::logVelocity() const {
    //std::cout << "Circle Velocity - " ;
    velocity.logSpeed();
}

sf::Vector2f Circle::getPosition() const {
    return sf::Vector2f(posX, posY);
}

void Circle::setPosition(float x, float y) {
    posX = x;
    posY = y;
    circle.setPosition(posX - circle.getRadius(), posY - circle.getRadius());
}
