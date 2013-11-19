#ifndef __FOREGROUND_L_LAYER_H__
#define __FOREGROUND_L_LAYER_H__

#include "cocos2d.h"
#include "Global.h"

class ForegroundLLayer : public cocos2d::CCLayer
{
public:
    virtual bool init();

    // allows use of create() function which uses init() to create this layer
    CREATE_FUNC(ForegroundLLayer);
};

#endif // __FOREGROUND_L_LAYER_H__
