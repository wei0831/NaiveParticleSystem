/******************************************************************************/
/*!
\file   Game.cpp
\author Jack Chang
\date   08/03/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
    Demo for Particle System
*/
/******************************************************************************/
#include "Game.h"

/******************************************************************************/
// Callback Prototype
/******************************************************************************/
void TW_CALL changeTest0(void * data);
void TW_CALL changeTest1(void * data);
void TW_CALL changeTest2(void * data);

/******************************************************************************/
// Default Constructor
/******************************************************************************/
Game::Game(int screenW, int screenH, std::string title)
{
    // Enable anti aliasing x8
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    // Create game window
    mWindow.create(
        sf::VideoMode(screenW, screenH), title, sf::Style::Default, settings);

    // Game Initialization
    initalize();
    mBGColor[0] = 0.0f;//0.2f;
    mBGColor[1] = 0.0f;//0.75f;
    mBGColor[2] = 0.0f;//1.0f;

    testEmitter0 = 
        new Emitter_Bubbles(500, sf::Vector2f(0.0f, 600.0f), 
        sf::Color(255, 0, 0), sf::Color(0, 0, 255),
        PointDirZone(sf::Vector2f(0.0f, 600.0f), 
        sf::Vector2f(1.0f, -1.0f), 200));

    testEmitter1 = new Emitter_Explosion(500, sf::Vector2f(400.0f, 300.0f),
        sf::Color(255, 0, 0), sf::Color(0, 0, 255));

    testEmitter2 = new Emitter_Fire(500, sf::Vector2f(400.0f, 400.0f), 
        sf::Color(255, 0, 0));
}

/******************************************************************************/
// Default Destructor
/******************************************************************************/
Game::~Game()
{
    delete testEmitter0;
    delete testEmitter1;
    delete testEmitter2;
}

/******************************************************************************/
// Main game loop
/******************************************************************************/
void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time frameRate = sf::seconds(1.f / 60.f);

    while (mWindow.isOpen())
    {
        // Still need to process events in case of drawing takes too much time
        processEvents();

        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > frameRate)
        {
            timeSinceLastUpdate -= frameRate;
            processEvents();
            update(frameRate);
        }

        draw();
    }

    // Terminate antTweakBar
    TwTerminate();
}

/******************************************************************************/
// Window Event Handle
/******************************************************************************/
void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        // Process antTweakBar event first: SFML 2.1
        int handled = TwEventSFML(&event, 2, 1);

        if (!handled)
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                mWindow.close();
                break;
            }
        }
    }
}

/******************************************************************************/
// Game Initialize
/******************************************************************************/
void  Game::initalize()
{
    // Initial Demo
    mTestNum = TEST_FIRE;

    // Initialize AntTweakBar
    TwInit(TW_OPENGL, NULL);
    // Tell the window size to AntTweakBar
    TwWindowSize((int)mWindow.getView().getSize().x
        , (int)mWindow.getView().getSize().y);
    mBar = TwNewBar("Prototype");
    TwDefine(" GLOBAL help='A simple naive particle system.' ");
    TwDefine(" Prototype size='200 200' ");

    // Message added to the help bar.
    int barPos[2] = { 0, 0 };
    TwSetParam(mBar, NULL, "position", TW_PARAM_INT32, 2, &barPos);

    TwAddVarRW(mBar, "BG Color", 
        TW_TYPE_COLOR3F, &mBGColor, " opened=true ");

    // Add Test Buttons
    TwAddButton(mBar, "btn0", changeTest0, this, " label='Test Bubble 0' ");
    TwAddButton(mBar, "btn1", changeTest1, this, " label='Test Explosion 1' ");
    TwAddButton(mBar, "btn2", changeTest2, this, " label='Test Fire 2' ");
}

/******************************************************************************/
// Game Update
/******************************************************************************/
void Game::update(sf::Time time)
{
    switch (mTestNum)
    {
    case Game::TEST_BUBBLE:
        testEmitter0->update(time);
        break;
    case Game::TEST_EXPLOSION:
        // To Do: Global object pool to hold multiple emitters
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            float x = (float)sf::Mouse::getPosition(mWindow).x;
            float y = (float)sf::Mouse::getPosition(mWindow).y;
            testEmitter1->setPosition(sf::Vector2f(x, y));
            testEmitter1->trigger();
        }
        testEmitter1->update(time);
        break;
    case Game::TEST_FIRE:
        testEmitter2->update(time);
        break;
    default:
        break;
    }
}

/******************************************************************************/
// Game Draw
/******************************************************************************/
void Game::draw()
{
    // Background color
    mWindow.clear(sf::Color(
        (int)(mBGColor[0] * 255),
        (int)(mBGColor[1] * 255),
        (int)(mBGColor[2] * 255)));

    // Draw
    switch (mTestNum)
    {
    case Game::TEST_BUBBLE:
        testEmitter0->draw(mWindow);
        break;
    case Game::TEST_EXPLOSION:
        testEmitter1->draw(mWindow);
        break;
    case Game::TEST_FIRE:
        testEmitter2->draw(mWindow);
        break;
    default:
        break;
    }

    // antTweakBar Draw
    TwDraw();

    mWindow.display();
}

/******************************************************************************/
// Callback Functions for antTweakBar to change game state
/******************************************************************************/
void TW_CALL changeTest0(void * data)
{
    TwDefine(" Prototype label='Test Bubble 0' ");
    ((Game*)data)->mTestNum = Game::TEST_BUBBLE;
}
void TW_CALL changeTest1(void * data)
{
    TwDefine(" Prototype label='Test Explosion 1' ");
    ((Game*)data)->mTestNum = Game::TEST_EXPLOSION;
}
void TW_CALL changeTest2(void * data)
{
    TwDefine(" Prototype label='Test Fire 2' ");
    ((Game*)data)->mTestNum = Game::TEST_FIRE;
}
