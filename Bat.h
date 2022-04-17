#pragma once // processed only once by the compiler
#include <SFML/Graphics.hpp>

class Bat {
private:
    sf::Vector2f position;
    sf::RectangleShape shape;
    float speed = 1000;
    // float acc;
    bool movingUp = false;
    bool movingDown = false;
    // todo: bat only move if match string command
    // todo: make sure x is locked
    // todo: score for a bat
    // todo: moving with accerleration

public:
    Bat(float startX, float startY);
    sf::FloatRect getPosition();
    sf::RectangleShape getShape();
    void moveUp();
    void moveDown();
    void stopUp();
    void stopDown();
    void update(sf::Time dt);
};

//#include "bat.h"

Bat::Bat(float startX, float startY) {
    position.x = startX;
    position.y = startY;
    shape.setSize(sf::Vector2f(10, 100));
    shape.setPosition(position);
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