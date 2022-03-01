#ifndef BACKGROUNDRECT_H
#define BACKGROUNDRECT_H

#include "../Headers.h"

class BackgroundRect
{
  private:
    sf::Sprite* sprite;

  public:
    // Constructor and Destructor
    BackgroundRect(std::string texturePath);
    virtual ~BackgroundRect();
    
    // Functions
    void render(sf::RenderTarget& target);
};

#endif // BACKGROUNDRECT_H
