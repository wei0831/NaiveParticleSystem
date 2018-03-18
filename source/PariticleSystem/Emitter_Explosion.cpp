/******************************************************************************/
/*!
\file   Emitter_Explosion.cpp
\author Jack Chang
\date   08/03/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
    Explosion particle effects
*/
/******************************************************************************/
#include "Emitter_Explosion.h"

/******************************************************************************/
// Default Constructor
/******************************************************************************/
Emitter_Explosion::Emitter_Explosion(int capcity, sf::Vector2f pos,
    sf::Color startColor, sf::Color endColor)
    : Emitter(capcity, pos), mStartColor(startColor), mEndColor(endColor),
    mCurAngle(0.0f)
{
    // Assign Shape
    sf::Shape* shape = new sf::RectangleShape(sf::Vector2f(60.0f, 4.0f));
    shape->setTexture(
        DummyResourceManager::getInstance().getTexture(
            (int)DummyResourceManager::TEX_LASER));
    setShape(shape);

    // Initialize Emitter
    reset();
}

/******************************************************************************/
// Reset all stats of emitter
/******************************************************************************/
void Emitter_Explosion::reset()
{
    mBirthTimer = -1.f;
    mBirthAmount = -1;
    mBirthRate = -1.0f;
    mLife = -1.0f;
    mStopAfterLifeEnd = false;
}

/******************************************************************************/
// Trigger to create all particles
//     this particle creates 3 waves of explosion
//     only differences between waves are color and move speed
/******************************************************************************/
void Emitter_Explosion::trigger()
{
    // 1st wave. 360 degree, 80 particles
    // Slow speed, Color red
    mCurAngle = 0.f;
    for (int i = 0; i < 80; i++)
    {
        Particle& cur = createParticleManually();
        sf::Vector2f dir(0.f, 1.f);
        mCurAngle += 0.08f;
        Utility::Vector2DFromAngleRad(dir, mCurAngle);
        cur.mPosition = this->mPosition;
        cur.mDirection = dir;
        cur.mSpeed = 200.f + Utility::Randomf(-100.f, 100.f);
        cur.mScale.x = 1.0f;
        cur.mScale.y = 1.0f;
        cur.mDuration = 1.0f;
        cur.mPercentLife = 1.0f;
        cur.mOrientation = Utility::AngleRadToDeg(mCurAngle);
        cur.mColor = sf::Color::Red;
    }

    // 2nd wave. 360 degree, 80 particles
    // Medium speed, Color yellow
    mCurAngle = 0.f;
    for (int i = 0; i < 80; i++)
    {
        Particle& cur = createParticleManually();
        sf::Vector2f dir(0.f, 1.f);
        mCurAngle += 0.08f;
        Utility::Vector2DFromAngleRad(dir, mCurAngle);
        cur.mPosition = this->mPosition;
        cur.mDirection = dir;
        cur.mSpeed = 400.f + Utility::Randomf(-100.f, 100.f);
        cur.mScale.x = 1.0f;
        cur.mScale.y = 1.0f;
        cur.mDuration = 1.0f;
        cur.mPercentLife = 1.0f;
        cur.mOrientation = Utility::AngleRadToDeg(mCurAngle);
        cur.mColor = sf::Color::Yellow;
    }

    // 3rd wave. 360 degree, 80 particles
    // Fast speed, Color white
    mCurAngle = 0.f;
    for (int i = 0; i < 80; i++)
    {
        Particle& cur = createParticleManually();
        sf::Vector2f dir(0.f, 1.f);
        mCurAngle += 0.08f;
        Utility::Vector2DFromAngleRad(dir, mCurAngle);
        cur.mPosition = this->mPosition;
        cur.mDirection = dir;
        cur.mSpeed = 600.f + Utility::Randomf(-100.f, 100.f);
        cur.mScale.x = 1.0f;
        cur.mScale.y = 1.0f;
        cur.mDuration = 1.0f;
        cur.mPercentLife = 1.0f;
        cur.mOrientation = Utility::AngleRadToDeg(mCurAngle);
        cur.mColor = sf::Color::White;
    }
}

/******************************************************************************/
// Control each new birth particle stats
/******************************************************************************/
void Emitter_Explosion::initialParticleStats(Particle& particle)
{
    // This particle effect does not generate particle automatically
}

/******************************************************************************/
// Control each particle update behavior
/******************************************************************************/
void Emitter_Explosion::updateParticleBehavior(Particle& particle, sf::Time time)
{
    // Linear movement
    particle.mPosition += 
        particle.mDirection * particle.mSpeed * time.asSeconds();

    // Dumb air drag
    particle.mSpeed *= 0.97f;

    // Explode and get smaller
    particle.mScale.x *= 0.92f;

    // Fade out
    particle.mColor.a = (int)(particle.mPercentLife * 255);
}

/******************************************************************************/
// Getters
/******************************************************************************/
sf::Color Emitter_Explosion::getStartColor() const
{
    return mStartColor;
}

sf::Color Emitter_Explosion::getEndColor() const
{
    return mEndColor;
}

/******************************************************************************/
// Setters
/******************************************************************************/
void Emitter_Explosion::setStartColor(const sf::Color& color)
{
    mStartColor = color;
}

void Emitter_Explosion::setEndColor(const sf::Color& color)
{
    mEndColor = color;
}
