#include "Obstacle.h"

using namespace cocos2d;

// initialize the obstacle based on type which specifies the image to use and y position, and the x
//   position is x
//
// x    [in] - the x coordinate to initially position the obstacle
// type [in] - JUMPING_OBSTACLE creates an obstacle positioned for jumping over, and SLIDING_OBSTACLE
//               creates an obstacle positioned for sliding under
void Obstacle::InitWithPositionAndType(int x, int type)
{
    // get the window size from the director
    CCSize size = CCDirector::sharedDirector()->getWinSize();

	switch(type)
	{
	case JUMPING_OBSTACLE:
		CCSprite::initWithFile(JUMPING_SPRITE);
		setPosition( ccp(x, size.height * JUMP_Y_POS) );
		break;
	case SLIDING_OBSTACLE:
		CCSprite::initWithFile(SLIDING_SPRITE);
		setPosition( ccp(x, size.height * SLIDE_Y_POS) );
		break;
	default:
		CCLog("Illegal Obstacle Type");
	}
}
