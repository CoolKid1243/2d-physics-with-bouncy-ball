#ifndef MOUSE_INPUT_H
#define MOUSE_INPUT_H

#include <SFML/Graphics.hpp>

class MouseInput {
public:
    MouseInput();
    void update(sf::RenderWindow& window);
    sf::Vector2i getMousePosition() const;

private:
    sf::Vector2i mousePosition;
};

#endif // MOUSE_INPUT_H
