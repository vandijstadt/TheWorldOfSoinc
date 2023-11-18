#include "Modele/MOPlayer.h"

MOPlayer::MOPlayer():numberOfLife(5)
{
    //ctor
}
MOPlayer::MOPlayer(int numberOfLifeVar)
{
    //ctor
    numberOfLife=numberOfLifeVar;
}

MOPlayer::~MOPlayer()
{
    //dtor
}

MOPlayer::MOPlayer(const MOPlayer& other)
{
    //copy ctor
}

MOPlayer& MOPlayer::operator=(const MOPlayer& rhs)
{
    if (&rhs != this)
    {
        this->numberOfLife=rhs.numberOfLife;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const MOPlayer& MOPlayer)
{
    return out << "Number of life: " << std::to_string(MOPlayer.numberOfLife);
}


int MOPlayer::Die()
{
    this->numberOfLife-=1;
    return this->numberOfLife;
}
