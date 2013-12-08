#include "UILayer.h"

using namespace cocos2d;

// Initialize the UI for the main game scene
//
// return - false if there was an error in initializing, true otherwise
bool UILayer::init()
{
    if(!CCLayer::init())
    {
        return false;
    }

    // TODO: remove this as it is temporary to display that this is the main game scene when running
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCLabelTTF* tempHeader = CCLabelTTF::create("Main Game Scene", "Arial", 50);
    tempHeader->setPosition( ccp(size.width * 0.5, size.height * 0.9) );
    this->addChild(tempHeader);

    return true;
}
