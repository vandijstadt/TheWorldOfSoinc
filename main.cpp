#include <SFML/Graphics.hpp>

#include <string>
#include <iostream>

#include <Player.h>

int main()
{

//    Player p;
//    std::cout << p << std::endl;

    int SCREEN_WIDTH=1200;
    int SCREEN_HEIGHT=600;
    float speedOfPlayer=-0.1f;

    sf::Vector2f gravity(0, 0.5f); // Gravitational force
    sf::Vector2f velocity(0, 0); // Initial velocity

    bool isJumping = false;

    // Creates an SFML window
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "The world of Soinc");
//sf::RenderWindow window(sf::VideoMode(SCREEN_RESIZE * SCREEN_WIDTH, SCREEN_RESIZE * SCREEN_HEIGHT), "Super Mario Bros", sf::Style::Close);

    // Create a point to represent the character
    sf::CircleShape player(25);
    player.setFillColor(sf::Color::Blue);
    player.setPosition(200, 450);
    window.draw(player);

    // Create a map
    sf::Texture map1;
    if (!map1.loadFromFile("files/map1.png")) {
        return EXIT_FAILURE;
    }

    // Create a sprite
    sf::Sprite MapNow(map1);

//    std::cout << "taille : " << MapNow.getLocalBounds().height << std::endl;
    MapNow.setScale(static_cast<float>(SCREEN_HEIGHT) / map1.getSize().y, static_cast<float>(SCREEN_HEIGHT) / map1.getSize().y);

    // Create a font
    sf::Font font;
    if (!font.loadFromFile("files/SuperMario256.ttf")) {
        return EXIT_FAILURE;
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        window.clear(sf::Color::Black);


        // Draw the map and player
        window.draw(MapNow);
        window.draw(player);

        // Move forward
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
            && -MapNow.getPosition().x + SCREEN_WIDTH < MapNow.getLocalBounds().width){
            MapNow.move(speedOfPlayer, .0f);
        }
        // Back down
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && MapNow.getPosition().x < 0) {
            MapNow.move(-speedOfPlayer, .0f);
        }

        // Jump
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !isJumping) {
            velocity.y = -15; // Apply an upward velocity to jump
            isJumping = true;
        }

        velocity += gravity; // Apply gravity
        player.move(velocity);

        if (player.getPosition().y >= 450) // Ground level
        {
            player.setPosition(player.getPosition().x, 450);
            velocity.y = 0;
            isJumping = false;
        }

        // Verfie if die

        // Displays the window
        window.display();
    }

    return 0;
}
