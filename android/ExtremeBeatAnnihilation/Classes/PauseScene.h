#ifndef __PAUSE_LAYER_H__
#define __PAUSE_LAYER_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

#include "Global.h"

#include "MainMenuScene.h"
#include "OptionsMenuScene.h"

#define POS_HEADER_HEIGHT    0.9                 // factor of height to position the header
#define MENU_COLOR           ccc3(255, 255, 255) // RGB color of the menu items
#define MENU_FONT_SIZE       50                  // size of the font for the menu items
#define MENU_ITEM_PADDING    20                  // padding between menu items, most likely in pixels

class PauseLayer : public cocos2d::CCLayer
{
public:
    virtual bool init();
    virtual void onEnter();

    static  cocos2d::CCScene* Scene();

    void HandleOptionsPressed(CCObject* sender);
    void HandleMainMenuPressed(CCObject* sender);
    void HandleResumePressed(CCObject* sender);

    // allows use of create() function which uses init() to create this layer
    CREATE_FUNC(PauseLayer);
};

#endif // __PAUSE_LAYER_H__
