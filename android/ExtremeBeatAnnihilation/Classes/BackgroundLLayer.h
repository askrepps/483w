#ifndef __BACKGROUND_L_LAYER_H__
#define __BACKGROUND_L_LAYER_H__

#include "cocos2d.h"
#include "Global.h"

class BackgroundLLayer : public cocos2d::CCLayer
{
public:
    virtual bool init();

    // allows use of create() function which uses init() to create this layer
    CREATE_FUNC(BackgroundLLayer);
};

#endif // __BACKGROUND_L_LAYER_H__
