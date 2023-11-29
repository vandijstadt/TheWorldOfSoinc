#include "IGMur.h"

IGMur::IGMur(int x, int y) : RectangleShape(sf::Vector2f(50, 50))
{
    //ctor
    this->setFillColor(sf::Color::Yellow);
    this->setPosition(x, y);


}
IGMur::~IGMur()
{
    //dtor
}

IGMur::IGMur(const IGMur& other)
{
    //copy ctor
}

IGMur& IGMur::operator=(const IGMur& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
