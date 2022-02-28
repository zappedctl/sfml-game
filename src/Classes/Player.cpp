#include "../Headers/Player.h"

// Initializers

void Player::initTexture()
{
  if (!this->texture.loadFromFile("src/Textures/player.png"))
  {
    std::cout << "PLAYER::ERROR::CANT_LOAD_PLAYER_TEXTURE" << std::endl;
  }
}

void Player::initSprite()
{
  this->sprite.setTexture(this->texture);
}

// Constructor and Destructor

Player::Player()
{
  this->initTexture();
  this->initSprite();
}

Player::~Player()
{

}

// Functions

void Player::update()
{

}

void Player::render(sf::RenderTarget &target)
{
  target.draw(this->sprite);
}
