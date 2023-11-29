#include "IGMurInvisible.h"

IGMurInvisible::IGMurInvisible(int x, int y) : RectangleShape(sf::Vector2f(50, 50))
{
    //ctor
    this->setFillColor(sf::Color::White); //Change to the background color or transparent
    this->setPosition(x, y);


}
IGMurInvisible::~IGMurInvisible()
{
    //dtor
}

IGMurInvisible::IGMurInvisible(const IGMurInvisible& other)
{
    //copy ctor
}

IGMurInvisible& IGMurInvisible::operator=(const IGMurInvisible& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
