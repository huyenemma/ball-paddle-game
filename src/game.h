#ifndef GAME_H
#define GAME_H

//#include "../libs/include/SFML/Graphics.hpp"
#include <SFML/Graphics.hpp>
#include "../libs/include/Box2d/box2d.h"
#include "paddle.h"
#include "ball.h"

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    void handlePaddleInput(); 

    sf::RenderWindow window;
    b2World world;
    Paddle paddle;
    Ball ball;  
};

#endif