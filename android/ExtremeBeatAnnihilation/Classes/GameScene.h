#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include <string>

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

#include "Global.h"

#include "BackgroundRLayer.h"
#include "BackgroundLLayer.h"
#include "ForegroundRLayer.h"
#include "ForegroundLLayer.h"
#include "PlayerRLayer.h"
#include "PlayerLLayer.h"
#include "UILayer.h"
#include "PlayerR.h"
#include "PlayerL.h"

class GameScene : public cocos2d::CCScene
{
public:
    virtual bool init();

    void ccTouchesBegin( cocos2d::CCSet * ptouches, cocos2d::CCEvent * event );


    // allows use of create() function which uses init() to create this scene
    CREATE_FUNC(GameScene);

private:
    PlayerR* rightPlayer; 		// left player sprite
    PlayerL* leftPlayer;		// right player sprite
};

#endif // __GAME_SCENE_H__
