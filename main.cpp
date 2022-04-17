#include <SFML/Graphics.hpp>
#include "bat.h"
#include <sstream>
//#include <cstdlib>

// todo: score board
// todo: game class
// todo: add test?
// todo: rectangle (for the table)

int main() {
    // init window
    const int windowWidth = 1600, windowHeight = 900;
    sf::VideoMode vm(windowWidth, windowHeight);
    sf::RenderWindow window(vm, "pong");

    // init objects
    Bat bat(100, 100);
    int score = 10;
    sf::Text hud;
    sf::Font font;
    font.loadFromFile("../assets/fonts/JetBrainsMono-Bold.ttf");
    hud.setFont(font);
    hud.setCharacterSize(60);
    hud.setFillColor(sf::Color::White);
    hud.setPosition(20 , 20);
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
        sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ? bat.moveUp() : bat.stopUp();
        sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ? bat.moveDown(): bat.stopDown();

        // update object state
        sf::Time dt = clock.restart();
        bat.update(dt);
        std::stringstream ss;
        ss << score;
        hud.setString(ss.str());

        // clear window
        window.clear();

        // then draw
        window.draw(hud);
        window.draw(bat.getShape());

        // display window
        window.display();
    }

    return 0;
}