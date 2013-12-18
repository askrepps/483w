#ifndef __LOAD_SCENE_H__
#define __LOAD_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include <unistd.h>

#include "GameScene.h"
#include "Global.h"

#define MENU_COLOR           ccc3(255, 255, 255) // RGB color of the menu items
#define MENU_FONT_SIZE       50                  // size of the font for the menu items
#define MENU_ITEM_PADDING    20                  // padding between menu items, most likely in pixels

extern std::vector<Obstacle> leftSongObstacles;	 // In Global.cpp, stores the obstacles for the left 9 half of the game
extern std::vector<Obstacle> rightSongObstacles; // In Global.cpp, stores the obstacles for the right half of the  game

class LoadScene : public cocos2d::CCLayer
{
public:
    virtual bool              init();
    static  cocos2d::CCScene* Scene();
private:
    void GenerateObstacles();

    // allows use of create() function which uses init() to create this layer
    CREATE_FUNC(LoadScene);
};

#endif // __LOAD_SCENE_H__
