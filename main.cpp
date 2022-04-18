#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "bat.h"
#include "ball.h"
#include <sstream>

int main() {
    // init window
    const int windowWidth = 1600, windowHeight = 900;
    sf::VideoMode vm(windowWidth, windowHeight);
    sf::RenderWindow window(vm, "pong");

    // init objects
    Bat bat1(100, 100, sf::Keyboard::Up, sf::Keyboard::Down);
    Bat bat2(windowWidth - 100, windowHeight - 100, sf::Keyboard::W, sf::Keyboard::S);
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

    sf::SoundBuffer clackBuffer;
    clackBuffer.loadFromFile("../assets/sounds/tick.wav");
    sf::Sound clack;
    clack.setBuffer(clackBuffer);

    sf::SoundBuffer scoreBuffer;
    scoreBuffer.loadFromFile("../assets/sounds/nope.wav");
    sf::Sound score;
    score.setBuffer(scoreBuffer);

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

        (!sf::Keyboard::isKeyPressed(bat1.getKeyUp()) || bat1.getPosition().top < 0)
            ? bat1.stopUp() : bat1.moveUp();
        (!sf::Keyboard::isKeyPressed(bat1.getKeyDown())
        || bat1.getPosition().top + bat1.getPosition().height > window.getSize().y)
            ? bat1.stopDown(): bat1.moveDown();

        (!sf::Keyboard::isKeyPressed(bat2.getKeyUp()) || bat2.getPosition().top < 0)
            ? bat2.stopUp() : bat2.moveUp();
        (!sf::Keyboard::isKeyPressed(bat2.getKeyDown())
        || bat2.getPosition().top + bat2.getPosition().height > window.getSize().y)
            ? bat2.stopDown(): bat2.moveDown();

        // update object state
        sf::Time dt = clock.restart();
        bat1.update(dt);
        bat2.update(dt);
        ball.update(dt);

        // handle collision
        if (ball.getPosition().top < 0 || ball.getPosition().top > window.getSize().y) {
            ball.bounceTopOrBot();
            clack.play();
        }
        if (ball.getPosition().intersects(bat1.getPosition()) || ball.getPosition().intersects(bat2.getPosition())) {
            ball.reboundSides();
            ball.speedUp();
            clack.play();
        }
        if (ball.getPosition().left < 0) {
            ball.reset(windowWidth / 2, windowHeight / 2);
            score2 += 1;
            score.play();
        }
        if (ball.getPosition().left + ball.getPosition().width > window.getSize().x) {
            ball.reset(windowWidth / 2, windowHeight / 2);
            score1 += 1;
            score.play();
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