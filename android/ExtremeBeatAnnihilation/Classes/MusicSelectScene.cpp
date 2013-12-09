#include "MusicSelectScene.h"

using namespace cocos2d;
using namespace CocosDenshion;

// Initialize the menu items, background, and overall setup of the music selection menu
//
// return - false if there was an error in initializing, true otherwise
bool MusicSelect::init()
{
    CCLabelTTF*      labelSampleMusic;  // the text for sample music menu item
    CCLabelTTF*      labelYourMusic;    // the text for your music menu item
    CCLabelTTF*      labelBack;         // the text for back menu item
    CCMenuItemLabel* itemSampleMusic;   // menu item for opening sample music selection
    CCMenuItemLabel* itemYourMusic;     // menu item for opening your music selection
    CCMenuItemLabel* itemBack;          // menu item for going back to character select
    CCMenu*          menu;              // menu to contain the menu items

    CCLabelTTF*      header;            // the header font that tells the user what to do
    //CCSprite*        background;        // the background picture
    CCSize           size;              // the size of the window

    if(!CCLayer::init())
    {
        return false;
    }

    // get the window size from the director
    size = CCDirector::sharedDirector()->getWinSize();

    // create the header for the scene
    header = CCLabelTTF::create("Choose where you want to get your songs", MENU_FONT_STYLE, MENU_FONT_SIZE);
    header->setPosition( ccp(size.width * POS_HALF_SCREEN, size.height * POS_HEADER_HEIGHT) );
    this->addChild(header, 1);

    // create the text for the menu items
    labelSampleMusic = CCLabelTTF::create("Select Sample Music", MENU_FONT_STYLE, MENU_FONT_SIZE);
    labelYourMusic   = CCLabelTTF::create("Select Your Music", MENU_FONT_STYLE, MENU_FONT_SIZE);
    labelBack        = CCLabelTTF::create("Back", MENU_FONT_STYLE, MENU_FONT_SIZE);

    // create the items for the menu
    itemSampleMusic = CCMenuItemLabel::create(labelSampleMusic, this, menu_selector(MusicSelect::HandleSampleMusicPressed));
    itemYourMusic   = CCMenuItemLabel::create(labelYourMusic, this, menu_selector(MusicSelect::HandleYourMusicPressed));
    itemBack        = CCMenuItemLabel::create(labelBack, this, menu_selector(MusicSelect::HandleBackPressed));

    // set the color of the menu items
    itemSampleMusic->setColor(MENU_COLOR);
    itemYourMusic->setColor(MENU_COLOR);
    itemBack->setColor(MENU_COLOR);

    // create menu to contain the menu items
    menu = CCMenu::create(itemSampleMusic, itemYourMusic, itemBack, NULL);
    menu->alignItemsVerticallyWithPadding(MENU_ITEM_PADDING);
    menu->setPosition(size.width * POS_HALF_SCREEN, size.height * POS_HALF_SCREEN);
    this->addChild(menu, 1);

    // add splash screen as a sprite on the center of the screen
    //background = CCSprite::create(BACKGROUND_IMAGE);
    //background->setPosition( ccp(size.width * POS_HALF_SCREEN, size.height * POS_HALF_SCREEN) );
    //this->addChild(background, 0);

    return true;
}

// Create a music select scene that has a MusicSelect layer
//
// return - a newly created music select scene
CCScene* MusicSelect::Scene()
{
    CCScene*     scene = CCScene::create();       // the music select scene to return
    MusicSelect* layer = MusicSelect::create();   // the layer for the scene

    scene->addChild(layer);

    return scene;
}

// On selecting the sample music menu item, switch to the sample music scene
//
// sender [in] - the object that sent the selected event?
void MusicSelect::HandleSampleMusicPressed(CCObject* sender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("SFX/select.wav");
    CCDirector::sharedDirector()->replaceScene(SampleMusic::Scene());
}

// On selecting the your music menu item, switch to the your music scene
//
// sender [in] - the object that sent the selected event?
void MusicSelect::HandleYourMusicPressed(CCObject* sender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("SFX/select.wav");
    JavaVM* jvm = cocos2d::JniHelper::getJavaVM();
    if (NULL == jvm)
        CCLog("Failed to get the JavaVM");

    JNIEnv* env;
    jint ret = jvm->GetEnv((void**)&env, JNI_VERSION_1_4);
    if (ret != JNI_OK)
        CCLog("Failed to get then JNIEnv");

    jclass classRet = env->FindClass("org/cocos2dx/extbeatanni/ExtremeBeatAnnihilation");
    if (!classRet)
        CCLog("Failed to find class ExtremeBeatAnnihilation");

    jmethodID methodRet = env->GetMethodID(classRet, "startupFileExplore", "()V");
    if (!methodRet)
        CCLog("Failed to find method startupFileExplore");

    env->CallVoidMethod(classRet, methodRet);
}

// On selecting the back menu item, switch back to character select scene
//
// sender [in] - the object that sent the selected event?
void MusicSelect::HandleBackPressed(CCObject* sender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("SFX/back.wav");
    CCDirector::sharedDirector()->replaceScene(CharacterSelect::Scene());
}
