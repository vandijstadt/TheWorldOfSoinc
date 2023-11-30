#ifndef IGMOB_H
#define IGMOB_H

#include <SFML/Graphics.hpp>
#include <IGRectangleShape.h>

class IGMob : public IGRectangleShape
{
public:
    IGMob(int x, int y);
    virtual ~IGMob();
    IGMob(const IGMob& other);
    IGMob& operator=(const IGMob& other);
    void disappear();// Il faut le delete pas le mettre a un autre endroit
    virtual string TypeBlock();

protected:

private:
};

#endif // IGMOB_H
