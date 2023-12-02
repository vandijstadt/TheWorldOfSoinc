#include "Interface/IGCarte.h"

IGCarte::IGCarte(MOPlayer & mOPlayer, vector < vector < char >> matrix, sf::Vector2u windowSize, bool isFullscreen): RenderWindow(sf::VideoMode(1200, 600), "The world of Sonic"), MOmatrix(matrix), isFullscreen(isFullscreen)
{
    if (isFullscreen)
    {
        this -> close();
        create(sf::VideoMode::getDesktopMode(), "The world of Sonic", sf::Style::Fullscreen);
        sf::View view;
        view.setSize(sf::Vector2f(1200, 600));
        view.setCenter(sf::Vector2f(650.f, 780.f));
        this->setView(view);
    }

    this -> mOPlayer = mOPlayer;

    // Create a font
    font.loadFromFile("files/SuperMario256.ttf");

    textureSol.loadFromFile("files/sol.png");
    textureBrique.loadFromFile("files/brique.png");
    textureMob.loadFromFile("files/spike.png");
//    textureBloc.loadFromFile("files/bloc.png");
    texturePlayer.loadFromFile("files/soinc.png");
    textureDrapeau.loadFromFile("files/drapeau.png");
    exitTexture.loadFromFile("files/exit.png");

    exitSprite.setTexture(exitTexture);
//    sf::Vector2f viewSize = sf::Vector2f(1200.f,600.f);
    exitSprite.setPosition(1200.f - exitSprite.getGlobalBounds().width, 0);

//    player.setRadius(20);
    player.setPosition(200, 450);
    player.setScale(0.2f, 0.2f);
    player.setTexture(texturePlayer);


    gravity = sf::Vector2f(0.0f, 0.5f);
    velocity = sf::Vector2f(0.0f, 0.0f);

    logFile = std::ofstream("log.txt", std::ios::trunc);

    // Date et heure actuel
    auto currentTime = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(currentTime);
    string timeString = std::ctime( & time);

    string texte = "==================== " + timeString + " ===================="; // Le texte de debut de fichier
    texte.erase(std::remove_if(texte.begin(), texte.end(), [](char c)
    {
        return c == '\n';
    }), texte.end()); // Supprime un retour a la ligne

    logFile << texte << endl;
    int rows = MOmatrix.size();
    int cols = MOmatrix[0].size();

    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (sol == MOmatrix[i][j])
            {
                IGSol tmp(50 * j, this -> getSize().y - (50 * (rows - i)));
                tmp.setTexture(&textureSol);
                IGmatrix.push_back(tmp);
                IGmatrixPostion.push_back(tmp.getPosition());

                //                logFile << "Sol ajouté - Position : (" << formatedNumber(tmp.getPosition().x) << ", " << formatedNumber(tmp.getPosition().y) << "), Taille : (" << tmp.getSize().x << ", " << tmp.getSize().y << ")" << endl;
            }
            else if (brique == MOmatrix[i][j])
            {
                IGMur tmp(50 * j, this -> getSize().y - (50 * (rows - i)));
                tmp.setTexture(&textureBrique);
                IGmatrix.push_back(tmp);
                IGmatrixPostion.push_back(tmp.getPosition());

                //                logFile << "Mur ajouté - Position : (" << formatedNumber(tmp.getPosition().x) << ", " << formatedNumber(tmp.getPosition().y) << "), Taille : (" << tmp.getSize().x << ", " << tmp.getSize().y << ")" << endl;
            }
            else if (mob == MOmatrix[i][j])
            {
                IGMob tmp(50 * j, this -> getSize().y - (50 * (rows - i)));
                tmp.setTexture(&textureMob);
                IGmatrix.push_back(tmp);
                IGmatrixPostion.push_back(tmp.getPosition());

                //                logFile << "Mob ajouté - Position : (" << formatedNumber(tmp.getPosition().x) << ", " << formatedNumber(tmp.getPosition().y) << "), Taille : (" << tmp.getSize().x << ", " << tmp.getSize().y << ")" << endl;
            }
            else if (drapeau == MOmatrix[i][j])
            {
                IGDrapeau tmp(50 * j, this -> getSize().y - (50 * (rows - i)));
                tmp.setTexture(&textureDrapeau);
                IGmatrix.push_back(tmp);
                IGmatrixPostion.push_back(tmp.getPosition());

                //                logFile << "Drapeau ajouté - Position : (" << formatedNumber(tmp.getPosition().x) << ", " << formatedNumber(tmp.getPosition().y) << "), Taille : (" << tmp.getSize().x << ", " << tmp.getSize().y << ")" << endl;
            }
            else if (mur_invisble == MOmatrix[i][j])
            {
                IGMurInvisible tmp(50 * j, this -> getSize().y - (50 * (rows - i)));
                IGmatrix.push_back(tmp);
                IGmatrixPostion.push_back(tmp.getPosition());

                //                logFile << "Drapeau ajouté - Position : (" << formatedNumber(tmp.getPosition().x) << ", " << formatedNumber(tmp.getPosition().y) << "), Taille : (" << tmp.getSize().x << ", " << tmp.getSize().y << ")" << endl;
            }

        }
    }

    text.setFont(font);
    text.setCharacterSize(20);

}

IGCarte::~IGCarte()
{
    //dtor

    RenderWindow::~RenderWindow();

    logFile.close();
}

