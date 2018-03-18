/******************************************************************************/
/*!
\file   Emitter_Fire.cpp
\author Jack Chang
\date   08/03/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
Fire particle effects
*/
/******************************************************************************/
#ifndef EMITTER_FIRE_H
#define EMITTER_FIRE_H

#include "Emitter.h"
#include "Zone.h"

class Emitter_Fire : public Emitter
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
    Emitter_Fire(int capcity, sf::Vector2f pos, sf::Color startColor);
    void reset();
    sf::Color getStartColor() const;
    void setStartColor(const sf::Color& color);

    /*--------------------------------------------------------------------------
    // Private Variables
    --------------------------------------------------------------------------*/
private:
    sf::Color mStartColor;
    Zone* mZone;
};

#endif