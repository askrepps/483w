#include "PlayerL.h"

using namespace cocos2d;

bool PlayerL::init()
{
    if(!CCSprite::init())
    {
        return false;
    }

    initWithFile("CharacterOne.png");

    canJump = true;
    canSlide = true;

    return true;
}

void PlayerL::Jump()
{
	CCCallFunc *funcAction = CCCallFunc::create(this, callfunc_selector(PlayerL::enableJump));
	CCJumpBy *jumpAction = CCJumpBy::create(0.5, ccp(0, 0), 100 , 1);

	CCSequence *actions = CCSequence::create(jumpAction, funcAction, NULL);;

	if(canJump)
	{
		canJump = false;
		runAction(actions);
	}
}

void PlayerL::Slide()
{
	CCCallFunc *funcAction = CCCallFunc::create(this, callfunc_selector(PlayerL::enableSlide));

	CCSequence *actions = CCSequence::create(funcAction, NULL);

	if(canSlide)
	{
		canSlide = false;
		runAction(actions);
	}
}

void PlayerL::enableJump()
{
    canJump = true;
}

void PlayerL::enableSlide()
{
    canSlide = true;
}
