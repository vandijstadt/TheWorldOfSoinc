#ifndef IGCARTE_H
#define IGCARTE_H

#include <SFML/Graphics.hpp>

#include <string>
#include <iostream>
#include <chrono>

#include <iomanip>
#include <sstream>

#include <IGCarte.h>

using std::string;
using std::vector;
using std::endl;
using std::cout;
using std::cerr;

class IGCarte
{
public:
    IGCarte(sf::RenderWindow &window, std::vector<std::vector<char>> matrix);
    virtual ~IGCarte();

    void update();

protected:

private:
    sf::RenderWindow &window;

    std::vector<std::vector<char>> MOmatrix;
    std::vector<sf::RectangleShape> IGmatrix;

    sf::Font font;
    sf::CircleShape player;
    sf::Texture map1;
    sf::Sprite MapNow;

    int SCREEN_WIDTH = 1200;
    int SCREEN_HEIGHT = 600;
    float speedOfPlayer=-0.1f;

    sf::Vector2f gravity; // Gravitational force
    sf::Vector2f velocity; // Initial velocity
    bool isJumping = false;


    char sol = '-';
    char drapeau = '|';
    char mur = '*';
    char mur_invisble = '[';

//    sf::RectangleShape *PremieBlock;
//    sf::RectangleShape *dernierBlock;

    void _move();
    void _forward();
    void _back();
    void _jump();
    string formatedNumber(int number);



};

#endif // IGCARTE_H
