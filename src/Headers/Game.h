#ifndef GAME_H
#define GAME_H

#include "../Headers.h"
#include "Player.h"
#include "BackgroundRect.h"

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

    std::vector<BackgroundRect*> backgroundRects;

    // Initializers
    void initWindow();
    void initBackgroundRects();

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
    void renderPlayer();
    void render();
    
    // Functions
    void run();
};

#endif // GAME_H
