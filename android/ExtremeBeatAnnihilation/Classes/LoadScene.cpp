#include "LoadScene.h"

using namespace cocos2d;
using namespace CocosDenshion;


CCScene* LoadScene::Scene()
{
	// Create the scene and add the layer in
    CCScene*         scene = CCScene::create();
    LoadScene* layer = LoadScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    return scene;
}

// Initialize the Loading screen to show while waiting for the game to load
//
// return - false if there was an error in initializing, true otherwise
bool LoadScene::init()
{
    CCLabelTTF*      loading;  	  // The label saying loading
    CCSize           size;        // the size of the window

    // Initialize the CCLayer, if it fails, obviously we need to break
    if(!CCLayer::init())
    {
        return false;
    }

    // get the window size from the director
    size = CCDirector::sharedDirector()->getWinSize();

    // create the loading label and add it to the scene
    loading = CCLabelTTF::create("Loading...", MENU_FONT_STYLE, MENU_FONT_SIZE);
    loading->setPosition(ccp(size.width / 2, size.height / 2));
    this->addChild(loading, 1);

    // Schedule the level generator to be called, immediately, this is to avoid the loading scene
    // Not being displayed
    this->scheduleOnce(schedule_selector(LoadScene::GenerateObstacles), 0);

    // Return true, we are good to go
    return true;
}

void LoadScene::GenerateObstacles()
{
	// Populate the obstacles
	// TODO: Actually implement algorithm
	// TODO: DELETE THIS FOR THE LOVE OF GOD AND ALL THAT IS HOLY WHEN THE ALGORITHM IS READY
	usleep(2000000);		// Sleep for 5 seconds (or 5000000 microseconds)

	// We are all ready to go to play the game, pause the music and get the party
	// started!
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	CCDirector::sharedDirector()->replaceScene(GameScene::create());
}
