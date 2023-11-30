#ifndef IGSOL_H
#define IGSOL_H

#include <SFML/Graphics.hpp>
#include <IGRectangleShape.h>

#include <iostream>

class IGSol : public IGRectangleShape
{
public:
    IGSol(int x, int y);
    virtual ~IGSol();
    IGSol(const IGSol& other);
    IGSol& operator=(const IGSol& other);
    virtual string TypeBlock();

protected:

private:
};

#endif // IGSOL_H
