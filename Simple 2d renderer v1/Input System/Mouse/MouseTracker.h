#ifndef MOUSE_TRACKER_H
#define MOUSE_TRACKER_H

#include <SFML/Graphics.hpp>
#include "MouseInput.h"

class MouseTracker {
public:
    MouseTracker();
    void update(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

private:
    MouseInput mouseInput;
};

#endif // MOUSE_TRACKER_H
