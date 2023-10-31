#include "Action.h"

Action::Action()
{
    //ctor
}

Action::~Action()
{
    //dtor
}

Action::Action(const Action& other)
{
    //copy ctor
}

Action& Action::operator=(const Action& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
