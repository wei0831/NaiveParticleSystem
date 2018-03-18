/******************************************************************************/
/*!
\file   Paritcle.h
\author Jack Chang
\date   08/02/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
        Single particle. Nothing Special.
*/
/******************************************************************************/
#ifndef PARTICLE_H
#define PARTICLE_H

#include "SFML/Graphics.hpp"

class Particle
{
    /*--------------------------------------------------------------------------
    // Public Variables
    --------------------------------------------------------------------------*/
public:
    sf::Vector2f mPosition;
    sf::Vector2f mDirection;
    float        mSpeed;
    sf::Vector2f mScale;
    sf::Color    mColor;
    float        mOrientation;
    float        mRotationAngle;
    float        mRotationSpeed;

    sf::Texture* mTexture;
    float        mDuration;
    float        mPercentLife;

    /*--------------------------------------------------------------------------
    // Public Functions
    --------------------------------------------------------------------------*/
public:
    Particle();

};

#endif
