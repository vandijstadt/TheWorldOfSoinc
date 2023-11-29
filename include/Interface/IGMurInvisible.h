#ifndef IGMURINVISIBLE_H
#define IGMURINVISIBLE_H

#include <SFML/Graphics.hpp>

#include <iostream>

class IGMurInvisible : public sf::RectangleShape
{
public:
    IGMurInvisible(int x, int y);
    virtual ~IGMurInvisible();
    IGMurInvisible(const IGMurInvisible& other);
    IGMurInvisible& operator=(const IGMurInvisible& other);

protected:

private:
};

#endif // IGMURINVISIBLE_H
