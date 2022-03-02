#ifndef BLOCK_H
#define BLOCK_H

#include "../Headers.h"

class Block
{
  private:
    sf::Texture* texture;
    sf::Sprite sprite;

    // Initializers
    void initSprite(const int x, const int y);

  public:
    // Constructor and Destructor
    Block(const int x, const int y, sf::Texture* texture);
    virtual ~Block();

    // Functions
    void render(sf::RenderTarget& target);
};

#endif // BLOCK_H
