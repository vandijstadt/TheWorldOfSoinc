#ifndef MOMOPlayer_H
#define MOMOPlayer_H


#include <string>
#include <iostream>

class MOPlayer
{
public:
    MOPlayer();
    virtual ~MOPlayer();
    MOPlayer(const MOPlayer& other);
    MOPlayer& operator=(const MOPlayer& other);
    friend std::ostream& operator<<(std::ostream& out, const MOPlayer& MOPlayer);


    // Action
    int Die();

protected:

private:
    MOPlayer(int numberOfLifeVar);
    int numberOfLife;
};

#endif // MOMOPlayer_H
