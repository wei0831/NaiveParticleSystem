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
#include "Particle.h"

/******************************************************************************/
// Default Constructor
/******************************************************************************/
Particle::Particle()
: mScale(1.0f, 1.0f), mPercentLife(1.0f)
{
    mRotationSpeed = 0.0f;
    mRotationAngle = 0.0f;
}
