#ifndef CIRCLE_ZONE
#define CIRCLE_ZONE

#include "SFML/Graphics.hpp"
#include "Zone.h"

class CircleZone : public Zone
{
public:
    CircleZone(sf::Vector2f pos, sf::Vector2f dir, float width);
    sf::Vector2f getRandomPos();
    sf::Vector2f getRandomDir();

private:
    sf::Vector2f mPosition;
    sf::Vector2f mDirection;
    float mRadius;
};

#endif
