#ifndef __MAIN_MENU_SCENE_H__
#define __MAIN_MENU_SCENE_H__

#include "cocos2d.h"

class MainMenu : public cocos2d::CCLayer
{
public:
    virtual bool init();

    // there's no 'id' for android cocos2d, so we recommend to returning the exact class pointer
    static cocos2d::CCScene* scene();

    // a selector callback
    void menuCloseCallback(CCObject* pSender);

    // implement the "static node()" method manually
    CREATE_FUNC(MainMenu);
};

#endif // __MAIN_MENU_SCENE_H__
