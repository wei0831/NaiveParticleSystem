/******************************************************************************/
/*!
\file   Emitter_Explosion.h
\author Jack Chang
\date   08/03/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
Explosion particle effects
*/
/******************************************************************************/
#ifndef EMITTER_EXPLOSION_H
#define EMITTER_EXPLOSION_H

#include "Emitter.h"
#include "PointDirZone.h"

class Emitter_Explosion : public Emitter
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
    Emitter_Explosion(int capcity,sf::Vector2f pos, 
        sf::Color startColor, sf::Color endColor);
    void reset();
    sf::Color getStartColor() const;
    sf::Color getEndColor() const;
    void setStartColor(const sf::Color& color);
    void setEndColor(const sf::Color& color);
    void trigger();

    /*--------------------------------------------------------------------------
    // Private Variables
    --------------------------------------------------------------------------*/
private:
    sf::Color mStartColor;
    sf::Color mEndColor;
    float mCurAngle;
};

#endif