#include "../Headers/Player.h"
#include "../Headers/Game.h"

extern Game game;

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

void Player::initPhysics()
{
  this->accelerationSpeed = 12.f;
}

// Constructor and Destructor

Player::Player()
{
  this->initTexture();
  this->initSprite();
  this->initPhysics();
}

Player::~Player()
{

}

// Functions

void Player::updateMovement()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
  {
    this->acceleration.y -= this->accelerationSpeed * game.getDt();
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
  {
    this->acceleration.y += this->accelerationSpeed * game.getDt();
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
  {
    this->acceleration.x -= this->accelerationSpeed * game.getDt();
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
  {
    this->acceleration.x += this->accelerationSpeed * game.getDt();
  }
}

void Player::updatePhysics()
{
  this->sprite.move(this->acceleration);
  std::cout << this->acceleration.y << std::endl;
}

void Player::update()
{
  this->updateMovement();
  this->updatePhysics();
}

void Player::render(sf::RenderTarget &target)
{
  target.draw(this->sprite);
}
