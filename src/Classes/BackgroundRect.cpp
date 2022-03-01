#include "../Headers/BackgroundRect.h"

void BackgroundRect::initShape()
{
  this->shape.setTexture(this->texture);
  this->shape.setSize(sf::Vector2f(this->width, this->height));
  this->shape.setTextureRect(sf::IntRect(0, 0, this->width, this->height));
}

// Constructor and Destructor

BackgroundRect::BackgroundRect(const int width, const int height, sf::Texture* texture)
{
  this->width = width;
  this->height = height;
  this->texture = texture;
  this->initShape();
}

BackgroundRect::~BackgroundRect()
{

}

// Functions

void BackgroundRect::render(sf::RenderTarget& target)
{
  target.draw(this->shape);
}
