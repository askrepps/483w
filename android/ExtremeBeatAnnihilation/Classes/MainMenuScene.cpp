#include "MainMenuScene.h"

using namespace cocos2d;
using namespace CocosDenshion;

// Initialize the menu items, background, and overall setup of the main menu
//
// return - false if there was an error in initializing, true otherwise
bool MainMenu::init()
{
    CCLabelTTF*      labelSinglePlayer; // the text for single player menu item
    CCLabelTTF*      labelMultiplayer;  // the text for multiplayer menu item
    CCLabelTTF*      labelOptions;      // the text for options menu item
    CCLabelTTF*      labelExit;         // the text for exit menu item
    CCMenuItemLabel* itemSinglePlayer;  // menu item for starting single player game
    CCMenuItemLabel* itemMultiplayer;   // menu item for starting multiplayer game
    CCMenuItemLabel* itemOptions;       // menu item for opening up options
    CCMenuItemLabel* itemExit;          // menu item for exiting the app
    CCMenu*          menu;              // menu to contain the menu items

    CCSize           size;              // the size of the window
    CCSprite*        sprite;            // the background splashscreen

    if(!CCLayer::init())
    {
        return false;
    }

    // get the window size from the director
    size = CCDirector::sharedDirector()->getWinSize();

    // create the text for the menu items
    labelSinglePlayer = CCLabelTTF::create("Start Single Player", MENU_FONT_STYLE, MENU_FONT_SIZE);
    labelMultiplayer  = CCLabelTTF::create("Start Multiplayer", MENU_FONT_STYLE, MENU_FONT_SIZE);
    labelOptions      = CCLabelTTF::create("Options", MENU_FONT_STYLE, MENU_FONT_SIZE);
    labelExit         = CCLabelTTF::create("Exit", MENU_FONT_STYLE, MENU_FONT_SIZE);

    // create the items for the menu
    itemSinglePlayer = CCMenuItemLabel::create(labelSinglePlayer, this, menu_selector(MainMenu::CallbackSelectSinglePlayer));
    itemMultiplayer  = CCMenuItemLabel::create(labelMultiplayer, this, menu_selector(MainMenu::CallbackSelectMultiplayer));
    itemOptions      = CCMenuItemLabel::create(labelOptions, this, menu_selector(MainMenu::CallbackSelectOptions));
    itemExit         = CCMenuItemLabel::create(labelExit, this, menu_selector(MainMenu::CallbackSelectExit));

    // make all menu items red
    itemSinglePlayer->setColor(MENU_COLOR);
    itemMultiplayer->setColor(MENU_COLOR);
    itemOptions->setColor(MENU_COLOR);
    itemExit->setColor(MENU_COLOR);

    // create menu to contain the menu items
    menu = CCMenu::create(itemSinglePlayer, itemMultiplayer, itemOptions, itemExit, NULL);
    menu->alignItemsVertically();
    menu->setPosition(size.width * POSITION_HALF_SCREEN, size.height * POSITION_HALF_SCREEN);
    this->addChild(menu, 1);

    // add splash screen as a sprite on the center of the screen
    sprite = CCSprite::create(BACKGROUND_IMAGE);
    sprite->setPosition( ccp(size.width * POSITION_HALF_SCREEN, size.height * POSITION_HALF_SCREEN) );
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
