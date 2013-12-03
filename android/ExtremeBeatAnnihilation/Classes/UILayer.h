#ifndef __UI_LAYER_H__
#define __UI_LAYER_H__

#include "cocos2d.h"

#define PAUSE_WIDTH_POS      0.9                 // factor of screen with to position pause menu item
#define PAUSE_HEIGHT_POS     0.1                 // factor of screen height to position pause menu item
#define MENU_COLOR           ccc3(255, 255, 255) // RGB color of the menu items
#define MENU_FONT_SIZE       50                  // size of the font for the menu items
#define MENU_FONT_STYLE      "Arial"             // style of the font for the menu items

class UILayer : public cocos2d::CCLayer
{
public:
    virtual bool init();

    void HandlePausePressed(CCObject* sender);

    // allows use of create() function which uses init() to create this layer
    CREATE_FUNC(UILayer);
};

#endif // __UI_LAYER_H__
