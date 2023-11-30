#include "IGSol.h"

IGSol::IGSol(int x, int y) : IGRectangleShape(x, y)
{
    //ctor
    typeBlock="Sol";
}

IGSol::~IGSol()
{
    //dtor
}

IGSol::IGSol(const IGSol& other): IGRectangleShape(other)
{
    //copy ctor
}

IGSol& IGSol::operator=(const IGSol& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
string IGSol::TypeBlock()
{
    return typeBlock;
}
