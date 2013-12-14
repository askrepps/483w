#ifndef __OBSTACLE_H__
#define __OBSTACLE_H__

#include "cocos2d.h"

#include "Global.h"
class Obstacle : public cocos2d::CCSprite
{
public:
	Obstacle(int x, int type);
protected:
	bool InitWithPosAndType(int x, int type);
private:
	int m_xPos;
	int m_yPos;
};

#endif // __OBSTACLE_H__
