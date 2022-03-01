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
    float speed;

    // Initializers
    void initTexture();
    void initSprite();
    void initPhysics();

  public:
    // Constructor and Destructor
    Player();
    virtual ~Player();

    // Accessors
    const sf::Vector2f getPos() const;

    // UpdateFunctions
    void updateMovement();
    void updatePhysics();
    void update();

    // Functions
    void render(sf::RenderTarget& target);
};

#endif // PLAYER_H
