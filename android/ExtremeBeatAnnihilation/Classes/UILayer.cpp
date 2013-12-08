#include "UILayer.h"

using namespace cocos2d;
using namespace CocosDenshion;

// Initialize the UI for the main game scene
//
// return - false if there was an error in initializing, true otherwise
bool UILayer::init()
{
    CCLabelTTF*      labelPause;  // the text for pause menu item
    CCMenuItemLabel* itemPause;   // menu item for opening the pause menu
    CCMenu*          menu;        // menu to contain the menu item
    CCSize           size;        // the size of the window

    if(!CCLayer::init())
    {
        return false;
    }

    // get the window size from the director
    size = CCDirector::sharedDirector()->getWinSize();

    // create the pause menu item
    labelPause = CCLabelTTF::create("Pause", MENU_FONT_STYLE, MENU_FONT_SIZE);
    itemPause  = CCMenuItemLabel::create(labelPause, this, menu_selector(UILayer::HandlePausePressed));
    itemPause->setColor(MENU_COLOR);
    itemPause->setPosition(size.width * PAUSE_WIDTH_POS, size.height * PAUSE_HEIGHT_POS);

    // create the menu containing the pause item
    menu = CCMenu::create(itemPause, NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu, 1);

    return true;
}

// On selecting the pause menu item, pause the game and bring up the pause menu
//
// sender [in] - the object that sent the selected event
void UILayer::HandlePausePressed(CCObject* sender)
{
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    CCDirector::sharedDirector()->pushScene(PauseLayer::Scene());
}
