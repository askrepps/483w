#ifndef __PLAYER_R_LAYER_H__
#define __PLAYER_R_LAYER_H__

#include "cocos2d.h"

class PlayerRLayer : public cocos2d::CCLayer
{
public:
    virtual bool init();

    // allows use of create() function which uses init() to create this layer
    CREATE_FUNC(PlayerRLayer);
};

#endif // __PLAYER_R_LAYER_H__
