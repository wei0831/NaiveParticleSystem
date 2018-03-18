/******************************************************************************/
/*!
\file   CircleZone.h
\author Jack Chang
\date   08/03/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
    A zone for particles.
    Provide generation of random position within the zone and random direction.
*/
/******************************************************************************/
#ifndef CIRCLE_ZONE
#define CIRCLE_ZONE

#include "SFML/Graphics.hpp"
#include "Zone.h"

class CircleZone : public Zone
{
    /*--------------------------------------------------------------------------
    // Public Functions
    --------------------------------------------------------------------------*/
public:
    CircleZone(sf::Vector2f pos, sf::Vector2f dir, float width);
    sf::Vector2f getRandomPos();
    sf::Vector2f getRandomDir();

    /*--------------------------------------------------------------------------
    // Private Variables
    --------------------------------------------------------------------------*/
private:
    sf::Vector2f mPosition;
    sf::Vector2f mDirection;
    float mRadius;
};

#endif
