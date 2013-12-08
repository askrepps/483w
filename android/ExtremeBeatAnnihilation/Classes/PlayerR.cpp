#include "PlayerR.h"

using namespace cocos2d;

bool PlayerR::init()
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

void PlayerR::Jump()
{
	CCCallFunc *funcAction = CCCallFunc::create(this, callfunc_selector(PlayerR::enableJump));
	CCJumpBy *jumpAction = CCJumpBy::create(0.5, ccp(0, 0), 100 , 1);

	CCSequence *actions = CCSequence::create(jumpAction, funcAction, NULL);;

	if(canJump)
	{
		canJump = false;
		runAction(actions);
	}
}

void PlayerR::Slide()
{
	CCCallFunc *funcAction = CCCallFunc::create(this, callfunc_selector(PlayerR::enableSlide));

	CCSequence *actions = CCSequence::create(funcAction, NULL);

	if(canSlide)
	{
		canSlide = false;
		runAction(actions);
	}
}

void PlayerR::enableJump()
{
    canJump = true;
}

void PlayerR::enableSlide()
{
    canSlide = true;
}
