#ifndef IGMUR_H
#define IGMUR_H

#include <SFML/Graphics.hpp>

class IGMur : public sf::RectangleShape
{
public:
    IGMur(int x, int y);
    virtual ~IGMur();
    IGMur(const IGMur& other);
    IGMur& operator=(const IGMur& other);

protected:

private:
};

#endif // IGMUR_H
