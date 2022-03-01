#include "../Headers/BackgroundRect.h"

void BackgroundRect::initSprite()
{
  this->sprite.setTexture(*this->texture);
}

// Constructor and Destructor

BackgroundRect::BackgroundRect(sf::Texture* texture)
{
  this->texture = texture;
  this->initSprite();
}

BackgroundRect::~BackgroundRect()
{

}

// Functions

void BackgroundRect::render(sf::RenderTarget& target)
{
  target.draw(this->sprite);
}
