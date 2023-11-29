#include "IGDrapeau.h"

IGDrapeau::IGDrapeau(int x, int y): RectangleShape(sf::Vector2f(50, 50))
{
    //ctor
    this->setFillColor(sf::Color::Blue);
    this->setPosition(x, y);
}

IGDrapeau::~IGDrapeau()
{
    //dtor
}

IGDrapeau::IGDrapeau(const IGDrapeau& other)
{
    //copy ctor
}

IGDrapeau& IGDrapeau::operator=(const IGDrapeau& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
