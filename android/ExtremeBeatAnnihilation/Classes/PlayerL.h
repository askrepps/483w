#ifndef __PLAYER_L_H__
#define __PLAYER_L_H__

#include "cocos2d.h"

class PlayerL: public cocos2d::CCSprite
{
public:
	virtual bool init();

	void Jump();
	void Slide();
	void Blink();
	void enableJump();
	void enableSlide();
	bool CanCollide();
	void SetCollide();
	// allows use of create() function which uses init() to create this sprite
	CREATE_FUNC(PlayerL);

private:
	bool canJump;
	bool canSlide;
	bool canCollide;
	cocos2d::CCAction *runForever;
	cocos2d::CCFiniteTimeAction *jumpAction;
	cocos2d::CCFiniteTimeAction *slideAction;
};

#endif // __PLAYER_L_H__
