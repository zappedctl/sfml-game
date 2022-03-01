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
  this->speed = 96.f;
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
    this->acceleration.y = -1;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
  {
    this->acceleration.y = 1;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
  {
    this->acceleration.x = -1;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
  {
    this->acceleration.x = 1;
  }
}

void Player::updatePhysics()
{
  // Fixing diagonal movement causing faster speeds
  if (std::abs(this->acceleration.x) == 1 && std::abs(this->acceleration.y) == 1) {
    this->acceleration.x = 1 / (float)sqrt(2) * (this->acceleration.x > 0 ? 1 : -1);
    this->acceleration.y = 1 / (float)sqrt(2) * (this->acceleration.y > 0 ? 1 : -1);
  }    

  this->sprite.move(this->acceleration * this->speed * game.getDt());
  this->acceleration *= 0.f;
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
