#ifndef ENTITY_H
#define ENTITY_H

#include "../../Headers.h"

class Entity
{
  public:
    // Constructor and Destructor
    Entity();
    virtual ~Entity();

    // Functions
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget& target) = 0;
};

#endif // ENTITY_H
