#ifndef __MUSIC_SELECT_SCENE_H__
#define __MUSIC_SELECT_SCENE_H__

#include "cocos2d.h"
#include "SampleMusicScene.h"
//#include "YourMusicScene.h"
#include "CharacterSelectScene.h"

#define POS_HEADER_HEIGHT    0.9                 // factor of height to position the header
#define BACKGROUND_IMAGE     "splashscreen.jpg"  // image to display as the background
#define MENU_COLOR           ccc3(255, 255, 255) // RGB color of the menu items
#define MENU_FONT_SIZE       50                  // size of the font for the menu items
#define MENU_FONT_STYLE      "Arial"             // style of the font for the menu items
#define MENU_ITEM_PADDING    20                  // padding between menu items, most likely in pixels

class MusicSelect : public cocos2d::CCLayer
{
public:
    virtual bool              init();
    static  cocos2d::CCScene* Scene();

    void HandleSampleMusicPressed(CCObject* sender);
    void HandleYourMusicPressed(CCObject* sender);
    void HandleBackPressed(CCObject* sender);

    // allows use of create() function which uses init() to create this layer
    CREATE_FUNC(MusicSelect);
};

#endif // __MUSIC_SELECT_SCENE_H__
