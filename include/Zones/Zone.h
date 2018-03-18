/******************************************************************************/
/*!
\file   Zone.h
\author Jack Chang
\date   08/01/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
    A base zone. Abstract class
*/
/******************************************************************************/
#ifndef ZONE_H
#define ZONE_H

#include "SFML/Graphics.hpp"

class Zone
{
public:
    virtual sf::Vector2f getRandomPos() = 0;
    virtual sf::Vector2f getRandomDir() = 0;
};

#endif