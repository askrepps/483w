#include "OptionsMenuScene.h"
#include "SimpleAudioEngine.h"
#include "CCControlSlider.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* OptionsMenu::Scene()
{
    CCScene*  scene = CCScene::create();
    OptionsMenu* layer = OptionsMenu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool OptionsMenu::Init()
{
    CCSize           size;
    CCMenuItemImage* closeItem;
    CCMenu*          menu;
    CCLabelTTF*      label;
    CCSprite*        sprite;
    cocos2d::extension::CCControlSlider* volume;
    cocos2d::extension::CCControlSlider* sfx;

    if(!CCLayer::init())
    {
        return false;
    }

    // get the window size from the director
    size = CCDirector::sharedDirector()->getWinSize();

    // add a "close" icon to exit the process
    closeItem = CCMenuItemImage::create("CloseNormal.png", "CloseSelected.png", this,
                                           menu_selector(OptionsMenu::MenuCloseCallback));
    closeItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    // create menu
    menu = CCMenu::create(closeItem, NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu, 1);

    // add a label that shows "Main Menu" on the center of the screen
    label = CCLabelTTF::create("OPTIONS", "Thonburi", 34);
    label->setPosition( ccp(size.width / 2, size.height - 20) );
    this->addChild(label, 1);

    // add splash screen as a sprite on the center of the screen
    sprite = CCSprite::create("splashscreen.jpg");
    sprite->setPosition( ccp(size.width / 2, size.height / 2) );
    this->addChild(sprite, 0);

    // adds a slider to the screen
    volume = cocos2d::extension::CCControlSlider::create("sliderTrack.png", "sliderProgress.png", "sliderThumb.png");
    volume->setMinimumValue(0);
    volume->setMaximumValue(100);
    volume->setValue(50);
    volume->setPosition( ccp(size.width / 2, size.height - 20));
    this->addChild(volume, 1);
    return true;
}

// a selector callback
void OptionsMenu::MenuCloseCallback(CCObject* sender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
