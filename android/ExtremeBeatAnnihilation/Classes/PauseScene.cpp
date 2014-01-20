#include "PauseScene.h"

using namespace cocos2d;
using namespace CocosDenshion;

// externs defined in Global.cpp
extern int  Font_Size_Default;
extern bool Prev_Was_Main_Menu;

// Initialize the pause menu to display over the game scene
//
// return - false if there was an error in initializing, true otherwise
bool PauseLayer::init()
{
    CCLabelTTF*      header;         // the header which displays that this is a pause scene
    CCLabelTTF*      labelOptions;   // the text for options menu item
    CCLabelTTF*      labelMainMenu;  // the text for quit to main menu menu item
    CCLabelTTF*      labelResume;    // the text for resume menu item
    CCMenuItemLabel* itemOptions;    // menu item for opening the options scene
    CCMenuItemLabel* itemMainMenu;   // menu item for quitting to main menu
    CCMenuItemLabel* itemResume;     // menu item for going back to the game
    CCMenu*          menu;           // menu to contain the menu items
    CCSize           size;           // the size of the window

    if(!CCLayer::init())
    {
        return false;
    }

    // get the window size from the director
    size = CCDirector::sharedDirector()->getWinSize();

    // create the header and add it to the scene
    header = CCLabelTTF::create("Paused", FONT_STYLE, Font_Size_Default);
    header->setColor(MENU_COLOR);
    header->setPosition( ccp(size.width * POS_HALF_SCREEN, size.height * POS_HEADER_HEIGHT) );
    this->addChild(header, 1);

    // create the options menu item
    labelOptions = CCLabelTTF::create("Options", FONT_STYLE, Font_Size_Default);
    itemOptions  = CCMenuItemLabel::create(labelOptions, this, menu_selector(PauseLayer::HandleOptionsPressed));
    itemOptions->setColor(MENU_COLOR);

    // create the quit to main menu menu item
    labelMainMenu = CCLabelTTF::create("Quit to Main Menu", FONT_STYLE, Font_Size_Default);
    itemMainMenu  = CCMenuItemLabel::create(labelMainMenu, this, menu_selector(PauseLayer::HandleMainMenuPressed));
    itemMainMenu->setColor(MENU_COLOR);

    // create the resume menu item
    labelResume = CCLabelTTF::create("Resume", FONT_STYLE, Font_Size_Default);
    itemResume  = CCMenuItemLabel::create(labelResume, this, menu_selector(PauseLayer::HandleResumePressed));
    itemResume->setColor(MENU_COLOR);

    // create the menu containing the menu items and add it to the scene
    menu = CCMenu::create(itemOptions, itemMainMenu, itemResume, NULL);
    menu->alignItemsVerticallyWithPadding(MENU_ITEM_PADDING);
    menu->setPosition(size.width * POS_HALF_SCREEN, size.height * POS_HALF_SCREEN);
    this->addChild(menu, 1);

    return true;
}

// runs when the app enters the scene
void PauseLayer::onEnter()
{
    // pause music as soon as possible, so the player doesn't miss any game time
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    CCLayer::onEnter();
}

// Create a pause scene that has a PauseLayer layer
//
// return - a newly created pause scene
CCScene* PauseLayer::Scene()
{
    CCScene*    scene = CCScene::create();       // the pause scene to return
    PauseLayer* layer = PauseLayer::create();    // the layer for the scene

    scene->addChild(layer);

    return scene;
}

// On selecting the options menu item, go to the options scene
//
// sender [in] - the object that sent the selected event
void PauseLayer::HandleOptionsPressed(CCObject* sender)
{
    SimpleAudioEngine::sharedEngine()->playEffect("SFX/select.wav");
    Prev_Was_Main_Menu = false;
    CCDirector::sharedDirector()->replaceScene(OptionsMenu::Scene());
}

// On selecting the quit to main menu menu item, go to the main menu
//
// sender [in] - the object that sent the selected event
void PauseLayer::HandleMainMenuPressed(CCObject* sender)
{
    SimpleAudioEngine::sharedEngine()->playEffect("SFX/select.wav");

    // these lines can be done in this order, because each line is read and saved before executing them

    // pop this scene off the stack which brings you to the game scene, and then replace with main menu
    CCDirector::sharedDirector()->popScene();
    CCDirector::sharedDirector()->replaceScene(MainMenu::Scene());

    // stop will destroy the game scene music data, and then start up the menu music
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic(MENU_MUSIC, true);
}

// On selecting the resume menu item, go back to playing the game
//
// sender [in] - the object that sent the selected event
void PauseLayer::HandleResumePressed(CCObject* sender)
{
    SimpleAudioEngine::sharedEngine()->playEffect("SFX/back.wav");
    CCDirector::sharedDirector()->popScene();
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
