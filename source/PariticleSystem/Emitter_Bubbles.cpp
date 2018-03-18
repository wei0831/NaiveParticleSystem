/******************************************************************************/
/*!
\file   Emitter_Bubbles.cpp
\author Jack Chang
\date   08/03/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
    Bubble flow particle effects
*/
/******************************************************************************/
#include "Emitter_Bubbles.h"

/******************************************************************************/
// Default Constructor
/******************************************************************************/
Emitter_Bubbles::Emitter_Bubbles( int capcity, sf::Vector2f pos, 
    sf::Color startColor,sf::Color endColor, PointDirZone zone)
    : Emitter(capcity, pos), mStartColor(startColor), 
      mEndColor(endColor), mZone(zone)
{
    // Assign Shape
    sf::Shape* shape = new sf::CircleShape(10.f);
    setShape(shape);

    // Initialize Emitter
    reset();
}

/******************************************************************************/
// Reset all stats of emitter
/******************************************************************************/
void Emitter_Bubbles::reset()
{
    mBirthTimer = 0.1f;
    mBirthAmount = 5;
    mBirthRate = 0.1f;
    mLife = -1.0f;
    mStopAfterLifeEnd = false;
}

/******************************************************************************/
// Control each new birth particle stats
/******************************************************************************/
void Emitter_Bubbles::initialParticleStats(Particle& particle)
{
    particle.mPosition = mZone.getRandomPos();
    particle.mDirection = mZone.getRandomDir();
    particle.mSpeed = Utility::Randomf(25.0f, 150.0f);
    particle.mScale.x = Utility::Randomf(0.5f, 2.5f);
    particle.mScale.y = particle.mScale.x;
    particle.mDuration = 6.0f;
    particle.mPercentLife = 1.0f;
    particle.mOrientation = 0.0f;
    particle.mColor = mStartColor;
}

/******************************************************************************/
// Control each particle update behavior
/******************************************************************************/
void Emitter_Bubbles::updateParticleBehavior(Particle& particle, sf::Time time)
{
    // Linear movement
    particle.mPosition += 
        particle.mDirection * particle.mSpeed * time.asSeconds();

    // Color change depends on life. Color transition + Fade out
    float percentage = 1.0f - particle.mPercentLife;

    particle.mColor.r =
        mStartColor.r + (int)((mEndColor.r - mStartColor.r) * percentage);
    particle.mColor.g =
        mStartColor.g + (int)((mEndColor.g - mStartColor.g) * percentage);
    particle.mColor.b =
        mStartColor.b + (int)((mEndColor.b - mStartColor.b) * percentage);

    particle.mColor.a = (sf::Uint8)abs(particle.mPercentLife * 255);
}

/******************************************************************************/
// Getters
/******************************************************************************/
sf::Color Emitter_Bubbles::getStartColor() const
{
    return mStartColor;
}

sf::Color Emitter_Bubbles::getEndColor() const
{
    return mEndColor;
}

/******************************************************************************/
// Setters
/******************************************************************************/
void Emitter_Bubbles::setStartColor(const sf::Color& color)
{
    mStartColor = color;
}

void Emitter_Bubbles::setEndColor(const sf::Color& color)
{
    mEndColor = color;
}
