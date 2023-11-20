#include "Interface/IGCarte.h"

IGCarte::IGCarte(sf::RenderWindow &window, MOPlayer &mOPlayer, vector<vector<char>> matrix) : window(window), MOmatrix(matrix)
{
    this->mOPlayer = mOPlayer;

    // Create a font
    if (!font.loadFromFile("files/SuperMario256.ttf"))
    {
        cout << EXIT_FAILURE << endl;
    }

    // Create a point to represent the character
    player.setRadius(20);
    player.setFillColor(sf::Color::Blue);
    player.setPosition(200, 450);

    gravity = sf::Vector2f(0.0f, 0.5f);
    velocity = sf::Vector2f(0.0f, 0.0f);

    logFile = std::ofstream("log.txt", std::ios::trunc);

    // Date et heure actuel
    auto currentTime = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(currentTime);
    string timeString = std::ctime(&time);

    string texte = "==================== " + timeString + " ===================="; // Le texte de debut de fichier
    texte.erase(std::remove_if(texte.begin(), texte.end(), [](char c)
    {
        return c == '\n';
    }), texte.end()); // Supprime un retour a la ligne

    logFile << texte << endl ;
    int rows = MOmatrix.size();
    int cols = MOmatrix[0].size();

    int i,j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if(sol==MOmatrix[i][j])
            {
                IGSol tmp(50 * j, window.getSize().y - (50 * (rows-i)));
                IGmatrix.push_back(tmp);
                IGmatrixPostion.push_back(tmp.getPosition());

                logFile << "Bloc vert ajouté - Position : (" << formatedNumber(tmp.getPosition().x) << ", " << formatedNumber(tmp.getPosition().y) << "), Taille : (" << tmp.getSize().x << ", " << tmp.getSize().y << ")" << endl;
            }
            else if(mur == MOmatrix[i][j])
            {
                sf::RectangleShape tmp(sf::Vector2f(50, 50));
                tmp.setFillColor(sf::Color::Yellow);
                tmp.setPosition(tmp.getSize().y * j,window.getSize().y - (tmp.getSize().y * (rows-i)));
                IGmatrix.push_back(tmp);
                IGmatrixPostion.push_back(tmp.getPosition());
                logFile << "Bloc rouge ajouté - Position : (" << formatedNumber(tmp.getPosition().x) << ", " << formatedNumber(tmp.getPosition().y) << "), Taille : (" << tmp.getSize().x << ", " << tmp.getSize().y << ")" << endl;
            }
            else if(mob==MOmatrix[i][j])
            {
                sf::RectangleShape tmp(sf::Vector2f(50, 50)); // TODO : mettre un rond pour plus de comprehension
                tmp.setFillColor(sf::Color::Red);
                tmp.setPosition(tmp.getSize().y * j,window.getSize().y - (tmp.getSize().y * (rows-i)));
                IGmatrix.push_back(tmp);
                IGmatrixPostion.push_back(tmp.getPosition());
            }
            else if(drapeau==MOmatrix[i][j])
            {
                sf::RectangleShape tmp(sf::Vector2f(50, 50));
                tmp.setFillColor(sf::Color::Blue);
                tmp.setPosition(tmp.getSize().y * j,window.getSize().y - (tmp.getSize().y * (rows-i)));
                IGmatrix.push_back(tmp);
                IGmatrixPostion.push_back(tmp.getPosition());
            }

        }
    }


    text.setFont(font);
    text.setCharacterSize(20);

}

IGCarte::~IGCarte()
{
    //dtor

    logFile.close();
}

void IGCarte::update()
{
    window.clear(sf::Color::Black);

//    window.draw(MapNow);
    for(sf::RectangleShape x :IGmatrix)
        window.draw(x);
    window.draw(player);

    _move();

    // TODO : Verifier la mort et la fin de jeux

    text.setString("Nombre de vie : "+ std::to_string(mOPlayer.getNumberOfLife()));
    window.draw(text);


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
        // Vérifier s'il y a une case rouge juste devant le joueur
//        sf::Vector2f playerPosition = player.getPosition();
        sf::FloatRect playerBounds = player.getGlobalBounds();

        for (const sf::RectangleShape &e : IGmatrix)
        {
            sf::FloatRect blockBounds = e.getGlobalBounds();

            // Vérifier s'il y a une collision entre le joueur et la case rouge
            if (playerBounds.intersects(blockBounds))
            {

                actionWhenInteractWithRectange(e);

                player.setPosition(e.getPosition().x - playerBounds.width - 1, player.getPosition().y);
                cerr << "Collision avec une case rouge devant !" << endl;
                return; // Ne pas déplacer le joueur s'il y a une collision
            }
        }

        for(sf::RectangleShape &e :IGmatrix)
            e.move(-5.0f, 0.0f);

        cerr << "Avancer !" << endl;
    }
}

void IGCarte::_back()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {

        // Vérifier s'il y a une case rouge juste devant le joueur
//        sf::Vector2f playerPosition = player.getPosition();
        sf::FloatRect playerBounds = player.getGlobalBounds();

        for (const sf::RectangleShape &e : IGmatrix)
        {
            sf::FloatRect blockBounds = e.getGlobalBounds();

            // Vérifier s'il y a une collision entre le joueur et la case rouge
            if (playerBounds.intersects(blockBounds))
            {
                actionWhenInteractWithRectange(e);

                player.setPosition(e.getPosition().x + blockBounds.width + 1, player.getPosition().y);
                std::cerr << "Collision avec une case rouge derriere !" << std::endl;
                return; // Ne pas déplacer le joueur s'il y a une collision
            }
        }

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

    sf::FloatRect playerBounds = player.getGlobalBounds();
    for (sf::RectangleShape &e : IGmatrix)
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
            else if (velocity.y < 0) // Si le personnage est en train de monter
            {
                // Ajuster la position du joueur en-dessous de la case
                player.setPosition(player.getPosition().x, blockBounds.top + blockBounds.height);

                // Inverser la direction du mouvement vertical
                velocity.y = 0;
            }

            actionWhenInteractWithRectange(e);
        }
    }

    if (player.getPosition().y > window.getSize().y + playerBounds.getSize().y)
    {
        die();
    }
}

// TODO Cree une fonction pour verifier si on touche une couleur sa fait quoi


void IGCarte::actionWhenInteractWithRectange(sf::RectangleShape e)
{

    if(e.getFillColor()==sf::Color::Red)  // TODO : gerer la mort par un mob
    {
        die();
    }

    else if(e.getFillColor()==sf::Color::Blue)  // TODO : gerer la reussite
    {
        succes();
    }
}

void IGCarte::die()
{
    mOPlayer.Die();
    reset();
//        window.close();
}
void IGCarte::succes()
{
    window.close();
}


void IGCarte::reset()
{

    int taille = IGmatrix.size();
    for(int i = 0 ; i< taille; i++)
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
