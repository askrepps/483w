#include "ForegroundLLayer.h"

using namespace cocos2d;

// Initialize the left player's foreground (obstacles, ground) for the main game scene
//
// return - false if there was an error in initializing, true otherwise
bool ForegroundLLayer::init()
{
    CCSize screenSize;                         // the size of the window
    CCSize layerSize;                          // size of this layer

    if(!CCLayer::init())
    {
        return false;
    }

    // get the window size from the director
    screenSize = CCDirector::sharedDirector()->getWinSize();

    // set layerSize to be the full height and half the width of screenSize
    layerSize.setSize(screenSize.width * POS_HALF_SCREEN, screenSize.height);
    this->setContentSize(layerSize);

    // set the position of the layer to the left side of the screen
    this->setPosition(0, 0);

    return true;
}
