#ifndef IGRECTANGLESHAPE_H
#define IGRECTANGLESHAPE_H

#include <SFML/Graphics.hpp>

using std::string;

class IGRectangleShape : public sf::RectangleShape
{
public:
    IGRectangleShape(int x, int y);
    virtual ~IGRectangleShape();
    IGRectangleShape(const IGRectangleShape& other);
    IGRectangleShape& operator=(const IGRectangleShape& rhs);
    virtual string TypeBlock();
//    virtual string TypeBlock()=0;

protected:
    string typeBlock;

private:
};

#endif // IGRECTANGLESHAPE_H
