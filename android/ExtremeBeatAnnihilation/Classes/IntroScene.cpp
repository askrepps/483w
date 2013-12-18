#include "IntroScene.h"

using namespace cocos2d;
using namespace CocosDenshion;

// Initialize the intro scene
//
// return - false if there was an error in initializing, true otherwise
bool IntroScene::init()
{
    CCSize      size;              // the size of the window
    CCSprite*   logo;              // the development group logo
    CCSprite*   logoBackground;    // the background for the logo
    CCLabelTTF* note;              // the text to tell user to tap screen

    if(!CCLayer::init())
    {
        return false;
    }

    // get the window size from the director
    size = CCDirector::sharedDirector()->getWinSize();

    // add the logo background
    logoBackground = CCSprite::create(LOGO_BACKGROUND);
    logoBackground->setScaleX(size.width / logoBackground->boundingBox().size.width);
    logoBackground->setScaleY(size.height / logoBackground->boundingBox().size.height);
    logoBackground->setPosition( ccp(size.width * POS_HALF_SCREEN, size.height * POS_HALF_SCREEN) );
    addChild(logoBackground, 0);

    // add the logo sprite
    logo = CCSprite::create(LOGO_IMAGE);
    logo->setScale(size.height * LOGO_HEIGHT_SCALE / logo->boundingBox().size.height);
    logo->setPosition( ccp(size.width * POS_HALF_SCREEN, size.height * POS_LOGO_HEIGHT) );
    addChild(logo, 1);

    // create the note for the bottom of the screen
    note = CCLabelTTF::create("Tap screen to continue...", FONT_STYLE, INTRO_FONT_SIZE);
    note->setPosition( ccp(size.width * POS_HALF_SCREEN, size.height * POS_NOTE_HEIGHT) );
    note->setColor(INTRO_FONT_COLOR);
    this->addChild(note, 1);

    // enable screen touches to be detected
    setTouchEnabled(true);
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);

    return true;
}

// switch to the main menu scene when user touches the screen
//
// touch [in] - ?
// event [in] - ?
void IntroScene::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.0, MainMenu::Scene()));
}

// Create an intro scene that has a IntroScene layer
//
// return - a newly created intro scene
CCScene* IntroScene::Scene()
{
    CCScene*    scene = CCScene::create();      // the intro scene to return
    IntroScene* layer = IntroScene::create();   // the layer for the scene

    scene->addChild(layer);

    return scene;
}
