#ifndef __BACKGROUND_L_LAYER_H__
#define __BACKGROUND_L_LAYER_H__

#include "cocos2d.h"

#include "Global.h"

#include "ClipNode.h"

#define LEFT_BACKGROUND "background.png"      // image to display for the background

class BackgroundLLayer : public cocos2d::CCLayer
{
public:
    virtual bool init();
    void UpdateLayer(float delta);

    // allows use of create() function which uses init() to create this layer
    CREATE_FUNC(BackgroundLLayer);

private:
    cocos2d::CCSprite* m_background1;       // these two background sprites will be placed next to each
    cocos2d::CCSprite* m_background2;       //   other and shifted left on every update
};

#endif // __BACKGROUND_L_LAYER_H__
