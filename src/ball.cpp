#include "ball.h"

Ball::Ball(b2World& world) {
  // Set up the SFML shape for the ball
  texture.loadFromFile("../img/ball.jpg");
  sprite.setTexture(texture);

  // Calculate the scale factor
  float desiredRadius = 15.0f; // The desired radius in your game's world
  float originalRadius = texture.getSize().x / 2.0f; // Assuming the ball image is a circle
  float scaleFactor = desiredRadius / originalRadius;

    // Set the scale of the sprite
  sprite.setScale(scaleFactor, scaleFactor);

  // Set up the Box2D body definition
  b2BodyDef bodyDef;
  bodyDef.type = b2_dynamicBody; // Dynamic body to respond to forces and collisions
  float posX = 400.0f; // Example X position
  float posY = 300.0f; // Example Y position
  bodyDef.position.Set(posX / SCALE, posY / SCALE); // Convert to Box2D world units using a scale factor

  // Create the Box2D body in the world
  body = world.CreateBody(&bodyDef);

  // Define the shape of the physical body
  b2CircleShape circleShape;
  circleShape.m_radius = 15.0f / SCALE; // Radius in Box2D units

  // Create the fixture on the body
  b2FixtureDef fixtureDef;
  fixtureDef.shape = &circleShape;
  fixtureDef.density = 1.0f; // Density for mass calculation
  fixtureDef.friction = 0.3f; // Friction coefficient
  fixtureDef.restitution = 0.6f; // Bounciness

  fixtureDef.filter.categoryBits = CATEGORY_BALL;
  fixtureDef.filter.maskBits = CATEGORY_PADDLE | CATEGORY_WALLS; 

  body->CreateFixture(&fixtureDef);

}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Update the position of the SFML shape from the Box2D body
    const b2Vec2& pos = body->GetPosition();
    float posX = pos.x * SCALE; // Convert back from Box2D world units
    float posY = pos.y * SCALE;
    sprite.setPosition(posX, posY); 

    // Draw the shape
    target.draw(sprite, states);
}
