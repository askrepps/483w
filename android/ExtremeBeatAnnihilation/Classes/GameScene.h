#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "BackgroundRLayer.h"
#include "BackgroundLLayer.h"
#include "ForegroundRLayer.h"
#include "ForegroundLLayer.h"
#include "PlayerRLayer.h"
#include "PlayerLLayer.h"
#include "UILayer.h"

class GameScene : public cocos2d::CCScene
{
public:
    virtual bool init();

    // allows use of create() function which uses init() to create this scene
    CREATE_FUNC(GameScene);
};

#endif // __GAME_SCENE_H__
