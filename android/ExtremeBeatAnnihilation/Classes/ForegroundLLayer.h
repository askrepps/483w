#ifndef __FOREGROUND_L_LAYER_H__
#define __FOREGROUND_L_LAYER_H__

#include "cocos2d.h"

#include "Global.h"

#include "PlayerL.h"

class ForegroundLLayer : public cocos2d::CCLayer
{
public:
    virtual bool init();
    virtual void ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event);

    // allows use of create() function which uses init() to create this layer
    CREATE_FUNC(ForegroundLLayer);

private:
    PlayerL* m_player;                           // player sprite
};

#endif // __FOREGROUND_L_LAYER_H__
