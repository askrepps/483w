#ifndef __BACKGROUND_R_LAYER_H__
#define __BACKGROUND_R_LAYER_H__

#include "cocos2d.h"
#include "Global.h"

class BackgroundRLayer : public cocos2d::CCLayer
{
public:
    virtual bool init();

    // allows use of create() function which uses init() to create this layer
    CREATE_FUNC(BackgroundRLayer);
};

#endif // __BACKGROUND_R_LAYER_H__
