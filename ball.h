#pragma once
#include <SFML/Graphics.hpp>

class Ball {
private:
    sf::Vector2f position;
    sf::RectangleShape shape;
    const float defaultSpeed = 1500.0f;
    float speed = defaultSpeed;
    float directionX = .2f;
    float directionY = .2f;

public:
    Ball(float startX, float startY);
    sf::FloatRect getPosition();
    sf::RectangleShape getShape();
    void reboundSides();
    void bounceTopOrBot();
    void update(sf::Time dt);
    void speedUp();
    void reset(float x, float y);
};

Ball::Ball(float startX, float startY) {
    position.x = startX;
    position.y = startY;
    shape.setSize(sf::Vector2f(20, 20));
    shape.setPosition(position);
}

sf::FloatRect Ball::getPosition() {
    return shape.getGlobalBounds();
}

sf::RectangleShape Ball::getShape() {
    return shape;
}

void Ball::reboundSides() {
    directionX = -directionX;
}

void Ball::bounceTopOrBot() {
    directionY = -directionY;
}

void Ball::update(sf::Time dt) {
    position.y += directionY * speed * dt.asSeconds();
    position.x += directionX * speed * dt.asSeconds();
    shape.setPosition(position);
}

void Ball::speedUp() {
    speed *= 1.1;
}

void Ball::reset(float x, float y) {
    position.x = x;
    position.y = y;
    speed = defaultSpeed;
    float dir[] = {1.0, -1.0};
    directionX *= dir[int(rand() % 2)];
    directionY *= dir[int(rand() % 2)];
}