#include "ForegroundRLayer.h"

using namespace cocos2d;

// Initialize the right player's foreground (obstacles, player) for the main game scene
//
// return - false if there was an error in initializing, true otherwise
bool ForegroundRLayer::init()
{
    CCSize screenSize;                         // the size of the window
    CCSize layerSize;                          // size of this layer

    if(!CCLayer::init())
    {
        return false;
    }

    // get the window size from the director
    screenSize = CCDirector::sharedDirector()->getWinSize();

    // set layerSize to be the full height and half the width of screenSize, and position the layer to
    //   the right side of the screen
    layerSize.setSize(screenSize.width * POS_HALF_SCREEN, screenSize.height);
    setContentSize(layerSize);
    setPosition(screenSize.width * POS_HALF_SCREEN, 0);

    // create the player and add it
    m_player = PlayerR::create();
    m_player->setPosition( ccp(layerSize.width/4 * 3, layerSize.height * PLAYER_Y_POS) );
    addChild(m_player);

    return true;
}

// Needs description
//
// touches [in] -
// event   [in] -
void ForegroundRLayer::ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event)
{
    CCSize        size            = CCDirector::sharedDirector()->getWinSize();
    CCSetIterator it              = touches->begin();
    CCPoint       currentLocation;
    CCTouch*      touch;
    CCRect*       topRight        = new CCRect(size.width / 2, 0, size.width / 2, size.height/2);
    CCRect*       bottomRight     = new CCRect(size.width / 2, size.height/2, size.width / 2, size.height / 2);

    for(int i = 0; i < touches->count(); i++)
    {
        touch = (CCTouch*)(*it);
        if(touch)
        {
			currentLocation = touch->getLocationInView();

			if(bottomRight->containsPoint(currentLocation))          // right player slide
			{
				 m_player->Slide();
			}
			else if(topRight->containsPoint(currentLocation))        // right player jump
			{
				m_player->Jump();
			}
			else
			{
				CCLog("Left Touch.\n");
			}
        }
        it++;
    }
}
