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

    // Reset the timer
    m_timer = 0;

    // Set the seed of the timer
    srand(time(NULL));

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
    scheduleUpdate();

    return true;
}

// check if the song ended and switch to the end game scene if it did; update all of the layers
//
// delta [in] - time since last update?
void GameScene::update(float delta)
{
    // switch to the end game when the song finishes
    if (!SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())
    {
        SimpleAudioEngine::sharedEngine()->playBackgroundMusic(MENU_MUSIC, true);
        CCDirector::sharedDirector()->replaceScene(EndGame::Scene());
    }

    // Update the timer
    m_timer += delta;
    // Do we spawn an obstacle?
    if(m_timer > 1.0)
    {
    	SpawnObstacle(); // Spawn the obstacle
    	m_timer -= 1.0;  // Keep what was left over
    }
    // Update the backgrounds
    m_backgroundL->UpdateLayer(delta);
    m_backgroundR->UpdateLayer(delta);

    // update the foregrounds
    m_foregroundL->UpdateLayer(delta);
    m_foregroundR->UpdateLayer(delta);

    // Update the foreground
    // TODO: Create UpdateLayer for the foregrounds and call them

    // Update the UI Layer
    m_uiLayer->UpdateLayer(delta);

}
// spawns an obstacle every second
void GameScene::SpawnObstacle(void)
{

	int obstacle = (int)(rand() % 4);    	 // What obstacle do we create? 0 - 3

	switch(obstacle)
	{
	// Slide obstacle in the left screen
	case 0:
		m_foregroundL->SpawnSlideObstacle();
		break;
	// Jump obstacle on the left screen
	case 1:
		m_foregroundL->SpawnJumpObstacle();
		break;
	// Slide obstacle on the right screen
	case 2:
		m_foregroundR->SpawnSlideObstacle();
		break;
	// Jump obstacle on the right screen
	case 3:
		m_foregroundR->SpawnJumpObstacle();
		break;
	default:
		CCLog("Invalid obstacle generation");
		break;
	}
}
