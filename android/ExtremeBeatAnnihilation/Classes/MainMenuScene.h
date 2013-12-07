#ifndef __MAIN_MENU_SCENE_H__
#define __MAIN_MENU_SCENE_H__

#include "cocos2d.h"

#include "Global.h"

#include "CharacterSelectScene.h"
#include "OptionsMenuScene.h"

#define BACKGROUND_IMAGE     "splashscreen.jpg"  // image to display as the background
#define MENU_COLOR           ccc3(255, 255, 255) // RGB color of the menu items
#define MENU_FONT_SIZE       50                  // size of the font for the menu items
#define MENU_FONT_STYLE      "Arial"             // style of the font for the menu items
#define MENU_ITEM_PADDING    20                  // padding between menu items, most likely in pixels

class MainMenu : public cocos2d::CCLayer
{
public:
    virtual bool              init();
    static  cocos2d::CCScene* Scene();

    void HandleSinglePlayerPressed(CCObject* sender);
    void HandleMultiplayerPressed(CCObject* sender);
    void HandleOptionsPressed(CCObject* sender);

    // allows use of create() function which uses init() to create this layer
    CREATE_FUNC(MainMenu);
};

#endif // __MAIN_MENU_SCENE_H__
