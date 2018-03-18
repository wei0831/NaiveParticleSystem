/******************************************************************************/
/*!
\file   Game.h
\author Jack Chang
\date   08/01/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief

*/
/******************************************************************************/
#ifndef GAME_H
#define GAME_H
/*------------------------------------------------------------------------------
// Includes
------------------------------------------------------------------------------*/
#pragma region Includes
#include "SFML/Graphics.hpp"
#include "AntTweakBar.h"
#include "Emitter_Bubbles.h"
#include "Emitter_Explosion.h"
#include "Emitter_Fire.h"
#include "DummyResourceManager.h"
#pragma endregion

class Game
{
    /*--------------------------------------------------------------------------
    // Public Functions
    --------------------------------------------------------------------------*/
public:
    Game(int screenW, int screenH, std::string title);
    ~Game();
    void run();

    /*--------------------------------------------------------------------------
    // Public Variables
    --------------------------------------------------------------------------*/
public:
    enum TESTNUM
    {
        TEST_BUBBLE,
        TEST_EXPLOSION,
        TEST_FIRE
    };
    TESTNUM mTestNum;

    /*--------------------------------------------------------------------------
    // Private Functions
    --------------------------------------------------------------------------*/
private:
    void initalize();
    void processEvents();
    void update(sf::Time time);
    void draw();
    void (TW_CALL btnOne)(void *);

    /*--------------------------------------------------------------------------
    // Private Variables
    --------------------------------------------------------------------------*/
private:
    sf::RenderWindow mWindow;
    float mBGColor[3];
    sf::Time mFrameRate;
    TwBar* mBar;

    // Demo Emitters
    Emitter_Bubbles* testEmitter0;
    Emitter_Explosion* testEmitter1;
    Emitter_Fire* testEmitter2;
};

#endif
