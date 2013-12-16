#include "PlayerL.h"

using namespace cocos2d;

extern int Player_One;

bool PlayerL::init()
{

	canJump = true;
	canSlide = true;

    if(!CCSprite::init())
    {
        return false;
    }

    CCSpriteFrameCache* framecache = CCSpriteFrameCache::sharedSpriteFrameCache();

    switch (Player_One)
    {
    case 3:				//Red Player
    {
    	framecache->addSpriteFramesWithFile("CharacterSprites/RedCharacter/red_running.plist");
    	framecache->addSpriteFramesWithFile("CharacterSprites/RedCharacter/red_jumping.plist");
    	framecache->addSpriteFramesWithFile("CharacterSprites/RedCharacter/red_sliding.plist");

    	//Running Animation
    	CCArray* runAnimFrames = CCArray::create();

    	for(int i = 1; i <= 7; i++)
		{
			CCString *frame;
			frame = CCString::createWithFormat("red_running_%d.png", i);

			CCSpriteFrame *spriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(frame->getCString());
			if(!spriteFrame)
				CCLog("Error loading Sprite Frame");

			runAnimFrames->addObject(spriteFrame);
		}


		CCAnimation *runAnim = CCAnimation::createWithSpriteFrames(runAnimFrames, 0.1f);
		CC_SAFE_RETAIN(runAnim);

		PlayerL::runForever = CCRepeatForever::create(CCAnimate::create(runAnim));

		//Jumping Animation
		CCCallFunc *jumpFuncAction = CCCallFunc::create(this, callfunc_selector(PlayerL::enableJump));
		CCJumpBy *jumpAction = CCJumpBy::create(0.5, ccp(0, 0), 100 , 1);

		CCArray* jumpAnimFrames = CCArray::create();

		for(int i = 1; i <= 7; i++)
		{
			jumpAnimFrames->
				addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->
						spriteFrameByName(CCString::createWithFormat("red_jumping_%d.png", i)->getCString ()));
		}

		CCAnimation *jumpAnim = CCAnimation::createWithSpriteFrames(jumpAnimFrames, 0.1f);
		CC_SAFE_RETAIN(jumpAnim);
		CCAction *animationAction = CCAnimate::create(jumpAnim);

		CCSpawn *jumping = CCSpawn::create(jumpAction, animationAction, NULL);

		PlayerL::jumpAction = CCSequence::create(jumping, jumpFuncAction, NULL);

		//Sliding Animation
		CCCallFunc *slideFuncAction = CCCallFunc::create(this, callfunc_selector(PlayerL::enableSlide));

		CCArray* slideAnimFrames = CCArray::create();

		for(int i = 1; i <= 2; i++)
		{
			slideAnimFrames->
				addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->
						spriteFrameByName(CCString::createWithFormat("red_slide_%d.png", i)->getCString ()));
		}

		CCAnimation *slideAnim = CCAnimation::createWithSpriteFrames(slideAnimFrames, 0.1f);
		CC_SAFE_RETAIN(slideAnim);
		CCFiniteTimeAction *slideanimationAction = CCAnimate::create(slideAnim);

		CCSpawn *sliding = CCSpawn::create(slideanimationAction, NULL);

		PlayerL::slideAction = CCSequence::create(sliding, slideFuncAction, NULL);

    	break;
    }
    case 1:				//Blue Player
    {
    	framecache->addSpriteFramesWithFile("CharacterSprites/BlueCharacter/blue_running.plist");
    	framecache->addSpriteFramesWithFile("CharacterSprites/BlueCharacter/blue_jumping.plist");
    	framecache->addSpriteFramesWithFile("CharacterSprites/BlueCharacter/blue_sliding.plist");

    	//Running Animation
		CCArray* runAnimFrames = CCArray::create();

		for(int i = 1; i <= 7; i++)
		{
			runAnimFrames->
				addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->
						spriteFrameByName(CCString::createWithFormat("blue_running_%d.png", i)->getCString ()));
		}

		CCAnimation *runAnim = CCAnimation::createWithSpriteFrames(runAnimFrames, 0.1f);
		CC_SAFE_RETAIN(runAnim);
		PlayerL::runForever = CCRepeatForever::create(CCAnimate::create(runAnim));

		//Jumping Animation
		CCCallFunc *jumpFuncAction = CCCallFunc::create(this, callfunc_selector(PlayerL::enableJump));
		CCJumpBy *jumpAction = CCJumpBy::create(0.5, ccp(0, 0), 100 , 1);

		CCArray* jumpAnimFrames = CCArray::create();

		for(int i = 1; i <= 7; i++)
		{
			jumpAnimFrames->
				addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->
						spriteFrameByName(CCString::createWithFormat("blue_jumping_%d.png", i)->getCString ()));
		}

		CCAnimation *jumpAnim = CCAnimation::createWithSpriteFrames(jumpAnimFrames, 0.1f);
		CC_SAFE_RETAIN(jumpAnim);
		CCAction *animationAction = CCAnimate::create(jumpAnim);

		CCSpawn *jumping = CCSpawn::create(jumpAction, animationAction, NULL);

		PlayerL::jumpAction = CCSequence::create(jumping, jumpFuncAction, NULL);

		//Sliding Animation
		CCCallFunc *slideFuncAction = CCCallFunc::create(this, callfunc_selector(PlayerL::enableSlide));

		CCArray* slideAnimFrames = CCArray::create();

		for(int i = 1; i <= 2; i++)
		{
			slideAnimFrames->
				addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->
						spriteFrameByName(CCString::createWithFormat("blue_slide_%d.png", i)->getCString ()));
		}

		CCAnimation *slideAnim = CCAnimation::createWithSpriteFrames(slideAnimFrames, 0.1f);
		CC_SAFE_RETAIN(slideAnim);
		CCFiniteTimeAction *slideanimationAction = CCAnimate::create(slideAnim);

		CCSpawn *sliding = CCSpawn::create(slideanimationAction, NULL);

		PlayerL::slideAction = CCSequence::create(sliding, slideFuncAction, NULL);

		break;
    }
    case 2:				//Green Player
    {
    	framecache->addSpriteFramesWithFile("CharacterSprites/GreenCharacter/green_running.plist");
    	framecache->addSpriteFramesWithFile("CharacterSprites/GreenCharacter/green_jumping.plist");
    	framecache->addSpriteFramesWithFile("CharacterSprites/GreenCharacter/green_sliding.plist");

    	//Running Animation
		CCArray* runAnimFrames = CCArray::create();

		for(int i = 1; i <= 7; i++)
		{
			runAnimFrames->
				addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->
						spriteFrameByName(CCString::createWithFormat("green_running_%d.png", i)->getCString ()));
		}

		CCAnimation *runAnim = CCAnimation::createWithSpriteFrames(runAnimFrames, 0.1f);
		CC_SAFE_RETAIN(runAnim);
		runForever = CCRepeatForever::create(CCAnimate::create(runAnim));
		CCLog("RunForever %p", runForever);

		//Jumping Animation
		CCCallFunc *jumpFuncAction = CCCallFunc::create(this, callfunc_selector(PlayerL::enableJump));
		CCJumpBy *jumpAction = CCJumpBy::create(0.5, ccp(0, 0), 100 , 1);

		CCArray* jumpAnimFrames = CCArray::create();

		for(int i = 1; i <= 7; i++)
		{
			jumpAnimFrames->
				addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->
						spriteFrameByName(CCString::createWithFormat("green_jumping_%d.png", i)->getCString ()));
		}

		CCAnimation *jumpAnim = CCAnimation::createWithSpriteFrames(jumpAnimFrames, 0.1f);
		CCAction *animationAction = CCAnimate::create(jumpAnim);
		CC_SAFE_RETAIN(jumpAnim);
		CCSpawn *jumping = CCSpawn::create(jumpAction, animationAction, NULL);

		jumpAction = (CCJumpBy *)CCSequence::create(jumping, jumpFuncAction, NULL);

		//Sliding Animation
		CCCallFunc *slideFuncAction = CCCallFunc::create(this, callfunc_selector(PlayerL::enableSlide));

		CCArray* slideAnimFrames = CCArray::create();

		for(int i = 1; i <= 2; i++)
		{
			slideAnimFrames->
				addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->
						spriteFrameByName(CCString::createWithFormat("green_slide_%d.png", i)->getCString ()));
		}

		CCAnimation *slideAnim = CCAnimation::createWithSpriteFrames(slideAnimFrames, 0.1f);
		CC_SAFE_RETAIN(slideAnim);
		CCFiniteTimeAction *slideanimationAction = CCAnimate::create(slideAnim);

		CCSpawn *sliding = CCSpawn::create(slideanimationAction, NULL);

		slideAction = CCSequence::create(sliding, slideFuncAction, NULL);

		break;
    }
    default:
    	break;
    }

    canJump = true;
    canSlide = true;
    runAction(runForever);
    return true;
}

void PlayerL::Jump()
{
	if(canJump)
	{
		canJump = false;
		stopAction(runForever);
		runAction(jumpAction);
	}
}

void PlayerL::Slide()
{
	if(canJump)
	{
		canJump = false;
		stopAction(runForever);
		runAction(slideAction);
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
