#include <SFML/Graphics.hpp>

#include <iostream>

int main()
{
    int tailleX=1200;
    int tailleY=600;

    // Creates an SFML window
    sf::RenderWindow window(sf::VideoMode(tailleX, tailleY), "The world of Soinc");

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
    MapNow.setScale(static_cast<float>(tailleY) / map1.getSize().y, static_cast<float>(tailleY) / map1.getSize().y);

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
            && -MapNow.getPosition().x + tailleX < MapNow.getLocalBounds().width){
            MapNow.move(-.9f, .0f);
        }
        // Back down
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && MapNow.getPosition().x < 0) {
            MapNow.move(.01f, .0f);
        }

        // Jump
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && MapNow.getPosition().x < 450) {
            player.move(.0f, -.02f);
        }
        // Verfie if die

        // Displays the window
        window.display();
    }

    return 0;
}
