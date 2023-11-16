#include "IGCarte.h"

IGCarte::IGCarte(sf::RenderWindow &window, std::vector<std::vector<char>> matrix) : window(window), MOmatrix(matrix)
{
    // Create a font
    if (!font.loadFromFile("files/SuperMario256.ttf"))
    {
        std::cout << EXIT_FAILURE << std::endl;
    }

//    // Create a map
//    if (!map1.loadFromFile("files/map1.png"))
//    {
//        std::cout << EXIT_FAILURE << std::endl;
//    }
//
//    // Create a sprite
//    MapNow.setTexture(map1);
//    // Resize sprite
//    MapNow.setScale(static_cast<float>(SCREEN_HEIGHT) / map1.getSize().y, static_cast<float>(SCREEN_HEIGHT) / map1.getSize().y);


    // Create a point to represent the character
    player.setRadius(25);
    player.setFillColor(sf::Color::Blue);
    player.setPosition(200, 450);

    gravity = sf::Vector2f(0.0f, 0.5f);
    velocity = sf::Vector2f(0.0f, 0.0f);

//     A supprimer
    int rows = MOmatrix.size(); // 12
    int cols = MOmatrix[0].size(); // 20

    std::cerr << rows << "/" << cols << std::endl;

    int i,j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if(sol==MOmatrix[i][j])
            {
                sf::RectangleShape tmp(sf::Vector2f(50, 50));
                tmp.setFillColor(sf::Color::Green);
                tmp.setPosition(tmp.getSize().y * j,window.getSize().y - tmp.getSize().y);
                IGmatrix.push_back(tmp);

//                std::cerr << i << ":" << j << std::endl;
            }
            else if(drapeau==MOmatrix[i][j])
            {
                sf::RectangleShape tmp(sf::Vector2f(50, 500));
                tmp.setFillColor(sf::Color::Red);
                tmp.setPosition(50 * j,50 * i);
                IGmatrix.push_back(tmp);

//                std::cerr << i << ":" << j << std::endl;
            }
        }
    }
 sf::RectangleShape tmp(sf::Vector2f(50, 50));
 tmp.setFillColor(sf::Color::Green);
                tmp.setPosition(25,25);
    PremieBlock = &tmp;
    dernierBlock = &tmp;

    for(sf::RectangleShape x :IGmatrix)
        if(x.getPosition().x < PremieBlock->getPosition().x)
            std::cerr << " ";
//            PremieBlock=&x;
//        else if(x.getPosition().x>dernierBlock->getPosition().x)
//            std::cerr << " ";
//            dernierBlock=&x;

//    PremieBlock->setFillColor(sf::Color::Red);


}

IGCarte::~IGCarte()
{
    //dtor
}
void IGCarte::update()
{
    window.clear(sf::Color::Cyan);
//    window.draw(MapNow);
    for(sf::RectangleShape x :IGmatrix)
        window.draw(x);
    window.draw(player);

    _move();

    // Verifier la mort et la fin de jeux

    window.display();
}
void IGCarte::_move()
{
    _forward();
    _back();
    _jump();

    sf::sleep(sf::milliseconds(20));

}

void IGCarte::_forward()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {

        for(sf::RectangleShape &e :IGmatrix)
            e.move(-5.0f, 0.0f);

        std::cerr << "Avancer !" << std::endl;
    }
}

void IGCarte::_back()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        for(sf::RectangleShape &e :IGmatrix)
            e.move(5.0f, 0.0f);
        std::cerr << "Reculer !" << std::endl;
    }
}

void IGCarte::_jump()
{
// Vérifier si la touche de saut est pressée et le personnage n'est pas déjà en train de sauter
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !isJumping)
    {
        // Appliquer une vélocité vers le haut pour le saut
        velocity.y = -15;
        isJumping = true;
        std::cerr << "Sauter !" << std::endl;
    }

// Appliquer la gravité à la vélocité
    velocity += gravity;

// Déplacer le joueur en fonction de la vélocité
    player.move(velocity);

// Si le joueur atteint le niveau du sol
    int hauteurSol=500;

    for(sf::RectangleShape &e :IGmatrix)
        if(e.getPosition().x == player.getPosition().x)
            hauteurSol = e.getPosition().y;

    if (player.getPosition().y >= hauteurSol)
    {
        // Ajuster la position du joueur au niveau du sol
        player.setPosition(player.getPosition().x, hauteurSol);

        // Réinitialiser la vélocité verticale et l'état du saut
        velocity.y = 0;
        isJumping = false;
    }

}
