#ifndef BALL_H
#define BALL_H

//#include "../libs/include/SFML/Graphics.hpp"
#include <SFML/Graphics.hpp>
#include "../libs/include/Box2d/box2d.h"
#include "constants.h"

class Ball : public sf::Drawable {
public:
    Ball(b2World& world);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::Texture texture; 
    mutable sf::Sprite sprite; 
    b2Body* body;
};

#endif
