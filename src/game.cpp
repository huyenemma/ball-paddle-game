#include "game.h"

Game::Game() : window(sf::VideoMode(800, 600), "Ball and Paddle Game"),
               world(b2Vec2(0.f, 9.8f)),
               paddle(world),
               ball(world) { // No gravity in a top-down view
    // Initialize paddle and ball
}

void Game::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::handlePaddleInput() {
    const float paddleSpeed = 10.0f; // Adjust the speed as needed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        // Move paddle left
        paddle.getBody()->SetLinearVelocity(b2Vec2(-paddleSpeed, 0));
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        // Move paddle right
        paddle.getBody()->SetLinearVelocity(b2Vec2(paddleSpeed, 0));
    } else {
        // Stop the paddle when no key is pressed
        paddle.getBody()->SetLinearVelocity(b2Vec2(0, 0));
    }
}

void Game::update(sf::Time deltaTime) {
    // Update paddle and ball positions
    handlePaddleInput();
    world.Step(deltaTime.asSeconds(), 8, 3);
}

void Game::render() {
    window.clear();
    window.draw(paddle);
    window.draw(ball);
    window.display();
}
