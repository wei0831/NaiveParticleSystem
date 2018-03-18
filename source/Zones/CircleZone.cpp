/******************************************************************************/
/*!
\file   CircleZone.cpp
\author Jack Chang
\date   08/03/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
    Circular zone for particles.
    Provide generation of random position within the zone and random direction.
*/
/******************************************************************************/
#include "CircleZone.h"
#include "Utility.h"

/******************************************************************************/
// Default Constructor
/******************************************************************************/
CircleZone::CircleZone(sf::Vector2f pos, sf::Vector2f dir, float radius)
: mPosition(pos), mDirection(dir), mRadius(radius)
{

}

/******************************************************************************/
// Generate Random Position
/******************************************************************************/
sf::Vector2f CircleZone::getRandomPos()
{
    sf::Vector2f randPos = mPosition;

    // from Rad(0) ~ Rad(2* PI)
    randPos.x += cosf(Utility::Randomf(0.0f, 6.28f)) * mRadius;
    randPos.y += sinf(Utility::Randomf(0.0f, 6.28f)) * mRadius;

    return randPos;
}

/******************************************************************************/
// Generate Random Direction
/******************************************************************************/
sf::Vector2f CircleZone::getRandomDir()
{
    // This zone does not generate random direction
    return mDirection;
}
