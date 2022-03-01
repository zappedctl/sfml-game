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
  this->accelarationSpeed = 128.f;
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
    this->accelaration.y -= this->accelarationSpeed;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
  {
    this->accelaration.y += this->accelarationSpeed;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
  {
    this->accelaration.x -= this->accelarationSpeed;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
  {
    this->accelaration.x += this->accelarationSpeed;
  }
}

void Player::updatePhysics()
{
  this->accelaration *= game.getDt();
  this->sprite.move(this->accelaration);
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
