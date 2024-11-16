#include "Backround.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Backround::Backround() :
    backround(sf::Vector2f(10000000.f, 10000000.f)),
    posX(-5000000.f),
    posY(-8000000.f) {

    // Set initial position of the rectangle
    backround.setPosition(posX, posY);

    // Construct the full absolute file path
    std::string imagePath = "D:/All Game Stuff And Softwhere/VS Games/Simple 2d renderer/Simple 2d renderer v1/Renderer/Textures/Grid.png";

    if (!texture.loadFromFile(imagePath)) {
        std::cerr << "Error loading png" << std::endl;
    }
    else {
        texture.setRepeated(true);

        backround.setTexture(&texture);

        backround.setTextureRect(sf::IntRect(0, 0, 10000000,10000000)); // Texture scale
    }
}

void Backround::update(float deltaTime) {
    // Wrap around the screen edges
    if (posX > 800.f) posX = -50.f;
    if (posY > 600.f) posY = -50.f;

    // Update position of the rectangle
    backround.setPosition(posX, posY);
}

void Backround::draw(sf::RenderWindow& window) {
    // Draw the rectangle on the window
    window.draw(backround);
}
