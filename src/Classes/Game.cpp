#include "../Headers/Game.h"

// Initializers

void Game::initWindow()
{
  std::ifstream ifs("src/Config/window.ini");

  std::string title = "Game";
  sf::VideoMode windowBounds(800, 600);
  unsigned int windowFPSLimit = 60;
  bool windowVSyncEnabled = false;

  if (ifs.is_open())
  {
    std::getline(ifs, title);
    ifs >> windowBounds.width >> windowBounds.height;
    ifs >> windowFPSLimit;
    ifs >> windowVSyncEnabled;
  }

  this->window = new sf::RenderWindow(windowBounds, title);
  this->window->setFramerateLimit(windowFPSLimit);
  this->window->setVerticalSyncEnabled(windowVSyncEnabled);
}

sf::Texture* loadTexture(std::string path)
{
  sf::Texture* texture = new sf::Texture();
  if(!texture->loadFromFile(path))
  {
    std::cout << "GAME::ERROR::CANT_LOAD_TEXTURE: " << path << std::endl;
  }

  texture->setRepeated(true);
  return texture;
}

void Game::initTextures()
{
  this->textures.push_back(loadTexture("src/Textures/stone.png"));
}

void Game::initBackgroundTextures()
{
  this->backgroundTextures.push_back(loadTexture("src/Textures/grass.png"));
}

void Game::initBackgroundRects()
{
  this->backgroundRects.push_back(BackgroundRect(640, 320, this->backgroundTextures[0]));
}

void Game::initBlocks()
{
  this->blocks.push_back(Block(0, 0, this->textures[0]));
}

// Constructor and Destructor

Game::Game()
{
  this->initWindow();
  this->initTextures();
  this->initBackgroundTextures();
  this->initBackgroundRects();
  this->initBlocks();
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

void Game::renderBlocks()
{
  for (int i = 0; i < this->blocks.size(); i++)
  {
    this->blocks[i].render(*this->window);
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
  this->renderBlocks();
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
