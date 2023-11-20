#include "IGSol.h"

IGSol::IGSol(int x, int y) : RectangleShape(sf::Vector2f(50, 50))
{
//    ctor
    this->setFillColor(sf::Color::Green);
    this->setPosition(x, y);

    sf::Texture texture;
    if (!texture.loadFromFile("files/sol.png"))
    {
        std::cout << EXIT_FAILURE << std::endl;
    }

    this->setTexture(&texture, true);
}

IGSol::~IGSol()
{
    //dtor
}

IGSol::IGSol(const IGSol& other)
{
    //copy ctor
}

IGSol& IGSol::operator=(const IGSol& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
