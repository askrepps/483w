#ifndef __UI_LAYER_H__
#define __UI_LAYER_H__

#include "cocos2d.h"

class UILayer : public cocos2d::CCLayer
{
public:
    virtual bool init();

    // allows use of create() function which uses init() to create this layer
    CREATE_FUNC(UILayer);
};

#endif // __UI_LAYER_H__
