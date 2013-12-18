#include "OptionsMenuScene.h"

using namespace cocos2d;
using namespace extension;
using namespace CocosDenshion;

// externs defined in Global.h
extern bool  Prev_Was_Main_Menu;
extern bool  Allow_Volume_Set;
extern float Music_Volume;
extern float SFX_Volume;

//Returns a scene for from the layer
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
    CCMenuItemLabel* backItem;
    CCMenu*          menu;
    CCLabelTTF*      backLabel;                 // the text for the back menu item
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
    backLabel = CCLabelTTF::create("BACK", FONT_STYLE, 34);
    backItem  = CCMenuItemLabel::create(backLabel, this, menu_selector(OptionsMenu::MenuGoBack));
    backItem->setPosition(ccp(size.width / 2, 20));

    // create menu
    menu = CCMenu::create(backItem, NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu, 1);

    // add a label that shows "Main Menu" on the center of the screen
    label = CCLabelTTF::create("OPTIONS", FONT_STYLE, 34);
    label->setPosition( ccp(size.width / 2, size.height - 20) );
    this->addChild(label, 1);

    // add a label that shows "Volume" next to the volume slider bar
    volumelabel = CCLabelTTF::create("MUSIC", FONT_STYLE, 34);
    volumelabel->setPosition( ccp(60, (2*size.height/3) - 20) );
    this->addChild(volumelabel, 1);

    // add a label that shows "SFX" next to the sfx slider bar
    sfxlabel = CCLabelTTF::create("SFX", FONT_STYLE, 34);
    sfxlabel->setPosition( ccp(70, (size.height/3) - 20) );
    this->addChild(sfxlabel, 1);

    // adds volume slider to the screen
    volume = CCControlSlider::create("sliderTrack-hd.png", "sliderProgress-hd.png", "sliderThumb-hd.png");
    volume->addTargetWithActionForControlEvents(this, cccontrol_selector(OptionsMenu::HandleMusicSliderChanged),
                                                                                      CCControlEventValueChanged);
    volume->setMinimumValue(0);
    volume->setMaximumValue(100);
    volume->setValue(Music_Volume);
    volume->setPosition( ccp(size.width / 2, (2*size.height/3) - 20));
    this->addChild(volume, 1);

    // adds sfx slider to the screen
    sfx = CCControlSlider::create("sliderTrack-hd.png", "sliderProgress-hd.png", "sliderThumb-hd.png");
    sfx->addTargetWithActionForControlEvents(this, cccontrol_selector(OptionsMenu::HandleSfxSliderChanged),
                                                                                 CCControlEventValueChanged);
    sfx->setMinimumValue(0);
    sfx->setMaximumValue(100);
    sfx->setValue(SFX_Volume);
    sfx->setPosition( ccp(size.width / 2, (size.height/3) - 20));
    this->addChild(sfx, 1);

    Allow_Volume_Set = true;          // not that sliders are initialized, volume levels can change

    return true;
}

// Update the background music volume whenever the value of the slider is changed
//
// slider [in] - the slider that changed its value
void OptionsMenu::HandleMusicSliderChanged(CCControlSlider* slider)
{
    if (Allow_Volume_Set)            // everything's been initialized, so allow volume setting
    {
        Music_Volume = slider->getValue();
        SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(Music_Volume / VOLUME_FACTOR);
    }
}

// Update the sound effects volume whenever the value of the slider is changed
//
// slider [in] - the slider that changed its value
void OptionsMenu::HandleSfxSliderChanged(CCControlSlider* slider)
{
    if (Allow_Volume_Set)            // everything's been initialized, so allow volume setting
    {
        SFX_Volume = slider->getValue();
        SimpleAudioEngine::sharedEngine()->setEffectsVolume(SFX_Volume / VOLUME_FACTOR);
    }
}

// Changes the scene back to the Main Menu
void OptionsMenu::MenuGoBack(CCObject* sender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("SFX/back.wav");
    if (Prev_Was_Main_Menu)                      // Go back to the main menu
    {
        CCDirector::sharedDirector()->replaceScene(MainMenu::Scene());
    }
    else                                         // Go back to pause scene
    {
        CCDirector::sharedDirector()->replaceScene(PauseLayer::Scene());
    }

    Allow_Volume_Set = false;    // set to false again, so volumes don't get set to default values upon
                                 //   return to the options menu
}
