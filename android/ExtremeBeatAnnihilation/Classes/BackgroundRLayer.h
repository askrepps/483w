#ifndef __BACKGROUND_R_LAYER_H__
#define __BACKGROUND_R_LAYER_H__

#include "cocos2d.h"

#include "Global.h"

#include "ClipNode.h"

#define RIGHT_BACKGROUND "night_background_inverted.png"      // image to display for the background

class BackgroundRLayer : public cocos2d::CCLayer
{
public:
    virtual bool init();
    virtual void update(float delta);

    // allows use of create() function which uses init() to create this layer
    CREATE_FUNC(BackgroundRLayer);

private:
    cocos2d::CCSprite* m_background1;       // these two background sprites will be placed next to each
    cocos2d::CCSprite* m_background2;       //   other and shifted right on every update
};

#endif // __BACKGROUND_R_LAYER_H__
