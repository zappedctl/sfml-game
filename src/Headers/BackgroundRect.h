#ifndef BACKGROUNDRECT_H
#define BACKGROUNDRECT_H

#include "../Headers.h"

class BackgroundRect
{
  private:
    int width;
    int height;
    sf::Texture* texture;
    sf::RectangleShape shape;

    // Initializers
    void initShape();

  public:
    // Constructor and Destructor
    BackgroundRect(const int width, const int height, sf::Texture* texture);
    virtual ~BackgroundRect();
    
    // Functions
    void render(sf::RenderTarget& target);
};

#endif // BACKGROUNDRECT_H
