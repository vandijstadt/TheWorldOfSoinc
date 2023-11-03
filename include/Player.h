#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

class Player
{
    public:
        Player();
        virtual ~Player();
        Player(const Player& other);
        Player& operator=(const Player& other);
        friend std::ostream& operator<<(std::ostream& out, const Player& player);


        // Action
        int Die();

    protected:

    private:
        Player(int numberOfLifeVar);
        int numberOfLife;
};

#endif // PLAYER_H
