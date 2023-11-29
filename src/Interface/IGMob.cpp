#include "IGMob.h"

IGMob::IGMob(int x, int y): RectangleShape(sf::Vector2f(50, 50))
{
    //ctor
    this->setFillColor(sf::Color::Red);
    this->setPosition(x, y);
}

IGMob::~IGMob()
{
    //dtor
}

IGMob::IGMob(const IGMob& other)
{
    //copy ctor
}

IGMob& IGMob::operator=(const IGMob& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
