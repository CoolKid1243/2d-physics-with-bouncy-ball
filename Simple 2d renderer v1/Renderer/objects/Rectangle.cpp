#include "Rectangle.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Rectangle::Rectangle() :
    rectangle(sf::Vector2f(10000000.f, 10000.f)),
    posX(-5000000.f),
    posY(400.f) {

    // Set initial position of the rectangle
    rectangle.setPosition(posX, posY);

    // Construct the full absolute file path
    std::string imagePath = "D:/All Game Stuff And Softwhere/VS Games/Simple 2d renderer/Simple 2d renderer v1/Renderer/Textures/Grass.png";

    if (!texture.loadFromFile(imagePath)) {
        std::cerr << "Error loading png" << std::endl;
    }
    else {
        texture.setRepeated(true);

        rectangle.setTexture(&texture);

        rectangle.setTextureRect(sf::IntRect(0, 0, 10000000, 10000)); // Texture scale
    }
}

void Rectangle::update(float deltaTime) {
    // Wrap around the screen edges
    if (posX > 800.f) posX = -50.f;
    if (posY > 600.f) posY = -50.f;

    // Update position of the rectangle
    rectangle.setPosition(posX, posY);
}

void Rectangle::draw(sf::RenderWindow& window) {
    // Draw the rectangle on the window
    window.draw(rectangle);
}
