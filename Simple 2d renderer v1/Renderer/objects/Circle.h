#pragma once
#include <SFML/Graphics.hpp>
#include "Gravity.h"
#include "Velocity.h"
#include "Bounce.h"
#include "Friction.h"

class Circle {
public:
    Circle();
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    void setVelocity(float newSpeedX, float newSpeedY);
    void getVelocity(float& outSpeedX, float& outSpeedY) const;
    void logVelocity() const;
    sf::Vector2f getPosition() const;    
    void setPosition(float x, float y);  

public:
    sf::CircleShape circle;
    float posX;
    float posY;
    sf::Texture texture;

private:
    Gravity gravityHandler;
    Velocity velocity;
    Bounce bounceHandler;
    FrictionHandler frictionHandler;
};
