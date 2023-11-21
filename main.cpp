#include <SFML/Graphics.hpp>

#include <Interface/IGCarte.h>
#include <MOMap.h> // A Supp

int main()
{
    MOMap moMap;
    MOPlayer mOPlayer;

    IGCarte igCarte(mOPlayer, moMap.Niveau(-1)); // -1 = Map test
    igCarte.setActive(true);


    while (igCarte.isOpen())
    {
        sf::Event event;
        while (igCarte.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                igCarte.close();
            }
        }

        igCarte.update();

    }

    return 0;
}

