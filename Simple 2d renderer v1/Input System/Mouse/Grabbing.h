#pragma once
#include <SFML/Graphics.hpp>
#include "Circle.h"

class Grabbing {
public:
    Grabbing();
    void update(sf::RenderWindow& window, Circle& circle, float deltaTime);

private:
    bool isGrabbing;
    sf::Vector2f offset;
    sf::Vector2f previousMousePos;
};
