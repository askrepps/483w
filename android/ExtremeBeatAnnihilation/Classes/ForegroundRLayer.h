#ifndef __FOREGROUND_R_LAYER_H__
#define __FOREGROUND_R_LAYER_H__

#include "cocos2d.h"
#include "Global.h"

class ForegroundRLayer : public cocos2d::CCLayer
{
public:
    virtual bool init();

    // allows use of create() function which uses init() to create this layer
    CREATE_FUNC(ForegroundRLayer);
};

#endif // __FOREGROUND_R_LAYER_H__
