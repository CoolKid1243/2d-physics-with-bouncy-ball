#pragma once
#include <SFML/Graphics.hpp>
#include "Velocity.h"

class Rectangle {
public:
    Rectangle();

    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

public:
    sf::RectangleShape rectangle;
    float posX;
    float posY;
    sf::Texture texture;
};
