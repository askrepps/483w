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
	CCSize   winSize = CCDirector::sharedDirector()->getWinSize();
    UILayer* ui;                                                     // the overall ui of the scene

    if(!CCScene::init())
    {
        return false;
    }

    m_backgroundR = BackgroundRLayer::create();
    m_backgroundL = BackgroundLLayer::create();
    m_foregroundR = ForegroundRLayer::create();
    m_foregroundL = ForegroundLLayer::create();
    m_playerR     = PlayerRLayer::create();
    m_playerL     = PlayerLLayer::create();
    ui            = UILayer::create();

    this->addChild(m_backgroundR, 0);
    this->addChild(m_backgroundL, 0);
    this->addChild(m_foregroundR, 1);
    this->addChild(m_foregroundL, 1);
    this->addChild(m_playerR, 1);
    this->addChild(m_playerL, 1);
    this->addChild(ui, 2);

    rightPlayer = PlayerR::create();
    rightPlayer->setPosition(ccp(winSize.width/6*5, winSize.height/3));
    m_foregroundR->addChild(rightPlayer, 1);

    leftPlayer = PlayerL::create();
    leftPlayer->setPosition(ccp(winSize.width/6, winSize.height/3));
    m_foregroundL->addChild(leftPlayer, 1);

    // start up the song chosen by the user
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic(Game_Song.c_str(), false);

    // startup all the update methods of the layers
    ScheduleAllUpdates();

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

// schedule the updates to run for all the necessary layers
void GameScene::ScheduleAllUpdates()
{
    m_backgroundL->scheduleUpdate();
    m_backgroundR->scheduleUpdate();
}
