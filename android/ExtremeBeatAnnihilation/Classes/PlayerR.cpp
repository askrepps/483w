#include "PlayerR.h"

using namespace cocos2d;

extern int Player_Two;

bool PlayerR::init()
{

	canJump = true;
	canSlide = true;

    if(!CCSprite::init())
    {
        return false;
    }

    CCSpriteFrameCache* framecache = CCSpriteFrameCache::sharedSpriteFrameCache();


    switch (Player_Two)
    {
        case 1:
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
		PlayerR::runForever = CCRepeatForever::create(CCAnimate::create(runAnim));

		//Jumping Animation
		CCCallFunc *jumpFuncAction = CCCallFunc::create(this, callfunc_selector(PlayerR::enableJump));
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

		PlayerR::jumpAction = CCSequence::create(jumping, jumpFuncAction, NULL);

		//Sliding Animation
		CCCallFunc *slideFuncAction = CCCallFunc::create(this, callfunc_selector(PlayerR::enableSlide));

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

		PlayerR::slideAction = CCSequence::create(sliding, slideFuncAction, NULL);

		break;
    }
    case 2:
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
		PlayerR::runForever = CCRepeatForever::create(CCAnimate::create(runAnim));

		//Jumping Animation
		CCCallFunc *jumpFuncAction = CCCallFunc::create(this, callfunc_selector(PlayerR::enableJump));
		CCJumpBy *jumpAction = CCJumpBy::create(0.5, ccp(0, 0), 100 , 1);

		CCArray* jumpAnimFrames = CCArray::create();

		for(int i = 1; i <= 7; i++)
		{
			jumpAnimFrames->
				addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->
						spriteFrameByName(CCString::createWithFormat("green_jumping_%d.png", i)->getCString ()));
		}

		CCAnimation *jumpAnim = CCAnimation::createWithSpriteFrames(jumpAnimFrames, 0.1f);
		CC_SAFE_RETAIN(jumpAnim);
		CCAction *animationAction = CCAnimate::create(jumpAnim);

		CCSpawn *jumping = CCSpawn::create(jumpAction, animationAction, NULL);

		PlayerR::jumpAction = CCSequence::create(jumping, jumpFuncAction, NULL);

		//Sliding Animation
		CCCallFunc *slideFuncAction = CCCallFunc::create(this, callfunc_selector(PlayerR::enableSlide));

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

		PlayerR::slideAction = CCSequence::create(sliding, slideFuncAction, NULL);

		break;
    }
    case 3:
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
    		PlayerR::runForever = CCRepeatForever::create(CCAnimate::create(runAnim));

    		//Jumping Animation
    		CCCallFunc *jumpFuncAction = CCCallFunc::create(this, callfunc_selector(PlayerR::enableJump));
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

    		PlayerR::jumpAction = CCSequence::create(jumping, jumpFuncAction, NULL);

    		//Sliding Animation
    		CCCallFunc *slideFuncAction = CCCallFunc::create(this, callfunc_selector(PlayerR::enableSlide));

    		CCArray* slideAnimFrames = CCArray::create();

    		for(int i = 1; i <= 2; i++)
    		{
    			slideAnimFrames->
    				addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->
    						spriteFrameByName(CCString::createWithFormat("red_slide_%d.png", i)->getCString ()));
    		}

    		CCAnimation *slideAnim = CCAnimation::createWithSpriteFrames(slideAnimFrames, 0.1f);
    		CCFiniteTimeAction *slideanimationAction = CCAnimate::create(slideAnim);
    		CC_SAFE_RETAIN(slideAnim);
    		CCSpawn *sliding = CCSpawn::create(slideanimationAction, NULL);

    		PlayerR::slideAction = CCSequence::create(sliding, slideFuncAction, NULL);

        	break;
        }
    default:
    	break;
    }
    canJump = true;
    canSlide = true;
    CCSprite::setFlipX(true);
    runAction(runForever);
    return true;
}

void PlayerR::Jump()
{
	if(canJump)
	{
		canJump = false;
		stopAction(runForever);
		runAction(jumpAction);
	}
}

void PlayerR::Slide()
{
	if(canJump)
	{
		canJump = false;
		stopAction(runForever);
		runAction(slideAction);
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
