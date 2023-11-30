#ifndef IGDRAPEAU_H
#define IGDRAPEAU_H

#include <SFML/Graphics.hpp>
#include <IGRectangleShape.h>

class IGDrapeau : public IGRectangleShape
{
public:
    IGDrapeau(int x, int y);
    virtual ~IGDrapeau();
    IGDrapeau(const IGDrapeau& other);
    IGDrapeau& operator=(const IGDrapeau& other);
    virtual string TypeBlock();

protected:

private:
};

#endif // IGDRAPEAU_H
