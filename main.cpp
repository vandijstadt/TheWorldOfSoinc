#include <SFML/Graphics.hpp>

#include <iostream>

int main()
{
    int tailleX=800;
    int tailleY=600;

    // Crée une fenêtre SFML
    sf::RenderWindow window(sf::VideoMode(tailleX, tailleY), "The world of Soinc");

    // Crée un rectangle pour représenter le personnage
//    sf::RectangleShape character(sf::Vector2f(50, 100));
//    character.setPosition(375, 450);  // Positionne le personnage sur le sol
//    character.setFillColor(sf::Color::Red);

    // Crée un carte
    sf::Texture map1;
    if (!map1.loadFromFile("files/map1.png")) {
        return EXIT_FAILURE;
    }
    sf::Sprite MapNow(map1);

    sf::Font font;
    if (!font.loadFromFile("files/SuperMario256.ttf")) {
        return EXIT_FAILURE;
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        // Dessine le sol et le personnage
        window.draw(MapNow);

        // Move forward
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
            && -MapNow.getPosition().x + tailleX < map1.getSize().x){
            MapNow.move(-.1f, .0f);
//            std::cout << "Position x de fin page: " << -MapNow.getPosition().x + tailleX << " | Taille : " << map1.getSize().x << std::endl;
        }
        // Back down
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && MapNow.getPosition().x < 0) {
            MapNow.move(.1f, .0f);
//            std::cout << "Position x : " << -MapNow.getPosition().x << " < " << 0 << std::endl;
        }

        // Jump

        // Verfie if die

        window.display();
    }

    return 0;
}
