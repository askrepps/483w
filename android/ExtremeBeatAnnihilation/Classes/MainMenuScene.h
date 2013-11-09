#ifndef __MAIN_MENU_SCENE_H__
#define __MAIN_MENU_SCENE_H__

#include "cocos2d.h"

class MainMenu : public cocos2d::CCLayer
{
public:
    virtual bool              init();
    static  cocos2d::CCScene* Scene();

    void CallbackSelectSinglePlayer(CCObject* sender);
    void CallbackSelectMultiplayer(CCObject* sender);
    void CallbackSelectOptions(CCObject* sender);
    void CallbackSelectExit(CCObject* sender);

    // implement the "static node()" method manually
    CREATE_FUNC(MainMenu);
};

#endif // __MAIN_MENU_SCENE_H__
