#include "Headers/Game.h"

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>

Game::Game() : window(sf::VideoMode(1280, 720), "Orbiters")
{
    player.setRadius(15.f);
    player.setOutlineColor(sf::Color::White);
}

void Game::update()
{
    sf::Vector2f movement(0.f, 0.f);
    if (movingUp) 
        player.getPosition().y+1 < 0.f ? 
            movement.y = 1.f : movement.y -= 0.05f; 
              
    if (movingDown) 
        player.getPosition().y > 689.f ? 
            movement.y -= 0.05f : movement.y += 0.05f;
        
    if (movingLeft)
        player.getPosition().x+1 < 0.f ? 
            movement.x = 1.f : movement.x -= 0.05f;

    if (movingRight)
        player.getPosition().x > 1249.f ? 
            movement.x -= 0.05f : movement.x += 0.05f;

    player.move(movement);
}

void Game::render()
{
    window.clear();
    window.draw(player);
    window.display();
}

void Game::run() 
{
    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event))
        {
            switch(event.type) 
            {
                case sf::Event::KeyPressed: 
                    handlePlayerInput(event.key.code, true); 
                    break;
                case sf::Event::KeyReleased:
                    handlePlayerInput(event.key.code, false); 
                    break;
                case sf::Event::Closed: 
                    window.close(); 
                    break;
            }
        }

        update();
        render();
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key pKey, bool pIsPressed)
{
    switch(pKey)
    {
        case sf::Keyboard::W:
            movingUp = pIsPressed;
            break;
        case sf::Keyboard::S:
            movingDown = pIsPressed;
            break;
        case sf::Keyboard::A:
            movingLeft = pIsPressed;
            break;
        case sf::Keyboard::D:
            movingRight = pIsPressed;
            break;
        default:
            break;
    }
}