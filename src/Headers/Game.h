#ifndef GAME_H
#define GAME_H

#include "../Headers.h"
#include "Player.h"
#include "BackgroundRect.h"
#include "Block.h"

class Player;

class Game
{
  private:
    sf::RenderWindow* window;
    sf::Event sfEvent;

    Player player;

    // Delta Time
    sf::Clock dtClock;
    float dt;

    std::vector<sf::Texture*> textures;
    std::vector<sf::Texture*> backgroundTextures;
    std::vector<BackgroundRect> backgroundRects;
    std::vector<Block> blocks;

    // Initializers
    void initWindow();
    void initTextures();
    void initBackgroundTextures();
    void initBackgroundRects();
    void initBlocks();

  public:
    // Constructor and Destructor
    Game();
    virtual ~Game();

    // Accessors
    const float getDt() const;

    // Update Functions
    void updateSFMLEvents();
    void updateDt();
    void updatePlayer();
    void updateView();
    void update();

    // Render Functions
    void renderBackgroundRects();
    void renderBlocks();
    void renderPlayer();
    void render();
    
    // Functions
    void run();
};

#endif // GAME_H
