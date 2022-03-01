#include "../Headers/Game.h"

// Initializers

void Game::initWindow()
{
  this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML");
  this->window->setFramerateLimit(60);
}

sf::Texture* loadTexture(std::string path)
{
  sf::Texture* texture = new sf::Texture();
  texture->loadFromFile(path);
  texture->setRepeated(true);

  return texture;
}

void Game::initBackgroundTextures()
{
  sf::Texture* grassTexture = loadTexture("src/Textures/grass.png");
  this->backgroundTextures.push_back(grassTexture);
}

void Game::initBackgroundRects()
{
  BackgroundRect grassBackgroundRect(640, 320, this->backgroundTextures[0]);

  this->backgroundRects.push_back(grassBackgroundRect);
}

// Constructor and Destructor

Game::Game()
{
  this->initWindow();
  this->initBackgroundTextures();
  this->initBackgroundRects();
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
  sf::FloatRect visibleArea(
    this->player.getPos().x - this->window->getSize().x / 2 + 16,
    this->player.getPos().y - this->window->getSize().y / 2 + 16,
    this->window->getSize().x,
    this->window->getSize().y
  );

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

void Game::renderBackgroundRects()
{
  for (int i = 0; i < this->backgroundRects.size(); i++)
  {
    this->backgroundRects[i].render(*this->window);
  }
}

void Game::renderPlayer()
{
  this->player.render(*this->window);
}

void Game::render()
{
  this->window->clear();
  this->renderBackgroundRects();
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
