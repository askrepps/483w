#ifndef __SAMPLE_MUSIC_SCENE_H__
#define __SAMPLE_MUSIC_SCENE_H__

#include <string>

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

#include "Global.h"

#include "GameScene.h"
#include "MusicSelectScene.h"

#define POS_HEADER_HEIGHT    0.9                 // factor of height to position the header

#define BACKGROUND_IMAGE     "splashscreen.jpg"  // image to display as the background

#define MENU_COLOR           ccc3(255, 255, 255) // RGB color of the menu items
#define MENU_FONT_SIZE       50                  // size of the font for the menu items
#define MENU_FONT_STYLE      "Arial"             // style of the font for the menu items
#define MENU_ITEM_PADDING    20                  // padding between menu items, most likely in pixels

#define FIRST_SONG           "Music/LettingGo.mp3"
#define SECOND_SONG          "Music/TheCallOfStars.mp3"
#define THIRD_SONG           ""

class SampleMusic : public cocos2d::CCLayer
{
public:
    virtual bool              init();
    static  cocos2d::CCScene* Scene();

    void HandleFirstSongPressed(CCObject* sender);
    void HandleSecondSongPressed(CCObject* sender);
    void HandleThirdSongPressed(CCObject* sender);
    void HandleBackPressed(CCObject* sender);

    // allows use of create() function which uses init() to create this layer
    CREATE_FUNC(SampleMusic);
};

#endif // __SAMPLE_MUSIC_SCENE_H__
