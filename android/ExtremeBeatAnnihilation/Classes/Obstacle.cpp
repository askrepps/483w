#include "Obstacle.h"

using namespace cocos2d;

Obstacle::Obstacle(int x, int type)
{
	if(!InitWithPosAndType(x, type))
		CCLog("Obstacle failed to initialize");
}

bool Obstacle::InitWithPosAndType(int x, int type)
{
	switch(type)
	{
	case JUMPING_OBSTACLE:
		CCSprite::initWithFile(JUMPING_SPRITE);
		break;
	case SLIDING_OBSTACLE:
		CCSprite::initWithFile(SLIDING_SPRITE);
		break;
	default:
		CCLog("Illegal Obstacle Type");
	}

	m_xPos = x;

	return true;
}
