#ifndef IGMURINVISIBLE_H
#define IGMURINVISIBLE_H

#include <SFML/Graphics.hpp>
#include <IGRectangleShape.h>

#include <iostream>

class IGMurInvisible : public IGRectangleShape
{
public:
    IGMurInvisible(int x, int y);
    virtual ~IGMurInvisible();
    IGMurInvisible(const IGMurInvisible& other);
    IGMurInvisible& operator=(const IGMurInvisible& other);
    virtual string TypeBlock();

protected:

private:
};

#endif // IGMURINVISIBLE_H
