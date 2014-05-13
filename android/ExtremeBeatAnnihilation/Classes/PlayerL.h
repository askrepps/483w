#ifndef __PLAYER_L_H__
#define __PLAYER_L_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

class PlayerL: public cocos2d::CCSprite
{
public:
	virtual bool init();

	void Jump();
	void Slide();
	void Blink();
	void EnableJump();
	void EnableSlide();
	bool CanCollide();
	void SetCollide();

	// allows use of create() function which uses init() to create this sprite
	CREATE_FUNC(PlayerL);

private:
	bool m_canJump;
	bool m_canSlide;
	bool m_canCollide;

	cocos2d::CCAction*           m_runForever;
	cocos2d::CCFiniteTimeAction* m_jumpAction;
	cocos2d::CCFiniteTimeAction* m_slideAction;
};

#endif // __PLAYER_L_H__
