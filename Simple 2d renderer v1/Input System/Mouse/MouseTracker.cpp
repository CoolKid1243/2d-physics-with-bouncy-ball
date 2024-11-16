#include "MouseTracker.h"

MouseTracker::MouseTracker() {}

void MouseTracker::update(sf::RenderWindow& window) {
    mouseInput.update(window);
}

void MouseTracker::draw(sf::RenderWindow& window) {
    // Drawing code if needed in future
}
