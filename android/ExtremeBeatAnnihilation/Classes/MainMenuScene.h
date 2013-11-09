#ifndef __MAIN_MENU_SCENE_H__
#define __MAIN_MENU_SCENE_H__

#include "cocos2d.h"

class MainMenu : public cocos2d::CCLayer
{
public:
    virtual bool              init();
    static  cocos2d::CCScene* scene();
            void              MenuCloseCallback(CCObject* pSender);

    // implement the "static node()" method manually
    CREATE_FUNC(MainMenu);
};

#endif // __MAIN_MENU_SCENE_H__
