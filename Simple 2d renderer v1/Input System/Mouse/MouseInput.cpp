#include "MouseInput.h"
#include <iostream>

MouseInput::MouseInput() : mousePosition(0, 0) {}

void MouseInput::update(sf::RenderWindow& window) {
    mousePosition = sf::Mouse::getPosition(window);
    //std::cout << "Mouse Position: " << mousePosition.x << ", " << mousePosition.y << std::endl;
}

sf::Vector2i MouseInput::getMousePosition() const {
    return mousePosition;
}
