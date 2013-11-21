#include "OptionsMenuScene.h"

using namespace cocos2d;
using namespace extension;
using namespace CocosDenshion;

CCScene* OptionsMenu::Scene()
{
    CCScene*     scene = CCScene::create();
    OptionsMenu* layer = OptionsMenu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool OptionsMenu::init()
{
    CCSize           size;
    CCMenuItemFont*  backItem;
    CCMenu*          menu;
    CCLabelTTF*      label;
    CCLabelTTF*      volumelabel;
    CCLabelTTF*      sfxlabel;
    CCControlSlider* volume;
    CCControlSlider* sfx;

    if(!CCLayer::init())
    {
        return false;
    }

    // get the window size from the director
    size = CCDirector::sharedDirector()->getWinSize();

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
    volume = CCControlSlider::create("sliderTrack-hd.png", "sliderProgress-hd.png", "sliderThumb-hd.png");
    volume->addTargetWithActionForControlEvents(this, cccontrol_selector(OptionsMenu::HandleMusicSliderChanged),
                                                                                      CCControlEventValueChanged);
    volume->setMinimumValue(0);
    volume->setMaximumValue(100);
    volume->setValue(50);
    volume->setPosition( ccp(size.width / 2, (2*size.height/3) - 20));
    this->addChild(volume, 1);

    // adds sfx slider to the screen
    sfx = CCControlSlider::create("sliderTrack-hd.png", "sliderProgress-hd.png", "sliderThumb-hd.png");
    sfx->addTargetWithActionForControlEvents(this, cccontrol_selector(OptionsMenu::HandleSfxSliderChanged),
                                                                                 CCControlEventValueChanged);
    sfx->setMinimumValue(0);
    sfx->setMaximumValue(100);
    sfx->setValue(50);
    sfx->setPosition( ccp(size.width / 2, (size.height/3) - 20));
    this->addChild(sfx, 1);

    return true;
}

// Update the background music volume whenever the value of the slider is changed
//
// slider [in] - the slider that changed its value
void OptionsMenu::HandleMusicSliderChanged(CCControlSlider* slider)
{
    SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(slider->getValue() / VOLUME_FACTOR);
}

// Update the sound effects volume whenever the value of the slider is changed
//
// slider [in] - the slider that changed its value
void OptionsMenu::HandleSfxSliderChanged(CCControlSlider* slider)
{
    SimpleAudioEngine::sharedEngine()->setEffectsVolume(slider->getValue() / VOLUME_FACTOR);
}

void OptionsMenu::MenuGoBack(CCObject* sender)
{
	// Go back to the main menu
	CCDirector::sharedDirector()->replaceScene(MainMenu::Scene());
}
