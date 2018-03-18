/******************************************************************************/
/*!
\file   PointDirZone.cpp
\author Jack Chang
\date   08/03/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
    A zone for particles. 
    Provide generation of random position within the zone and random direction.
*/
/******************************************************************************/
#include "PointDirZone.h"
#include "Utility.h"

/******************************************************************************/
// Default Constructor
/******************************************************************************/
PointDirZone::PointDirZone(sf::Vector2f pos, sf::Vector2f dir, float width)
: mPosition(pos), mDirection(dir), mWidth(width)
{
    mPerpDirection = mDirection;
    Utility::Vector2DNormalize(mPerpDirection);
    Utility::Vector2DPerp(mPerpDirection);
}

/******************************************************************************/
// Generate Random Position
/******************************************************************************/
sf::Vector2f PointDirZone::getRandomPos()
{
    sf::Vector2f randPos = mPosition;
    
    randPos += Utility::Randomf(-mWidth * 0.5f, mWidth * 0.5f) * mPerpDirection;

    return randPos;
}

/******************************************************************************/
// Generate Random Direction
/******************************************************************************/
sf::Vector2f PointDirZone::getRandomDir()
{
    // This zone does not generate random direction
    return mDirection;
}