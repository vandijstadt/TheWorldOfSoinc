#ifndef IGMUR_H
#define IGMUR_H

#include <SFML/Graphics.hpp>
#include <IGRectangleShape.h>

class IGMur : public IGRectangleShape
{
public:
    IGMur(int x, int y);
    virtual ~IGMur();
    IGMur(const IGMur& other);
    IGMur& operator=(const IGMur& other);
    virtual string TypeBlock();

protected:

private:
};

#endif // IGMUR_H
