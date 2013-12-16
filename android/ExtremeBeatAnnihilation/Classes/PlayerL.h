#ifndef __PLAYER_L_H__
#define __PLAYER_L_H__

#include "cocos2d.h"

class PlayerL: public cocos2d::CCSprite
{
public:
	virtual bool init();

	void Jump();
	void Slide();
	void enableJump();
	void enableSlide();

	// allows use of create() function which uses init() to create this sprite
	CREATE_FUNC(PlayerL);

private:
	bool canJump;
	bool canSlide;
	cocos2d::CCAction *runForever;
	cocos2d::CCAction *jumpAction;
	cocos2d::CCAction *slideAction;
};

#endif // __PLAYER_L_H__
