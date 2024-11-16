#include <SFML/Graphics.hpp>
#include <iostream>
#include "CollisionHandler.h"
#include "Circle.h"
#include "Rectangle.h"
#include "MouseTracker.h"
#include "Grabbing.h"
#include "Backround.h"
#include "Camera.h"

Circle circle;
Rectangle rectangle;
Backround backround;
MouseTracker mouseTracker;
Grabbing grabbing;
Camera camera;

void Update(float deltaTime, sf::RenderWindow& window) {
    circle.update(deltaTime);
    rectangle.update(deltaTime);
    backround.update(deltaTime);

    // Handle collision between circle and rectangle
    CollisionHandler::HandleCollision(circle, rectangle);
    mouseTracker.update(window);
    grabbing.update(window, circle, deltaTime);

    // Update the camera
    camera.update(window);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "CKVR 2d Physics System");
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Handle mouse wheel scrolling
            if (event.type == sf::Event::MouseWheelScrolled) {
                if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                    if (event.mouseWheelScroll.delta > 0) {
                        camera.zoomIn(); // Zoom in
                    }
                    else if (event.mouseWheelScroll.delta < 0) {
                        camera.zoomOut(); // Zoom out
                    }
                }
            }

            // Handle key press
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::C) {
                    camera.lockOntoCircle(!camera.isLockedOntoCircle());
                }
            }
        }

        float deltaTime = clock.restart().asSeconds();

        // Lock the camera onto the circle if the lock is enabled
        if (camera.isLockedOntoCircle()) {
            camera.setCenter(circle.getPosition());
        }

        Update(deltaTime, window);

        window.clear();

        // Apply the view transformation
        sf::View view = window.getView();
        view.setCenter(camera.getCenter());
        view.setSize(sf::Vector2f(window.getSize()));
        view.zoom(camera.getZoom());
        window.setView(view);

        // Render the objects
        backround.draw(window);
        rectangle.draw(window);
        circle.draw(window);
        mouseTracker.draw(window);

        window.display();
    }
    return 0;
}
