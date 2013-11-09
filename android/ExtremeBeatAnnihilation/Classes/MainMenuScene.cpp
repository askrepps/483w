#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"
#include "CharacterSelectScene.h"
#include "OptionsMenuScene.h"

using namespace cocos2d;
using namespace CocosDenshion;

// Initialize the menu items, background, and overall setup of the main menu
//
// return - false if there was an error in initializing, true otherwise
bool MainMenu::init()
{
    CCMenuItemFont* itemSinglePlayer;  // menu item for starting single player game
    CCMenuItemFont* itemMultiplayer;   // menu item for starting multiplayer game
    CCMenuItemFont* itemOptions;       // menu item for opening up options
    CCMenuItemFont* itemExit;          // menu item for exiting the app
    CCMenu*         menu;              // menu to contain the closeItem

    CCSize          size;              // the size of the window
    CCSprite*       sprite;            // the background splashscreen

    if(!CCLayer::init())
    {
        return false;
    }

    // get the window size from the director
    size = CCDirector::sharedDirector()->getWinSize();

    // create the items for the menu
    itemSinglePlayer = CCMenuItemFont::create("Start Single Player", this, menu_selector(MainMenu::CallbackSelectSinglePlayer));
    itemMultiplayer  = CCMenuItemFont::create("Start Multiplayer", this, menu_selector(MainMenu::CallbackSelectMultiplayer));
    itemOptions      = CCMenuItemFont::create("Options", this, menu_selector(MainMenu::CallbackSelectOptions));
    itemExit         = CCMenuItemFont::create("Exit", this, menu_selector(MainMenu::CallbackSelectExit));

    // create menu to contain the menu items
    menu = CCMenu::create(itemSinglePlayer, itemMultiplayer, itemOptions, itemExit, NULL);
    menu->alignItemsVertically();
    menu->setPosition(size.width * 0.5, size.height * 0.5);
    this->addChild(menu, 1);

    // add splash screen as a sprite on the center of the screen
    sprite = CCSprite::create("splashscreen.jpg");
    sprite->setPosition( ccp(size.width / 2, size.height / 2) );
    this->addChild(sprite, 0);

    return true;
}

// Create a main menu scene that has a MainMenu layer
//
// return - a newly created main menu scene
CCScene* MainMenu::Scene()
{
    CCScene*  scene = CCScene::create();    // the main menu scene to return
    MainMenu* layer = MainMenu::create();   // the layer for the scene

    scene->addChild(layer);

    return scene;
}

// On selecting the single player menu item, switch to a character select scene with the necessary
//    information on starting a single player game
//
// sender [in] - the object that sent the selected event?
void MainMenu::CallbackSelectSinglePlayer(CCObject* sender)
{
	CCDirector::sharedDirector()->replaceScene(CharacterSelect::Scene());
}

// On selecting the multiplayer menu item, switch to a character select scene with the necessary
//    information on starting a multiplayer game
//
// sender [in] - the object that sent the selected event?
void MainMenu::CallbackSelectMultiplayer(CCObject* sender)
{
	CCDirector::sharedDirector()->replaceScene(CharacterSelect::Scene());
}

// On selecting the single player menu item, switch to the options scene
//
// sender [in] - the object that sent the selected event?
void MainMenu::CallbackSelectOptions(CCObject* sender)
{
	CCDirector::sharedDirector()->replaceScene(OptionsMenu::Scene());
}

// On selecting the single player menu item, exit the app
//
// sender [in] - the object that sent the selected event?
void MainMenu::CallbackSelectExit(CCObject* sender)
{
    CCDirector::sharedDirector()->end();
}
