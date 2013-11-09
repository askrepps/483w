#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* MainMenu::Scene()
{
    CCScene*  scene = CCScene::create();
    MainMenu* layer = MainMenu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::Init()
{
    CCSize           size;           // the size of the window
    CCMenuItemImage* closeItem;      // the icon to click to close the app
    CCMenu*          menu;           // menu to contain the closeItem
    CCLabelTTF*      label;          // label to display "Main Menu"
    CCSprite*        sprite;         // the background splashscreen

    if(!CCLayer::init())
    {
        return false;
    }

    // get the window size from the director
    size = CCDirector::sharedDirector()->getWinSize();

    // add a "close" icon to exit the app
    closeItem = CCMenuItemImage::create("CloseNormal.png", "CloseSelected.png", this,
                                           menu_selector(MainMenu::MenuCloseCallback));
    closeItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    // create menu to contain closeItem
    menu = CCMenu::create(closeItem, NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu, 1);

    // add a label that shows "Main Menu" on the center of the screen
    label = CCLabelTTF::create("Main Menu", "Thonburi", 34);
    label->setPosition( ccp(size.width / 2, size.height - 20) );
    this->addChild(label, 1);

    // add splash screen as a sprite on the center of the screen
    sprite = CCSprite::create("splashscreen.jpg");
    sprite->setPosition( ccp(size.width / 2, size.height / 2) );
    this->addChild(sprite, 0);

    return true;
}

// a selector callback
void MainMenu::MenuCloseCallback(CCObject* sender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
