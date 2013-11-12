#ifndef __MAIN_MENU_SCENE_H__
#define __MAIN_MENU_SCENE_H__

#include "cocos2d.h"
#include "CharacterSelectScene.h"
#include "OptionsMenuScene.h"

#define POSITION_HALF_SCREEN 0.5                 // factor of width/height which give a position halfway
#define BACKGROUND_IMAGE     "splashscreen.jpg"  // image to display as the background
#define MENU_COLOR           ccc3(255, 0, 0)     // RGB color of the menu items
#define MENU_FONT_SIZE       50                  // size of the font for the menu items
#define MENU_FONT_STYLE      "Thonburi"          // style of the font for the menu items

class MainMenu : public cocos2d::CCLayer
{
public:
    virtual bool              init();
    static  cocos2d::CCScene* Scene();

    void CallbackSelectSinglePlayer(CCObject* sender);
    void CallbackSelectMultiplayer(CCObject* sender);
    void CallbackSelectOptions(CCObject* sender);

    // implement the "static node()" method manually
    CREATE_FUNC(MainMenu);
};

#endif // __MAIN_MENU_SCENE_H__
