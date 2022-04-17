#include <SFML/Graphics.hpp>
#include "bat.h"
#include "ball.h"
#include <sstream>

int main() {
    // init window
    const int windowWidth = 1600, windowHeight = 900;
    sf::VideoMode vm(windowWidth, windowHeight);
    sf::RenderWindow window(vm, "pong");

    // init objects
    Bat bat1(100, 100);
    Bat bat2(windowWidth - 100, windowHeight - 100);
    Ball ball(600, 600);
    int score1 = 0;
    int score2 = 0;

    sf::Text hud;
    sf::Font font;
    font.loadFromFile("../assets/fonts/JetBrainsMono-Bold.ttf");
    hud.setFont(font);
    hud.setCharacterSize(60);
    hud.setFillColor(sf::Color::White);
    hud.setPosition(windowWidth / 2 - 55 , 10);

    sf::Clock clock;

    // game loop
    while (window.isOpen()) {
        // handle user input event
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }
        (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || bat1.getPosition().top < 0)
            ? bat1.stopUp() : bat1.moveUp();
        (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || bat1.getPosition().top + bat1.getPosition().height > window.getSize().y)
            ? bat1.stopDown(): bat1.moveDown();
        sf::Keyboard::isKeyPressed(sf::Keyboard::W) ? bat2.moveUp() : bat2.stopUp();
        sf::Keyboard::isKeyPressed(sf::Keyboard::S) ? bat2.moveDown(): bat2.stopDown();

        // update object state
        sf::Time dt = clock.restart();
        bat1.update(dt);
        bat2.update(dt);
        ball.update(dt);

        if (ball.getPosition().top > window.getSize().y) ball.reboundBottom();
        if (ball.getPosition().top < 0) ball.reboundBatOrTop();
        if (ball.getPosition().left < 0) {
            ball.reset(windowWidth / 2, windowHeight / 2);
            score2 += 1;
        }
        if (ball.getPosition().left + ball.getPosition().width > window.getSize().x) {
            ball.setPosition(windowWidth / 2, windowHeight / 2);
            score1 += 1;
        }
        if (ball.getPosition().intersects(bat1.getPosition())) {
            // Hit detected so reverse the ball and score a point
            ball.reboundSides();
            ball.speedUp();
        }

        std::stringstream ss;
        ss << score1 << ":" << score2;
        hud.setString(ss.str());

        // clear window
        window.clear();

        // then draw
        window.draw(hud);
        window.draw(bat1.getShape());
        window.draw(bat2.getShape());
        window.draw(ball.getShape());

        // display window
        window.display();
    }

    return 0;
}