#ifndef __FOREGROUND_R_LAYER_H__
#define __FOREGROUND_R_LAYER_H__

#include "cocos2d.h"

#include "Global.h"

#include "PlayerR.h"

class ForegroundRLayer : public cocos2d::CCLayer
{
public:
    virtual bool init();
    virtual void ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event);

    // allows use of create() function which uses init() to create this layer
    CREATE_FUNC(ForegroundRLayer);

private:
    PlayerR* m_player;                       // player sprite
};

#endif // __FOREGROUND_R_LAYER_H__
