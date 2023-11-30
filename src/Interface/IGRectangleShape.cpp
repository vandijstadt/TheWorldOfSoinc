#include "IGRectangleShape.h"

IGRectangleShape::IGRectangleShape(int x, int y): RectangleShape(sf::Vector2f(50, 50))
{
    //ctor
    this->setPosition(x, y);
    typeBlock="Error";
}

IGRectangleShape::~IGRectangleShape()
{
    //dtor
}
IGRectangleShape::IGRectangleShape(const IGRectangleShape& other) : RectangleShape(other)
{
    //copy ctor
    typeBlock = other.typeBlock;
}

IGRectangleShape& IGRectangleShape::operator=(const IGRectangleShape& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator

    return *this;
}

string IGRectangleShape::TypeBlock()
{
    return typeBlock;
}
