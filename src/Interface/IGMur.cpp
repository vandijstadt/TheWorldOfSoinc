#include "IGMur.h"

IGMur::IGMur(int x, int y) : IGRectangleShape(x, y)
{
    //ctor
    typeBlock="Mur";

}
IGMur::~IGMur()
{
    //dtor
}

IGMur::IGMur(const IGMur& other): IGRectangleShape(other)
{
    //copy ctor
}

IGMur& IGMur::operator=(const IGMur& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}


string IGMur::TypeBlock()
{
    return typeBlock;
}
