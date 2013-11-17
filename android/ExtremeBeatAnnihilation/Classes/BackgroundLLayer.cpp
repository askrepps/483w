#include "BackgroundLLayer.h"

using namespace cocos2d;

// Initialize the left player's background for the main game scene
//
// return - false if there was an error in initializing, true otherwise
bool BackgroundLLayer::init()
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

    // TODO: remove this as it is temporary to display a test
    CCLabelTTF* tempHeader = CCLabelTTF::create("Test Left", "Arial", 50);
    tempHeader->setPosition( ccp(layerSize.width * 0.5, layerSize.height * 0.5) );
    this->addChild(tempHeader);

    return true;
}
