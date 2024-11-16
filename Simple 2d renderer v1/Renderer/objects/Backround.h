#pragma once
#include <SFML/Graphics.hpp>
#include "Velocity.h"

class Backround {
public:
    Backround();

    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

public:
    sf::RectangleShape backround;
    float posX;
    float posY;
    sf::Texture texture;
};
