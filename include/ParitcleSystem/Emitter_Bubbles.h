/******************************************************************************/
/*!
\file   Emitter_Bubbles.h
\author Jack Chang
\date   08/03/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
Bubble flow particle effects
*/
/******************************************************************************/
#ifndef EMITTER_BUBBLES_H
#define EMITTER_BUBBLES_H

#include "Emitter.h"
#include "PointDirZone.h"

class Emitter_Bubbles : public Emitter
{
    /*--------------------------------------------------------------------------
    // Protected variables
    --------------------------------------------------------------------------*/
protected:
    virtual void initialParticleStats(Particle& particle);
    virtual void updateParticleBehavior(Particle& particle, sf::Time time);

    /*--------------------------------------------------------------------------
    // Public Functions
    --------------------------------------------------------------------------*/
public:
    Emitter_Bubbles(int capcity, sf::Vector2f pos, 
        sf::Color startColor, sf::Color endColor, PointDirZone zone);
    void reset();
    sf::Color getStartColor() const;
    sf::Color getEndColor() const;
    void setStartColor(const sf::Color& color);
    void setEndColor(const sf::Color& color);

    /*--------------------------------------------------------------------------
    // Private Variables
    --------------------------------------------------------------------------*/
private:
    sf::Color mStartColor;
    sf::Color mEndColor;
    PointDirZone mZone;
};

#endif