#include "../Headers/Block.h"

void Block::initSprite(const int x, const int y)
{
  this->sprite.setTexture(*this->texture);
  this->sprite.setPosition(sf::Vector2f(x, y));
}

// Constructor and Destructor

Block::Block(const int x, const int y, sf::Texture* texture)
{
  this->texture = texture;
  this->initSprite(x, y);
}

Block::~Block()
{

}

// Functions

void Block::render(sf::RenderTarget& target)
{
  target.draw(this->sprite); 
}
