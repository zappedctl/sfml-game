#ifndef BLOCK_H
#define BLOCK_H

#include "../Headers.h"

class Block
{
  private:
    sf::Texture* texture;
    sf::Sprite sprite;

  public:
    // Constructor and Destructor
    Block();
    virtual ~Block();
};

#endif // BLOCK_H
