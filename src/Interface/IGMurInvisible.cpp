#include "IGMurInvisible.h"

IGMurInvisible::IGMurInvisible(int x, int y) : IGRectangleShape(x, y)
{
    //ctor
    this->setFillColor(sf::Color::Transparent); //Change to the background color or transparent
    typeBlock="MurInvisible";
}
IGMurInvisible::~IGMurInvisible()
{
    //dtor
}

IGMurInvisible::IGMurInvisible(const IGMurInvisible& other): IGRectangleShape(other)
{
    //copy ctor
}

IGMurInvisible& IGMurInvisible::operator=(const IGMurInvisible& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

string IGMurInvisible::TypeBlock()
{
    return typeBlock;
}
