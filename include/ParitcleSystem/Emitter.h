/******************************************************************************/
/*!
\file   Emitter.h
\author Jack Chang
\date   08/03/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
Base particle emitter
*/
/******************************************************************************/
#ifndef EMITTER_H
#define EMITTER_H

#include "CircularObjectPool.hpp"
#include "Particle.h"
#include "Utility.h"
#include "DummyResourceManager.h"

class Emitter
{
    /*--------------------------------------------------------------------------
    // Protected variables
    --------------------------------------------------------------------------*/
protected:
    sf::Vector2f mPosition;
    float mBirthTimer;
    float mBirthRate;
    int mBirthAmount;
    float mLife;
    bool mStopAfterLifeEnd;
    bool mEnableEmit;
    sf::Shape* mShape;
    sf::BlendMode mBlendMode;

    /*--------------------------------------------------------------------------
    // Protected Functions
    --------------------------------------------------------------------------*/
protected:
    void createParticle();
    Particle& createParticleManually();
    void swapParticle(
        CircularObjectPool<Particle>& list, size_t index1, size_t index2);
    virtual void initialParticleStats(Particle& particle);
    virtual void updateParticleBehavior(Particle& particle, sf::Time time);

    /*--------------------------------------------------------------------------
    // Public Functions
    --------------------------------------------------------------------------*/
public:
    Emitter(int capacity, sf::Vector2f pos);
    ~Emitter();
    void update(sf::Time time);
    void draw(sf::RenderWindow& render);
    void reset();

    void setPosition(sf::Vector2f pos);
    sf::Vector2f getPosition();
    float getBirthRate();
    void setBirthRate(float value);
    int  getBirthAmount();
    void setBirthAmount(int value);
    float getLife();
    void setLife(float value);
    bool getEnableEmit();
    void setEnableEmit(bool value);
    sf::Shape* getShape();
    void setShape(sf::Shape* shape);

    /*--------------------------------------------------------------------------
    // Private Variables
    --------------------------------------------------------------------------*/
private:
    CircularObjectPool<Particle> mParticleList;
    sf::RenderStates mRenderState;
};

#endif
