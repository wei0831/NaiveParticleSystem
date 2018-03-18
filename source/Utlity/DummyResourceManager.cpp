/******************************************************************************/
/*!
\file   DummyResourceManager.cpp
\author Jack Chang
\date   08/03/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
    Bad dummy Resource Manager. Should replace with real one asap.
*/
/******************************************************************************/
#include "DummyResourceManager.h"
#include <iostream>

/******************************************************************************/
// Get Single Instance
/******************************************************************************/
DummyResourceManager& DummyResourceManager::getInstance()
{
    static DummyResourceManager instance;
    return instance;
}

/******************************************************************************/
// Private Constructor
/******************************************************************************/
DummyResourceManager::DummyResourceManager()
{
    // Private
}

/******************************************************************************/
// Initial all textures
/******************************************************************************/
void DummyResourceManager::initialResource()
{
    // Lazy check
    if (isInitialized)
        return;

    mTextureList.resize(MAX_TEXTURE);
    loadTextureHelper((int)TEX_PARTICLE, "../assets/particleTexture.png");
    loadTextureHelper((int)TEX_LASER, "../assets/laser.png");
}

/******************************************************************************/
// Load textures from files
/******************************************************************************/
void DummyResourceManager::loadTextureHelper(int txt, char * filesrc)
{
    if (!mTextureList[txt].loadFromFile(filesrc))
        std::cerr << " Filed to load texture !" << std::endl;
}

/******************************************************************************/
// Retrieval textures
/******************************************************************************/
sf::Texture* DummyResourceManager::getTexture(int txt)
{
    return &mTextureList[txt];
}
