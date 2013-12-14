#include "SampleMusicScene.h"

using namespace cocos2d;
using namespace CocosDenshion;

// externs defined in Global.h
extern std::string Game_Song;

// Initialize the menu items, background, and overall setup of the sample music menu
//
// return - false if there was an error in initializing, true otherwise
bool SampleMusic::init()
{
    CCLabelTTF*      labelFirstSong;    // the text for the first song menu item
    CCLabelTTF*      labelSecondSong;   // the text for the second song menu item
    CCLabelTTF*      labelThirdSong;    // the text for the third song menu item
    CCLabelTTF*      labelBack;         // the text for back menu item
    CCMenuItemLabel* itemFirstSong;     // menu item for choosing the first song
    CCMenuItemLabel* itemSecondSong;    // menu item for choosing the second song
    CCMenuItemLabel* itemThirdSong;     // menu item for choosing the third song
    CCMenuItemLabel* itemBack;          // menu item for going back to music select
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
    header = CCLabelTTF::create("Choose from the sample songs", MENU_FONT_STYLE, MENU_FONT_SIZE);
    header->setPosition( ccp(size.width * POS_HALF_SCREEN, size.height * POS_HEADER_HEIGHT) );
    this->addChild(header, 1);

    // create the text for the menu items
    labelFirstSong  = CCLabelTTF::create("Letting Go by UltraMax", MENU_FONT_STYLE, MENU_FONT_SIZE);
    labelSecondSong = CCLabelTTF::create("The Call of Stars by UltraMax", MENU_FONT_STYLE, MENU_FONT_SIZE);
    labelThirdSong  = CCLabelTTF::create("Insert Song by Artist", MENU_FONT_STYLE, MENU_FONT_SIZE);
    labelBack       = CCLabelTTF::create("Back", MENU_FONT_STYLE, MENU_FONT_SIZE);

    // create the items for the menu
    itemFirstSong  = CCMenuItemLabel::create(labelFirstSong, this, menu_selector(SampleMusic::HandleFirstSongPressed));
    itemSecondSong = CCMenuItemLabel::create(labelSecondSong, this, menu_selector(SampleMusic::HandleSecondSongPressed));
    itemThirdSong  = CCMenuItemLabel::create(labelThirdSong, this, menu_selector(SampleMusic::HandleThirdSongPressed));
    itemBack       = CCMenuItemLabel::create(labelBack, this, menu_selector(SampleMusic::HandleBackPressed));

    // set the color of the menu items
    itemFirstSong->setColor(MENU_COLOR);
    itemSecondSong->setColor(MENU_COLOR);
    itemThirdSong->setColor(MENU_COLOR);
    itemBack->setColor(MENU_COLOR);

    // create menu to contain the menu items
    menu = CCMenu::create(itemFirstSong, itemSecondSong, itemThirdSong, itemBack, NULL);
    menu->alignItemsVerticallyWithPadding(MENU_ITEM_PADDING);
    menu->setPosition(size.width * POS_HALF_SCREEN, size.height * POS_HALF_SCREEN);
    this->addChild(menu, 1);

    return true;
}

// Create a sample music scene that has a SampleMusic layer
//
// return - a newly created sample music scene
CCScene* SampleMusic::Scene()
{
    CCScene*     scene = CCScene::create();       // the sample music scene to return
    SampleMusic* layer = SampleMusic::create();   // the layer for the scene

    scene->addChild(layer);

    return scene;
}

// On selecting the first song menu item, switch to the game scene using the song selected
//
// sender [in] - the object that sent the selected event?
void SampleMusic::HandleFirstSongPressed(CCObject* sender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("SFX/select.wav");
    Game_Song = FIRST_SONG;
    CCDirector::sharedDirector()->replaceScene(LoadScene::Scene());
}

// On selecting the second song menu item, switch to the game scene using the song selected
//
// sender [in] - the object that sent the selected event?
void SampleMusic::HandleSecondSongPressed(CCObject* sender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("SFX/select.wav");
    Game_Song = SECOND_SONG;
    CCDirector::sharedDirector()->replaceScene(LoadScene::Scene());
}

// On selecting the third song menu item, switch to the game scene using the song selected
//
// sender [in] - the object that sent the selected event?
void SampleMusic::HandleThirdSongPressed(CCObject* sender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("SFX/select.wav");
    Game_Song = THIRD_SONG;
    CCDirector::sharedDirector()->replaceScene(LoadScene::Scene());
}

// On selecting the back menu item, switch back to music select scene
//
// sender [in] - the object that sent the selected event?
void SampleMusic::HandleBackPressed(CCObject* sender)
{
    SimpleAudioEngine::sharedEngine()->playEffect("SFX/back.wav");
    CCDirector::sharedDirector()->replaceScene(MusicSelect::Scene());
}
