#include "paddle.h"

Paddle::Paddle(b2World& world) {
  // Set up the SFML shape for the paddle
  shape.setSize(sf::Vector2f(100.0f, 20.0f)); // Example size
  shape.setFillColor(sf::Color::Blue); // Example color
  shape.setOrigin(50.0f, 10.0f); // Set origin to the center for proper rotation

  // Set up the Box2D body definition
  b2BodyDef bodyDef;
  bodyDef.type = b2_kinematicBody; // Kinematic bodies are not affected by forces but can be moved manually
  float posX = 400.0f; // Example X position
  float posY = 580.0f; // Example Y position
  bodyDef.position.Set(posX / SCALE, posY / SCALE); // Convert to Box2D world units using a scale factor

  // Create the Box2D body in the world
  body = world.CreateBody(&bodyDef);

  // Define the shape of the physical body
  b2PolygonShape boxShape;
  boxShape.SetAsBox((100.0f / 2) / SCALE, (20.0f / 2) / SCALE); // Half-width and half-height in Box2D units

  b2FixtureDef fixtureDef;
  fixtureDef.shape = &boxShape; 
  fixtureDef.filter.categoryBits = CATEGORY_PADDLE;
  fixtureDef.filter.maskBits = CATEGORY_BALL;

  // Create the fixture on the body
  body->CreateFixture(&fixtureDef); // Density of 0.0f for kinematic bodies
}
  

b2Body* Paddle::getBody() const {
  return body;
}

void Paddle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Update the position and rotation of the SFML shape from the Box2D body
    const b2Vec2& pos = body->GetPosition();
    shape.setPosition(pos.x * SCALE, pos.y * SCALE); // Convert back from Box2D world units
    shape.setRotation(body->GetAngle() * 180.0f / b2_pi); // Convert radians to degrees

    // Draw the shape
    target.draw(shape, states);
}