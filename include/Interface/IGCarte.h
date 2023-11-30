#ifndef IGCARTE_H
#define IGCARTE_H

#include <SFML/Graphics.hpp>

#include <string>
#include <iostream>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <sstream>

#include <Interface/IGCarte.h>
#include <Interface/IGSol.h>
#include <Interface/IGMur.h>
#include <Interface/IGMob.h>
#include <Interface/IGDrapeau.h>
#include <Interface/IGMurInvisible.h>
#include <MainMenu.h>


#include <Modele/MOPlayer.h>

using std::string;
using std::vector;
using std::endl;
using std::cout;
using std::cerr;

class IGCarte : public sf::RenderWindow
{
public:
    IGCarte(MOPlayer &player, std::vector<std::vector<char>> matrix, sf::Vector2u windowSize, bool isFullscreen);
    virtual ~IGCarte();

    void update();

protected:

private:

    vector<vector<char>> MOmatrix;
    vector<sf::RectangleShape> IGmatrix;
    vector<sf::Vector2f> IGmatrixPostion;

    sf::Font font;
    sf::Text text;
    sf::Sprite player;
//    sf::Texture map1;
//    sf::Sprite MapNow;

    float speedOfPlayer=-0.1f;

    sf::Vector2f gravity; // Gravitational force
    sf::Vector2f velocity; // Initial velocity
    sf::Vector2f previousPlayerPosition;
    bool isJumping = false;

    char sol = '-';
    char brique = '*';
    char mob = 'x';
    char drapeau = '|';
    char mur_invisble = '[';
    bool isFullscreen;
    sf::Texture textureSol;
    sf::Texture textureBrique;
    sf::Texture textureMob;
//    sf::Texture textureBloc;
    sf::Texture texturePlayer;

    std::ofstream logFile;

    MOPlayer mOPlayer;

    void _move();
    void _forward();
    void _back();
    void _jump();

    void die();
    void succes();

    void actionWhenInteractWithRectange(sf::RectangleShape e);

    string formatedNumber(int number);
    void reset();

};

#endif // IGCARTE_H
