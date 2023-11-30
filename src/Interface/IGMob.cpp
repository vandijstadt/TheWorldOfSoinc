#include "IGMob.h"

IGMob::IGMob(int x, int y): IGRectangleShape(x, y)
{
    //ctor
    this->typeBlock="Mob";
}

IGMob::~IGMob()
{
    //dtor
}

IGMob::IGMob(const IGMob& other): IGRectangleShape(other)
{
    //copy ctor
}

IGMob& IGMob::operator=(const IGMob& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

string IGMob::TypeBlock()
{
    return typeBlock;
}
