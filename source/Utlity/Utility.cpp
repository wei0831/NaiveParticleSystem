/******************************************************************************/
/*!
\file   Utility.cpp
\author Jack Chang
\date   08/03/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
    Simple temporary utility class
*/
/******************************************************************************/
#include "Utility.h"

/******************************************************************************/
// Calculate vector2D length
/******************************************************************************/
float Utility::Vector2DLength(sf::Vector2f& pVec0)
{
    return (float)sqrt(Vector2DSquareLength(pVec0));
}

/******************************************************************************/
// Calculate vector2D square length
/******************************************************************************/
float Utility::Vector2DSquareLength(sf::Vector2f& pVec0)
{
    return pVec0.x * pVec0.x + pVec0.y * pVec0.y;
}

/******************************************************************************/
// Normalize vector2D
/******************************************************************************/
void Utility::Vector2DNormalize(sf::Vector2f& vec)
{
    float len = Vector2DLength(vec);
    vec /= len;
}

/******************************************************************************/
// Find vector2D perpendicular vector2D
/******************************************************************************/
void Utility::Vector2DPerp(sf::Vector2f& vec)
{
    float temp = vec.x;
    vec.x = vec.y;
    vec.y = -1.0f * temp;
}

/******************************************************************************/
// Calculate vector2D given angle in degree
/******************************************************************************/
void Utility::Vector2DFromAngleDeg(sf::Vector2f& vec, float angle)
{
    vec.x = cosf(angle * (float)PI / 180.0f);
    vec.y = sinf(angle * (float)PI / 180.0f);
}

/******************************************************************************/
// Calculate vector2D given angle in rad
/******************************************************************************/
void Utility::Vector2DFromAngleRad(sf::Vector2f& vec, float angle)
{
    vec.x = cosf(angle);
    vec.y = sinf(angle);
}

/******************************************************************************/
// Convert rad to degree
/******************************************************************************/
float Utility::AngleRadToDeg(float angle)
{
    return (angle * 180.0f) / (float)PI;
}

/******************************************************************************/
// Convert degree to rad
/******************************************************************************/
float Utility::AngleDegToRad(float angle)
{
    return angle * (float)PI / 180.0f;
}

/******************************************************************************/
// Generate random float given min and max
/******************************************************************************/
float Utility::Randomf(float min, float max)
{
    return (max - min) * ((float)rand() / RAND_MAX) + min;
}
