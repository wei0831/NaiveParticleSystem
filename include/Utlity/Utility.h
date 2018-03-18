/******************************************************************************/
/*!
\file   Utility.h
\author Jack Chang
\date   08/01/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
    Simple temporary utility class
*/
/******************************************************************************/
#ifndef UTILITY_H
#define UTILITY_H

#define PI 3.1415926535897932384626433832795

#include "SFML/Graphics.hpp"
#include <cmath>

namespace Utility
{
    /*--------------------------------------------------------------------------
    // Public Functions
    --------------------------------------------------------------------------*/
    float Vector2DLength(sf::Vector2f& pVec0);
    float Vector2DSquareLength(sf::Vector2f& pVec0);
    void Vector2DNormalize(sf::Vector2f& vec);
    void Vector2DPerp(sf::Vector2f& vec);
    void Vector2DFromAngleDeg(sf::Vector2f& vec, float angle);
    void Vector2DFromAngleRad(sf::Vector2f& vec, float angle);
    float AngleDegToRad(float angle);
    float AngleRadToDeg(float angle);
    float Randomf(float min, float max);
}

#endif