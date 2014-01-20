#ifndef __FOREGROUND_L_LAYER_H__
#define __FOREGROUND_L_LAYER_H__

#include "cocos2d.h"

#include "Global.h"

#include "PlayerL.h"
#include "ClipNode.h"

class ForegroundLLayer : public cocos2d::CCLayer
{
public:
    virtual bool init();
    virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);

    void UpdateLayer(float delta);
    void SpawnSlideObstacle(void);
    void SpawnJumpObstacle(void);

    // allows use of create() function which uses init() to create this layer
    CREATE_FUNC(ForegroundLLayer);

private:
    PlayerL*           m_player;                 // player sprite
    cocos2d::ClipNode* m_clipNode;				 // Clip node for obstacles
    bool               m_firstUpdate;            // true when the next call to update is the first call
};

#endif // __FOREGROUND_L_LAYER_H__
