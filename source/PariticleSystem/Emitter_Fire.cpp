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
#include "Emitter_Fire.h"

/******************************************************************************/
// Default Constructor
/******************************************************************************/
Emitter_Fire::Emitter_Fire(int capcity, sf::Vector2f pos, sf::Color startColor)
    : Emitter(capcity, pos), mStartColor(startColor)
{ 
    // Assign Shape
    sf::Shape* shape = new sf::CircleShape(10.f);
    shape->setTexture(
        DummyResourceManager::getInstance().getTexture(
        (int)DummyResourceManager::TEX_PARTICLE));

    shape->setFillColor(sf::Color::Red);
    setShape(shape);

    // Change to Addictive Blending
    mBlendMode = sf::BlendAdd;

    // Initialize Emitter
    reset();
}

/******************************************************************************/
// Reset all stats of emitter
/******************************************************************************/
void Emitter_Fire::reset()
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
void Emitter_Fire::initialParticleStats(Particle& particle)
{
    particle.mPosition = 
        mPosition + sf::Vector2f(Utility::Randomf(-10.f, 10.f), 
                                 0.0f);
    particle.mDirection = 
        sf::Vector2f(Utility::Randomf(-0.3f, 0.3f),
                     Utility::Randomf(-1.5f, -0.75f));
    particle.mSpeed = Utility::Randomf(1.0f, 175.0f);
    particle.mScale.x = Utility::Randomf(0.5f, 3.0f);
    particle.mScale.y = particle.mScale.x;
    particle.mDuration = Utility::Randomf(1.5f, 6.0f);
    particle.mPercentLife = 1.0f;
    particle.mOrientation = 0.0f;
    particle.mColor = mStartColor;
}

/******************************************************************************/
// Control each particle update behavior
/******************************************************************************/
void Emitter_Fire::updateParticleBehavior(Particle& particle, sf::Time time)
{
    // Linear movement
    particle.mPosition += 
        particle.mDirection * particle.mSpeed * time.asSeconds();

    // Dumb air drag
    particle.mSpeed *= 0.99f;

    // Color change depends on life
    float percentage = 1.0f - particle.mPercentLife;

    particle.mColor.g =
        (sf::Uint8)(mStartColor.g + (int)(255 * percentage));
    particle.mColor.b =
        (sf::Uint8)(mStartColor.b + (int)(255 * percentage));

    particle.mColor.a = (sf::Uint8)abs(particle.mPercentLife * 255);
}

/******************************************************************************/
// Getters
/******************************************************************************/
sf::Color Emitter_Fire::getStartColor() const
{
    return mStartColor;
}

/******************************************************************************/
// Setters
/******************************************************************************/
void Emitter_Fire::setStartColor(const sf::Color& color)
{
    mStartColor = color;
}
