#include "GameScene.h"

using namespace cocos2d;
//using namespace CocosDenshion;

// Initialize the main game scene with all the layers for the left and right backgrounds, foregrounds,
//    players, and ui
//
// return - false if there was an error in initializing, true otherwise
bool GameScene::init()
{
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

    this->addChild(backgroundR, 0);
    this->addChild(backgroundL, 0);
    this->addChild(foregroundR, 1);
    this->addChild(foregroundL, 1);
    this->addChild(playerR, 1);
    this->addChild(playerL, 1);
    this->addChild(ui, 2);

    return true;
}
