#include "IGSol.h"

IGSol::IGSol(int x, int y) : RectangleShape(sf::Vector2f(50, 50))
{
    this->setPosition(x, y);
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
