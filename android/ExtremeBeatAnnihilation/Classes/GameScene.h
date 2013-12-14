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
#include "UILayer.h"

extern std::vector<Obstacle> leftSongObstacles;
extern std::vector<Obstacle> rightSongObstacles;

class GameScene : public cocos2d::CCScene
{
public:
    virtual bool init();

    void ScheduleAllUpdates();

    // allows use of create() function which uses init() to create this scene
    CREATE_FUNC(GameScene);

private:
    BackgroundRLayer* m_backgroundR;      // background for the right player's screen
    BackgroundLLayer* m_backgroundL;      // background for the left player's screen
    ForegroundRLayer* m_foregroundR;      // foreground (like obstacles) for the right player's screen
    ForegroundLLayer* m_foregroundL;      // foreground (like obstacles) for the left player's screen
};

#endif // __GAME_SCENE_H__
