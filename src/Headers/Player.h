#ifndef PLAYER_H
#define PLAYER_H

#include "../Headers.h"

class Player
{
  private:
    sf::Texture texture;
    sf::Sprite sprite;

    // Initializers
    void initTexture();
    void initSprite();

  public:
    // Constructor and Destructor
    Player();
    virtual ~Player();

    // Functions
    void update();
    void render(sf::RenderTarget& target);
};

#endif // PLAYER_H
