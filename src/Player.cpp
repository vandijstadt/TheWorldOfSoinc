#include "Player.h"

Player::Player():numberOfLife(5)
{
    //ctor
}
Player::Player(int numberOfLifeVar)
{
    //ctor
    numberOfLife=numberOfLifeVar;
}

Player::~Player()
{
    //dtor
}

Player::Player(const Player& other)
{
    //copy ctor
}

Player& Player::operator=(const Player& rhs)
{
    if (&rhs != this)
    { this->numberOfLife=rhs.numberOfLife; }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Player& player)
{
    return out << "Number of life: " << std::to_string(player.numberOfLife);
}


int Player::Die()
{
    this->numberOfLife-=1;
    return this->numberOfLife;
}
