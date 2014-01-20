#ifndef __OBSTACLE_H__
#define __OBSTACLE_H__

#include "cocos2d.h"

#include "Global.h"

class Obstacle : public cocos2d::CCSprite
{
public:
    void InitWithPositionAndType(int x, int type);
};

#endif // __OBSTACLE_H__
