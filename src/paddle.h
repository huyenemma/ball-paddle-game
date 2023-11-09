#ifndef PADDLE_H
#define PADDLE_H

//#include "../libs/include/SFML/Graphics.hpp"
#include <SFML/Graphics.hpp>
#include "../libs/include/Box2d/box2d.h"
#include "constants.h"

class Paddle : public sf::Drawable {
public:
    Paddle(b2World& world);
    b2Body* getBody() const; 
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    mutable sf::RectangleShape shape;
    b2Body* body;
};

#endif
