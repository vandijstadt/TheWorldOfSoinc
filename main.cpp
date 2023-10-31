#include <SFML/Graphics.hpp>

int main()
{
    // Crée une fenêtre SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "The world of Soinc");

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

    // Pour mes test

    sf::Text textRight;
    textRight.setFont(font); // Définissez la police
    textRight.setString("Right"); // Définissez le texte
    textRight.setCharacterSize(24); // Définissez la taille de la police
    textRight.setFillColor(sf::Color::Red); // Définissez la couleur du texte

    sf::Text textLeft;
    textLeft.setFont(font); // Définissez la police
    textLeft.setString("Left"); // Définissez le texte
    textLeft.setCharacterSize(24); // Définissez la taille de la police
    textLeft.setFillColor(sf::Color::Red); // Définissez la couleur du texte


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


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            MapNow.move(.01f, .0f);
//            window.draw(textLeft);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            MapNow.move(-.01f, .0f);
//            window.draw(textRight);
        }

        window.display();
    }

    return 0;
}
