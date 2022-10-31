#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.hpp>

class Game
{
    public:
        Game();
        void run();
        void render();
        void update();
        void handlePlayerInput(sf::Keyboard::Key pKey, bool pIsPressed);
    private:
        sf::RenderWindow window;
        sf::CircleShape player;
        bool movingLeft = false, movingUp = false, movingRight = false, movingDown = false;
};

#endif