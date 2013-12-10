#include "GameScene.h"

using namespace cocos2d;
using namespace CocosDenshion;

// externs defined in Global.h
extern std::string Game_Song;

// Initialize the main game scene with all the layers for the left and right backgrounds, foregrounds,
//    and ui
//
// return - false if there was an error in initializing, true otherwise
bool GameScene::init()
{
    UILayer* ui;                                // the overall ui of the scene

    if(!CCScene::init())
    {
        return false;
    }

    // create all the layers
    m_backgroundR = BackgroundRLayer::create();
    m_backgroundL = BackgroundLLayer::create();
    m_foregroundR = ForegroundRLayer::create();
    m_foregroundL = ForegroundLLayer::create();
    ui            = UILayer::create();

    // add all the layers
    addChild(m_backgroundR, 0);
    addChild(m_backgroundL, 0);
    addChild(m_foregroundR, 1);
    addChild(m_foregroundL, 1);
    addChild(ui, 2);

    // start up the song chosen by the user
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic(Game_Song.c_str(), false);

    // startup all the update methods of the layers
    ScheduleAllUpdates();

    return true;
}

// schedule the updates to run for all the necessary layers
void GameScene::ScheduleAllUpdates()
{
    m_backgroundL->scheduleUpdate();
    m_backgroundR->scheduleUpdate();
}
