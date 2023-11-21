#ifndef IGDRAPEAU_H
#define IGDRAPEAU_H

#include <SFML/Graphics.hpp>

class IGDrapeau : public sf::RectangleShape
{
public:
    IGDrapeau(int x, int y);
    virtual ~IGDrapeau();
    IGDrapeau(const IGDrapeau& other);
    IGDrapeau& operator=(const IGDrapeau& other);

protected:

private:
};

#endif // IGDRAPEAU_H
