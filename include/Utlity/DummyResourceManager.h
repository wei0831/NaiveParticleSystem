/******************************************************************************/
/*!
\file   DummyResourceManager.h
\author Jack Chang
\date   08/03/2014
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
Dummy Resource Manager. Should replace with real one asap.
*/
/******************************************************************************/
#ifndef DUMMY_RES_MANAGER
#define DUMMY_RES_MANAGER

#include "SFML/Graphics.hpp"
#include "DummyResourceManager.h"
#include <vector>

// Max numbers of texture allowed
#define MAX_TEXTURE 25

class DummyResourceManager
{
    /*--------------------------------------------------------------------------
    // Public Functions
    --------------------------------------------------------------------------*/
public:
    typedef enum RESOURCE_TEXTURE
    {
        TEX_PARTICLE = 0,
        TEX_LASER
    } RESOURCE_TEXTURE;

    /*--------------------------------------------------------------------------
    // Public Functions
    --------------------------------------------------------------------------*/
public:
    static DummyResourceManager& getInstance();
    void initialResource();
    void loadTextureHelper(int txt, char * filesrc);
    sf::Texture* getTexture(int txt);

private:
    DummyResourceManager();
    DummyResourceManager(DummyResourceManager const&);
    void operator=(DummyResourceManager const&);

private:
    std::vector<sf::Texture> mTextureList;
    bool isInitialized;
};
/*--------------------------------------------------------------------------
// Static Variables
--------------------------------------------------------------------------*/
// static std::vector<sf::Texture> mTextureList;
// static bool isInitialized = false;


// typedef enum RESOURCE_TEXTURE
// {
//     TEX_PARTICLE = 0,
//     TEX_LASER
// } RESOURCE_TEXTURE;

/*--------------------------------------------------------------------------
// Public Functions
--------------------------------------------------------------------------*/


#endif
