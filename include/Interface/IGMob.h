#ifndef IGMOB_H
#define IGMOB_H

#include <SFML/Graphics.hpp>

class IGMob : public sf::RectangleShape
{
public:
    IGMob(int x, int y);
    virtual ~IGMob();
    IGMob(const IGMob& other);
    IGMob& operator=(const IGMob& other);
    void disappear();

protected:

private:
};

#endif // IGMOB_H
