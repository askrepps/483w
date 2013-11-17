#ifndef __PLAYER_L_LAYER_H__
#define __PLAYER_L_LAYER_H__

#include "cocos2d.h"

class PlayerLLayer : public cocos2d::CCLayer
{
public:
    virtual bool init();

    // allows use of create() function which uses init() to create this layer
    CREATE_FUNC(PlayerLLayer);
};

#endif // __PLAYER_L_LAYER_H__
