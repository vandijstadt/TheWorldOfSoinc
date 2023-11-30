#include "IGDrapeau.h"

IGDrapeau::IGDrapeau(int x, int y): IGRectangleShape(x, y)
{
    //ctor
//    this->setFillColor(sf::Color::Blue);
    typeBlock="Drapeau";
}

IGDrapeau::~IGDrapeau()
{
    //dtor
}

IGDrapeau::IGDrapeau(const IGDrapeau& other): IGRectangleShape(other)
{
    //copy ctor
}


IGDrapeau& IGDrapeau::operator=(const IGDrapeau& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

string IGDrapeau::TypeBlock()
{
    return typeBlock;
}
