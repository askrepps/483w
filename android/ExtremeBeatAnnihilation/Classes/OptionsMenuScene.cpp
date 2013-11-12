#include "OptionsMenuScene.h"


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
bool OptionsMenu::init()
{
    CCSize           size;
    CCMenuItemFont* backItem;
    CCMenu*          menu;
    CCLabelTTF*      label;
    CCLabelTTF*      volumelabel;
    CCLabelTTF*      sfxlabel;
    cocos2d::extension::CCControlSlider* volume;
    cocos2d::extension::CCControlSlider* sfx;

    if(!CCLayer::init())
    {
        return false;
    }

    // get the window size from the director
    size = CCDirector::sharedDirector()->getWinSize();

    // add a "close" icon to exit the process
    //closeItem = CCMenuItemImage::create("CloseNormal.png", "CloseSelected.png", this,
    //                                       menu_selector(OptionsMenu::MenuCloseCallback));
    //closeItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    // Add a "Back" Button to go back to main menu
    backItem = CCMenuItemFont::create("BACK", this, menu_selector(OptionsMenu::MenuGoBack));
    backItem->setPosition(ccp(size.width / 2, 20));

    // create menu
    menu = CCMenu::create(backItem, NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu, 1);

    // add a label that shows "Main Menu" on the center of the screen
    label = CCLabelTTF::create("OPTIONS", "Thonburi", 34);
    label->setPosition( ccp(size.width / 2, size.height - 20) );
    this->addChild(label, 1);

    // add a label that shows "Volume" next to the volume slider bar
    volumelabel = CCLabelTTF::create("MUSIC", "Thonburi", 34);
    volumelabel->setPosition( ccp(60, (2*size.height/3) - 20) );
    this->addChild(volumelabel, 1);

    // add a label that shows "SFX" next to the sfx slider bar
    sfxlabel = CCLabelTTF::create("SFX", "Thonburi", 34);
    sfxlabel->setPosition( ccp(70, (size.height/3) - 20) );
    this->addChild(sfxlabel, 1);

    // adds volume slider to the screen
    volume = cocos2d::extension::CCControlSlider::create("sliderTrack-hd.png", "sliderProgress-hd.png", "sliderThumb-hd.png");
    volume->setMinimumValue(0);
    volume->setMaximumValue(100);
    volume->setValue(50);
    volume->setPosition( ccp(size.width / 2, (2*size.height/3) - 20));
    this->addChild(volume, 1);

    // adds sfx slider to the screen
    sfx = cocos2d::extension::CCControlSlider::create("sliderTrack-hd.png", "sliderProgress-hd.png", "sliderThumb-hd.png");
    sfx->setMinimumValue(0);
    sfx->setMaximumValue(100);
    sfx->setValue(50);
    sfx->setPosition( ccp(size.width / 2, (size.height/3) - 20));
    this->addChild(sfx, 1);

    return true;
}

void OptionsMenu::MenuGoBack(CCObject* sender)
{
	// Go back to the main menu
	CCDirector::sharedDirector()->replaceScene(MainMenu::Scene());
}


/*// a selector callback
void OptionsMenu::MenuCloseCallback(CCObject* sender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
*/
