#include "PlayerLLayer.h"

using namespace cocos2d;

// Initialize the left player for the main game scene
//
// return - false if there was an error in initializing, true otherwise
bool PlayerLLayer::init()
{
    if(!CCLayer::init())
    {
        return false;
    }

    return true;
}
