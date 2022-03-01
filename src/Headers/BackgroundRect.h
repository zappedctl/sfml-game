#ifndef BACKGROUNDRECT_H
#define BACKGROUNDRECT_H

#include "../Headers.h"

class BackgroundRect
{
  private:
    sf::Texture* texture;
    sf::Sprite sprite;

    // Initializers
    void initSprite();

  public:
    // Constructor and Destructor
    BackgroundRect(sf::Texture* texture);
    virtual ~BackgroundRect();
    
    // Functions
    void render(sf::RenderTarget& target);
};

#endif // BACKGROUNDRECT_H
