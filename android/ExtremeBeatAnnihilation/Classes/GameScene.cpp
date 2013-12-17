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
    if(!CCScene::init())
    {
        return false;
    }

    // create all the layers
    m_backgroundR = BackgroundRLayer::create();
    m_backgroundL = BackgroundLLayer::create();
    m_foregroundR = ForegroundRLayer::create();
    m_foregroundL = ForegroundLLayer::create();
    m_uiLayer     = UILayer::create();

    m_foregroundR->setTouchEnabled(true);
    m_foregroundL->setTouchEnabled(true);

    // add all the layers
    addChild(m_backgroundR, 0);
    addChild(m_backgroundL, 0);
    addChild(m_foregroundR, 1);
    addChild(m_foregroundL, 1);
    addChild(m_uiLayer, 2);

    // start up the song chosen by the user
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic(Game_Song.c_str(), false);

    // startup all the update methods of the layers
    ScheduleAllUpdates();

    return true;
}

// check if song the song ended and switch to the main menu if it did
//
// delta [in] - time since last update?
void GameScene::update(float delta)
{
    // switch to the main menu when the song finishes
    // TODO: create an end game scene and switch to that instead
    if (!SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())
    {
        SimpleAudioEngine::sharedEngine()->playBackgroundMusic(MENU_MUSIC, true);
        CCDirector::sharedDirector()->replaceScene(MainMenu::Scene());
    }

    // Update the backgrounds
    m_backgroundL->UpdateLayer(delta);
    m_backgroundR->UpdateLayer(delta);

    // Update the foreground
    // TODO: Create UpdateLayer for the foregrounds and call them

    // Update the UI Layer
    m_uiLayer->UpdateLayer(delta);

}

// schedule the updates to run for all the necessary layers
void GameScene::ScheduleAllUpdates()
{
    this->scheduleUpdate();
}
