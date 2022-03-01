#include "../Headers/BackgroundRect.h"

// Constructor and Destructor

BackgroundRect::BackgroundRect(std::string texturePath)
{
  sf::Texture texture;
  if(!texture.loadFromFile(texturePath))
  {
    std::cout << "BACKGROUNDRECT::ERROR::CANT_LOAD_TEXTURE" << std::endl;
  }

  this->sprite = new sf::Sprite();
  sprite->setTexture(texture);
}

BackgroundRect::~BackgroundRect()
{
  delete this->sprite;
}

// Functions

void BackgroundRect::render(sf::RenderTarget& target)
{
  target.draw(*this->sprite);
}
