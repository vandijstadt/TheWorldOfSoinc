#ifndef IGCARTE_H
#define IGCARTE_H

#include <SFML/Graphics.hpp>

#include <string>
#include <iostream>
#include <chrono>
#include <fstream>
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

    vector<vector<char>> MOmatrix;
    vector<sf::RectangleShape> IGmatrix;

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
    char mob = 'x';
    char mur = '*';
    char mur_invisble = '[';

//    sf::RectangleShape *PremieBlock;
//    sf::RectangleShape *dernierBlock;
    std::ofstream logFile;

    void _move();
    void _forward();
    void _back();
    void _jump();

    void actionWhenInteractWithRectange(sf::RectangleShape e);

    string formatedNumber(int number);




};

#endif // IGCARTE_H
