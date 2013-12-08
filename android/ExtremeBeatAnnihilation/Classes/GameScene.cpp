#include "GameScene.h"

using namespace cocos2d;
using namespace CocosDenshion;

// externs defined in Global.h
extern std::string Game_Song;

// Initialize the main game scene with all the layers for the left and right backgrounds, foregrounds,
//    players, and ui
//
// return - false if there was an error in initializing, true otherwise
bool GameScene::init()
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    BackgroundRLayer* backgroundR;      // background for the right player's screen
    BackgroundLLayer* backgroundL;      // background for the left player's screen
    ForegroundRLayer* foregroundR;      // foreground (like obstacles) for the right player's screen
    ForegroundLLayer* foregroundL;      // foreground (like obstacles) for the left player's screen
    PlayerRLayer*     playerR;          // the layer to contain the right player
    PlayerLLayer*     playerL;          // the layer to contain the left player
    UILayer*          ui;               // the overall ui of the scene

    if(!CCScene::init())
    {
        return false;
    }

    backgroundR = BackgroundRLayer::create();
    backgroundL = BackgroundLLayer::create();
    foregroundR = ForegroundRLayer::create();
    foregroundL = ForegroundLLayer::create();
    playerR     = PlayerRLayer::create();
    playerL     = PlayerLLayer::create();
    ui          = UILayer::create();

    rightPlayer = PlayerR::create();
    rightPlayer->setPosition(ccp(winSize.width/6*5, winSize.height/3));
    foregroundR->addChild(rightPlayer, 1);

    leftPlayer  = PlayerL::create();
    leftPlayer->setPosition(ccp(winSize.width/6, winSize.height/3));
    foregroundL->addChild(leftPlayer, 1);

    this->addChild(backgroundR, 0);
    this->addChild(backgroundL, 0);
    this->addChild(foregroundR, 1);
    this->addChild(foregroundL, 1);
    this->addChild(playerR, 1);
    this->addChild(playerL, 1);
    this->addChild(ui, 2);

    // start up the song chosen by the user
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic(Game_Song.c_str(), false);

    return true;
}

void GameScene::ccTouchesBegin( cocos2d::CCSet * ptouches, cocos2d::CCEvent * event )
{
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCSetIterator it= ptouches->begin();
    CCPoint currentLocation;
    CCTouch* touch;
    CCRect* bottomLeft = new CCRect(0, 0, winSize.width/2, winSize.height/2);
    CCRect* topLeft = new CCRect(0, winSize.height/2, winSize.width/2, winSize.height/2);
    CCRect* bottomRight = new CCRect(winSize.width/2, 0, winSize.width/2, winSize.height/2);
    CCRect* topRight = new CCRect(winSize.width/2, winSize.height/2, winSize.width/2, winSize.height/2);


    for(int i = 0; i <= ptouches->count(); i++)
	{
    	touch = (CCTouch*)(*it);
		currentLocation = touch->getLocationInView();
		//currentLocation = CCDirector(sharedDirector)::(convertToGL:currentLocation);

		if(bottomLeft->containsPoint(currentLocation))
		{
			// left player slide
		}
		else if(topLeft->containsPoint(currentLocation))
		{
			// left player jump
			leftPlayer->Jump();
		}
		else if(bottomRight->containsPoint(currentLocation))
		{
			// right player slide
		}
		else if(topRight->containsPoint(currentLocation))
		{
			// right player jump
			rightPlayer->Jump();
		}
		else
		{
			//NSLog(@"Congratulations, you have broken the physical laws of reality.");
		}

		it++;
	}
}
