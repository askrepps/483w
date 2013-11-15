#ifndef __MAINGAME_SCENE_H__
#define __MAINGAME_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

class MainGame : public cocos2d::CCLayer
{
public:
    virtual bool init();

    // there's no 'id' for android cocos2d, so we recommend to returning the exact class pointer
    static cocos2d::CCScene* Scene();

    // a selector callback
    void menuCloseCallback(CCObject* pSender);

    // allows use of create() function which uses init() to create this layer
    CREATE_FUNC(MainGame);
};

#endif // __MAINGAME_SCENE_H__
