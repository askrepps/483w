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

    CCArray* runAnimFrames;
    CCAnimation *runAnim;
    CCCallFunc *jumpFuncAction;
    CCJumpBy *jumpAction;
    CCArray* jumpAnimFrames;
    CCAnimation *jumpAnim;
    CCAction *animationAction;
    CCSpawn *jumping;
    CCCallFunc *slideFuncAction;
    CCArray* slideAnimFrames;
    CCAnimation *slideAnim;
    CCFiniteTimeAction *slideanimationAction;
    CCSpawn *sliding;

    switch (Player_One)
    {
        case 1:
    	framecache->addSpriteFramesWithFile("CharacterSprites/BlueCharacter/blue_running.plist");
    	framecache->addSpriteFramesWithFile("CharacterSprites/BlueCharacter/blue_jumping.plist");
    	framecache->addSpriteFramesWithFile("CharacterSprites/BlueCharacter/blue_sliding.plist");

    	//Running Animation
		runAnimFrames = CCArray::create();

		for(int i = 1; i <= 7; i++)
		{
			runAnimFrames->
				addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->
						spriteFrameByName(CCString::createWithFormat("blue_running_%d.png", i)->getCString ()));
		}

		runAnim = CCAnimation::createWithSpriteFrames(runAnimFrames, 0.1f);
		CC_SAFE_RETAIN(runAnim);
		runForever = CCRepeatForever::create(CCAnimate::create(runAnim));

		//Jumping Animation
		jumpFuncAction = CCCallFunc::create(this, callfunc_selector(PlayerL::enableJump));
		jumpAction = CCJumpBy::create(0.5, ccp(0, 0), 100 , 1);

		jumpAnimFrames = CCArray::create();

		for(int i = 1; i <= 7; i++)
		{
			jumpAnimFrames->
				addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->
						spriteFrameByName(CCString::createWithFormat("blue_jumping_%d.png", i)->getCString ()));
		}

		jumpAnim = CCAnimation::createWithSpriteFrames(jumpAnimFrames, 0.1f);
		CC_SAFE_RETAIN(jumpAnim);
		animationAction = CCAnimate::create(jumpAnim);

		jumping = CCSpawn::create(jumpAction, animationAction, NULL);

		jumpAction = (CCJumpTo*)CCSequence::create(jumping, jumpFuncAction, NULL);

		//Sliding Animation
		slideFuncAction = CCCallFunc::create(this, callfunc_selector(PlayerL::enableSlide));

		slideAnimFrames = CCArray::create();

		for(int i = 1; i <= 7; i++)
		{
			int j = i;
			if(j > 2)
					j = 2;
			slideAnimFrames->
				addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->
						spriteFrameByName(CCString::createWithFormat("blue_slide_%d.png", j)->getCString ()));
		}

		slideAnim = CCAnimation::createWithSpriteFrames(slideAnimFrames, 0.1f);
		CC_SAFE_RETAIN(slideAnim);
		slideanimationAction = CCAnimate::create(slideAnim);

		sliding = CCSpawn::create(slideanimationAction, NULL);

		slideAction = CCSequence::create(sliding, slideFuncAction, NULL);

		break;
    case 2:
    	framecache->addSpriteFramesWithFile("CharacterSprites/GreenCharacter/green_running.plist");
    	framecache->addSpriteFramesWithFile("CharacterSprites/GreenCharacter/green_jumping.plist");
    	framecache->addSpriteFramesWithFile("CharacterSprites/GreenCharacter/green_sliding.plist");

    	//Running Animation
		runAnimFrames = CCArray::create();

		for(int i = 1; i <= 7; i++)
		{
			runAnimFrames->
				addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->
						spriteFrameByName(CCString::createWithFormat("green_running_%d.png", i)->getCString ()));
		}

		runAnim = CCAnimation::createWithSpriteFrames(runAnimFrames, 0.1f);
		CC_SAFE_RETAIN(runAnim);
		runForever = CCRepeatForever::create(CCAnimate::create(runAnim));

		//Jumping Animation
		jumpFuncAction = CCCallFunc::create(this, callfunc_selector(PlayerL::enableJump));
		jumpAction = CCJumpBy::create(0.5, ccp(0, 0), 100 , 1);

		jumpAnimFrames = CCArray::create();

		for(int i = 1; i <= 7; i++)
		{
			jumpAnimFrames->
				addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->
						spriteFrameByName(CCString::createWithFormat("green_jumping_%d.png", i)->getCString ()));
		}

		jumpAnim = CCAnimation::createWithSpriteFrames(jumpAnimFrames, 0.1f);
		CC_SAFE_RETAIN(jumpAnim);
		animationAction = CCAnimate::create(jumpAnim);

		jumping = CCSpawn::create(jumpAction, animationAction, NULL);

		jumpAction = (CCJumpTo*)CCSequence::create(jumping, jumpFuncAction, NULL);

		//Sliding Animation
		slideFuncAction = CCCallFunc::create(this, callfunc_selector(PlayerL::enableSlide));

		slideAnimFrames = CCArray::create();

		for(int i = 1; i <= 7; i++)
		{
			int j = i;
			if(j > 2)
				j = 2;
			slideAnimFrames->
				addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->
						spriteFrameByName(CCString::createWithFormat("green_slide_%d.png", j)->getCString ()));
		}

		slideAnim = CCAnimation::createWithSpriteFrames(slideAnimFrames, 0.1f);
		CC_SAFE_RETAIN(slideAnim);
		slideanimationAction = CCAnimate::create(slideAnim);

		sliding = CCSpawn::create(slideanimationAction, NULL);

		slideAction = CCSequence::create(sliding, slideFuncAction, NULL);

		break;
    case 3:
        	framecache->addSpriteFramesWithFile("CharacterSprites/RedCharacter/red_running.plist");
        	framecache->addSpriteFramesWithFile("CharacterSprites/RedCharacter/red_jumping.plist");
        	framecache->addSpriteFramesWithFile("CharacterSprites/RedCharacter/red_sliding.plist");

        	//Running Animation
        	runAnimFrames = CCArray::create();

    		for(int i = 1; i <= 7; i++)
    		{
    			CCString *frame;
    			frame = CCString::createWithFormat("red_running_%d.png", i);

    			CCSpriteFrame *spriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(frame->getCString());
    			if(!spriteFrame)
    				CCLog("Error loading Sprite Frame");

    			runAnimFrames->addObject(spriteFrame);
    		}

    		runAnim = CCAnimation::createWithSpriteFrames(runAnimFrames, 0.1f);
    		CC_SAFE_RETAIN(runAnim);
    		runForever = CCRepeatForever::create(CCAnimate::create(runAnim));

    		//Jumping Animation
    		jumpFuncAction = CCCallFunc::create(this, callfunc_selector(PlayerL::enableJump));
    		jumpAction = CCJumpBy::create(0.5, ccp(0, 0), 100 , 1);

    		jumpAnimFrames = CCArray::create();

    		for(int i = 1; i <= 7; i++)
    		{
    			jumpAnimFrames->
    				addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->
    						spriteFrameByName(CCString::createWithFormat("red_jumping_%d.png", i)->getCString ()));
    		}

    		jumpAnim = CCAnimation::createWithSpriteFrames(jumpAnimFrames, 0.1f);
    		CC_SAFE_RETAIN(jumpAnim);
    		animationAction = CCAnimate::create(jumpAnim);

    		jumping = CCSpawn::create(jumpAction, animationAction, NULL);

    		jumpAction = (CCJumpTo*)CCSequence::create(jumping, jumpFuncAction, NULL);

    		//Sliding Animation
    		slideFuncAction = CCCallFunc::create(this, callfunc_selector(PlayerL::enableSlide));

    		slideAnimFrames = CCArray::create();

    		for(int i = 1; i <= 7; i++)
    		{
    			int j = i;
				if(j > 2)
					j = 2;
    			slideAnimFrames->
    				addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->
    						spriteFrameByName(CCString::createWithFormat("red_slide_%d.png", j)->getCString ()));
    		}

    		slideAnim = CCAnimation::createWithSpriteFrames(slideAnimFrames, 0.1f);
    		slideanimationAction = CCAnimate::create(slideAnim);
    		CC_SAFE_RETAIN(slideAnim);
    		sliding = CCSpawn::create(slideanimationAction, NULL);

    		slideAction = CCSequence::create(sliding, slideFuncAction, NULL);

        	break;
    default:
    	break;
    }

    canJump = true;
    canSlide = true;
    CC_SAFE_RETAIN(slideAction);
    CC_SAFE_RETAIN(runForever);
    CC_SAFE_RETAIN(jumpAction);
    runAction(runForever);
    return true;
}

void PlayerL::Jump()
{
	if(canJump && canSlide)
	{
		canJump = false;
		stopAction(runForever);
		runAction(jumpAction);
	}
}

void PlayerL::Slide()
{
	if(canJump && canSlide)
	{
		canSlide = false;
		stopAction(runForever);
		runAction(slideAction);
	}
}

void PlayerL::enableJump()
{
    canJump = true;
    runAction(runForever);
}

void PlayerL::enableSlide()
{
    canSlide = true;
    runAction(runForever);
}
