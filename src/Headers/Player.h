#ifndef PLAYER_H
#define PLAYER_H

#include "../Headers.h"

class Player
{
  private:
    sf::Texture texture;
    sf::Sprite sprite;

    // Physics
    sf::Vector2f acceleration;
    float accelerationSpeed;

    // Initializers
    void initTexture();
    void initSprite();
    void initPhysics();

  public:
    // Constructor and Destructor
    Player();
    virtual ~Player();

    // Functions
    void updateMovement();
    void updatePhysics();
    void update();
    void render(sf::RenderTarget& target);
};

#endif // PLAYER_H
