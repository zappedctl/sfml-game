#include "../Headers/Game.h"

// Initializers

void Game::initWindow()
{
  this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML");
  this->window->setFramerateLimit(60);
}

// Constructor and Destructor

Game::Game()
{
  this->initWindow();
}

Game::~Game()
{
  delete this->window;
}

// Accessors

const float Game::getDt() const
{
  return this->dt;
}

// Update Functions

void Game::updateSFMLEvents()
{
  while (this->window->pollEvent(this->sfEvent))
  {
    switch (this->sfEvent.type)
    {
      case sf::Event::Closed:
        this->window->close();
        break;

      case sf::Event::Resized: {
        this->updateView();
      }

      default:
        break;
    }
  }
}

void Game::updateDt()
{
  this->dt = this->dtClock.restart().asSeconds();
}

void Game::updatePlayer()
{
  this->player.update();
}

void Game::updateView()
{
  sf::FloatRect visibleArea(this->player.getPos().x, this->player.getPos().y, this->window->getSize().x, this->window->getSize().y);
  this->window->setView(sf::View(visibleArea));
}

void Game::update()
{
  this->updateSFMLEvents();
  this->updateDt();
  this->updatePlayer();
  this->updateView();
}

// Render Functions

void Game::renderPlayer()
{
  this->player.render(*this->window);
}

void Game::render()
{
  this->window->clear();
  this->renderPlayer();
  this->window->display();
}

// Functions

void Game::run()
{
  while (this->window->isOpen())
  {
    this->update();
    this->render();
  }
}
