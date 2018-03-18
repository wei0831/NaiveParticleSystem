/******************************************************************************/
/*!
\file   Emitter.cpp
\author Jack Chang
\date   08/01/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
    Base Emitter
*/
/******************************************************************************/
#include "Emitter.h"

/******************************************************************************/
// Default Constructor
/******************************************************************************/
Emitter::Emitter(int capacity, sf::Vector2f pos)
: mParticleList(capacity), mPosition(pos), mEnableEmit(true), mShape(NULL)
{
    mBlendMode = sf::BlendAlpha;

    // Initialize Emitter
    reset();
}

/******************************************************************************/
// Default Destructor
/******************************************************************************/
Emitter::~Emitter()
{
    if (mShape)
        delete mShape;
}

/******************************************************************************/
// Reset all stats of emitter
/******************************************************************************/
void Emitter::reset()
{
    mBirthTimer = 0.0f;
    mBirthAmount = 1;
    mBirthRate = 0.5f;
    mLife = -1.0f;
    mStopAfterLifeEnd = false;
}

/******************************************************************************/
// Control each new birth particle stats
/******************************************************************************/
void Emitter::initialParticleStats(Particle& particle)
{
    particle.mPosition = this->mPosition;
    particle.mDirection = sf::Vector2f(1.0f, 0.0f);
    particle.mSpeed = 15.0f;
    particle.mDuration = 10.0f;
    particle.mPercentLife = 1.0f;
    particle.mOrientation = 0.0f;
    particle.mColor = sf::Color::White;
}

/******************************************************************************/
// Control each particle update behavior
/******************************************************************************/
void Emitter::updateParticleBehavior(Particle& particle, sf::Time time)
{
    particle.mPosition
        += (particle.mDirection * particle.mSpeed * time.asSeconds());
}

/******************************************************************************/
// Main Update
/******************************************************************************/
void Emitter::update(sf::Time time)
{
    if (!mEnableEmit)
        return;

    // Update Emitter Life
    float elapsedSec = time.asSeconds();

    if (mLife > 0.0f)
        mLife -= elapsedSec;
    if (mLife < 0.0f && mStopAfterLifeEnd)
        return;

    // Update Particle List
    size_t removeCount = 0;
    for (size_t i = 0; i < mParticleList.getCount(); i++)
    {
        Particle& ref = mParticleList[i];
        updateParticleBehavior(ref, time);

        // Update Particle Life
        ref.mPercentLife -= elapsedSec / ref.mDuration;
        if (ref.mPercentLife < 0.0f)
            removeCount++;

        // Swap dead particle to the end of list
        swapParticle(mParticleList, i - removeCount, i);
    }
    mParticleList.setCount(mParticleList.getCount() - removeCount);

    // Update Particle Birth
    if (mBirthTimer >= 0.0f)
    {
        mBirthTimer += elapsedSec;
        if (mBirthTimer > mBirthRate)
        {
            int i = 0;
            while (i++ < mBirthAmount)
            {
                createParticle();
            }
            mBirthTimer = 0.0f;
        }
    }
}

/******************************************************************************/
// Rendering
/******************************************************************************/
void Emitter::draw(sf::RenderWindow& render)
{
    if (!mEnableEmit)
        return;

    if (mLife < 0.0f && mStopAfterLifeEnd)
        return;

    // Draw all particles
    for (size_t i = 0; i < mParticleList.getCount(); i++)
    {
        Particle& ref = mParticleList[i]; 
        mShape->setPosition(ref.mPosition);
        mShape->setScale(ref.mScale);
        mShape->setRotation(ref.mOrientation);
        mShape->setFillColor(ref.mColor);

        // Render
        mRenderState.blendMode = mBlendMode;
        render.draw(*mShape, mRenderState);
    }
}

/******************************************************************************/
// Automatically generate particles
/******************************************************************************/
void Emitter::createParticle()
{
    size_t index = mParticleList.getCount();
    Particle& ref = mParticleList[index];
    initialParticleStats(ref);
    mParticleList.setCount(index + 1);
}

/******************************************************************************/
// Manually generate particles
/******************************************************************************/
Particle& Emitter::createParticleManually()
{
    size_t index = mParticleList.getCount();
    Particle& ref = mParticleList[index];
    mParticleList.setCount(index + 1);

    return ref;
}

/******************************************************************************/
// Helper function to swap dead particle to back of list
/******************************************************************************/
void Emitter::swapParticle(CircularObjectPool<Particle>& list,
    size_t index1, size_t index2)
{
    if (index1 == index2) return;

    Particle temp = list[index1];
    list[index1] = list[index2];
    list[index2] = temp;
}

/******************************************************************************/
// Getters
/******************************************************************************/
sf::Vector2f Emitter::getPosition()
{
    return mPosition;
}

float Emitter::getBirthRate()
{
    return mBirthRate;
}

int  Emitter::getBirthAmount()
{
    return mBirthAmount;
}

float Emitter::getLife()
{
    return mLife;
}

bool Emitter::getEnableEmit()
{
    return mEnableEmit;
}

sf::Shape* Emitter::getShape()
{
    return mShape;
}

/******************************************************************************/
// Setters
/******************************************************************************/
void Emitter::setPosition(sf::Vector2f pos)
{
    mPosition = pos;
}

void Emitter::setBirthRate(float value)
{
    mBirthRate = value;
}

void Emitter::setBirthAmount(int value)
{
    mBirthAmount = value;
}

void Emitter::setLife(float value)
{
    mLife = value;
}

void Emitter::setEnableEmit(bool value)
{
    mEnableEmit = value;
}

void Emitter::setShape(sf::Shape* shape)
{
    if (mShape)
        delete mShape;
    
    mShape = shape;
}
