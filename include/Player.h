#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
    public:
        Player();
        virtual ~Player();
        Player(const Player& other);
        Player& operator=(const Player& other);

        // Action
        int Die() const;

    protected:

    private:
        bool numberOfLife;
};

#endif // PLAYER_H
