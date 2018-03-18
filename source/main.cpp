/******************************************************************************/
/*!
\file   main.cpp
\author Jack Chang
\date   07/31/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
    Initial testing for AntTweakBar and SFML
*/
/******************************************************************************/
#include "Game.h"
//#include "vld.h" // Visual Leak Detector

int main()
{
    DummyResourceManager::getInstance().initialResource();

    Game myGame(800, 600, "Naive Particle System");
    myGame.run();

	return 0;
}
