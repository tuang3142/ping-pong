#pragma once // processed only once by the compiler
#include <SFML/Graphics.hpp>
#include <iostream>

class Bat {
private:
    sf::Vector2f position;
    sf::RectangleShape shape;
    float speed = 1000;
    bool movingUp = false;
    bool movingDown = false;
    sf::Keyboard::Key keyUp;
    sf::Keyboard::Key keyDown;

public:
    Bat(float startX, float startY, sf::Keyboard::Key up, sf::Keyboard::Key down);
    sf::FloatRect getPosition();
    sf::RectangleShape getShape();
    void moveUp();
    void moveDown();
    void stopUp();
    void stopDown();
    void update(sf::Time dt);
    sf::Keyboard::Key getKeyUp();
    sf::Keyboard::Key getKeyDown();
};

Bat::Bat(float startX, float startY, sf::Keyboard::Key up, sf::Keyboard::Key down) {
    position.x = startX;
    position.y = startY;
    shape.setSize(sf::Vector2f(10, 100));
    shape.setPosition(position);
    keyUp = up;
    keyDown = down;
}

sf::FloatRect Bat::getPosition() {
    return shape.getGlobalBounds();
}

sf::RectangleShape Bat::getShape() {
    return shape;
}

void Bat::moveUp() {
    movingUp = true;
}

void Bat::moveDown() {
    movingDown = true;
}

void Bat::stopDown() {
    movingDown = false;
}

void Bat::stopUp() {
    movingUp = false;
}

void Bat::update(sf::Time dt) {
    float distance = speed * dt.asSeconds();
    if (movingUp) {
        position.y -= distance;
    }
    if (movingDown) {
        position.y += distance;
    }
    shape.setPosition(position);
}

sf::Keyboard::Key Bat::getKeyDown() {
    return keyDown;
}

sf::Keyboard::Key Bat::getKeyUp() {
    return keyUp;
}