void IGCarte::update()
{
    this -> clear(sf::Color::Blue);


    for (sf::RectangleShape x: IGmatrix)
        this -> draw(x);
    this -> draw(player);
    this->draw(exitSprite);

    sf::Vector2i mousePos = sf::Mouse::getPosition(*this);
    if (exitSprite.getGlobalBounds().contains(mousePos.x, mousePos.y))
    {
        this->close();
    }

    _move();

    // TODO : Verifier la mort et la fin de jeux

    text.setString("Nombre de vie : " + std::to_string(mOPlayer.getNumberOfLife()));
    this -> draw(text);
    this -> display();
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
    sf::Vector2f playerFrontPosition = player.getPosition() + sf::Vector2f(player.getGlobalBounds().width+2, 1.0f);
    sf::FloatRect playerFrontBounds(playerFrontPosition, sf::Vector2f(1.0f, 1.0f));

    for (IGRectangleShape &e: IGmatrix)
    {
        sf::FloatRect blockBounds = e.getGlobalBounds();

        // Vérifier s'il y a une collision entre le joueur et la case juste devant lui
        if (playerFrontBounds.intersects(blockBounds))
        {
            return;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        sf::FloatRect playerBounds = player.getGlobalBounds();

        for (const IGRectangleShape & e: IGmatrix)
        {
            sf::FloatRect blockBounds = e.getGlobalBounds();

            // Vérifier s'il y a une collision entre le joueur et la case rouge
            if (playerBounds.intersects(blockBounds))
            {
                actionWhenInteractWithRectange(e);

                // Restaurer la position précédente du joueur
                player.setPosition(e.getPosition().x - playerBounds.width - 1, player.getPosition().y);
                cerr << "Collision avec une case rouge devant !" << endl;
                return; // Ne pas déplacer le joueur s'il y a une collision
            }
        }

        for (sf::RectangleShape & e: IGmatrix)
            e.move(-5.0f, 0.0f);

        cerr << "Avancer !" << endl;
    }
}

void IGCarte::_back()
{
    sf::Vector2f playerBackPosition = player.getPosition() - sf::Vector2f(0.0f, 0.0f); // Décalage d'un pixel vers la gauche pour le côté arrière
    sf::FloatRect playerBackBounds(playerBackPosition, sf::Vector2f(1.0f, player.getGlobalBounds().height)); // Marge de 1 pixel pour la détection

    for (IGRectangleShape & e: IGmatrix)
    {
        sf::FloatRect blockBounds = e.getGlobalBounds();

        if (playerBackBounds.intersects(blockBounds))
        {
            return;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {

        // Vérifier s'il y a une case rouge juste devant le joueur
        //        sf::Vector2f playerPosition = player.getPosition();
        sf::FloatRect playerBounds = player.getGlobalBounds();

        for (const IGRectangleShape & e: IGmatrix)
        {
            sf::FloatRect blockBounds = e.getGlobalBounds();

            // Vérifier s'il y a une collision entre le joueur et la case rouge
            if (playerBounds.intersects(blockBounds))
            {
                actionWhenInteractWithRectange(e);

                player.setPosition(e.getPosition().x + blockBounds.width, player.getPosition().y);
                std::cerr << "Collision avec une case rouge derriere !" << std::endl;
                return; // Ne pas déplacer le joueur s'il y a une collision
            }
        }

        for (sf::RectangleShape & e: IGmatrix)
            e.move(5.0f, 0.0f);


        std::cerr << "Reculer !" << std::endl;
    }
}

void IGCarte::_jump()
{
    // Vérifier si la touche de saut est pressée et le personnage n'est pas déjà en train de sauter
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))) && !isJumping && velocity.y == 0)
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

    sf::FloatRect playerBounds = player.getGlobalBounds();
    for (IGRectangleShape & e: IGmatrix)
    {
        sf::FloatRect blockBounds = e.getGlobalBounds();

        // Vérifier s'il y a une collision entre le joueur et une case rouge
        if (playerBounds.intersects(blockBounds))
        {
            if (velocity.y > 0) // Si le personnage est en train de tomber
            {
                // Ajuster la position du joueur au-dessus de la case
                player.setPosition(player.getPosition().x, blockBounds.top - playerBounds.height);

                // Réinitialiser la vélocité verticale et l'état du saut
                velocity.y = 0;
                isJumping = false;
            }
            else if (velocity.y < 0)   // Si le personnage est en train de monter
            {
                // Ajuster la position du joueur en-dessous de la case
                player.setPosition(player.getPosition().x, blockBounds.top + blockBounds.height);

                // Inverser la direction du mouvement vertical
                velocity.y = 0;
            }

            actionWhenInteractWithRectange(e);
        }
    }

    if (player.getPosition().y > this -> getSize().y + playerBounds.getSize().y)
    {
        die();
    }
}

// TODO Cree une fonction pour verifier si on touche une couleur sa fait quoi

void IGCarte::actionWhenInteractWithRectange(IGRectangleShape e)
{

    if (e.TypeBlock() == "Mob")
    {
        die();
    }
    else if (e.TypeBlock() == "Drapeau")
    {
        succes();
    }
}

void IGCarte::die()
{
    mOPlayer.Die();
    reset();
    if (mOPlayer.isGameOver())
        this -> close();
}
void IGCarte::succes()
{
    this -> close();
}

void IGCarte::reset()
{
    int taille = IGmatrix.size();
    for (int i = 0; i < taille; i++)
        IGmatrix[i].setPosition(IGmatrixPostion[i]);

    player.setPosition(200, 450);

}

// Pour la console
string IGCarte::formatedNumber(int number)
{
    std::ostringstream oss;
    oss << std::setw(4) << std::setfill('0') << number;
    return oss.str();
}

