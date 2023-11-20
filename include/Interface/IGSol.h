#ifndef IGSOL_H
#define IGSOL_H

#include <SFML/Graphics.hpp>

#include <iostream>

class IGSol : public sf::RectangleShape
{
public:
    IGSol(int x, int y);
    virtual ~IGSol();
    IGSol(const IGSol& other);
    IGSol& operator=(const IGSol& other);

protected:

private:
};

#endif // IGSOL_H
