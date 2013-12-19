#include "PlayerL.h"

using namespace cocos2d;

extern int Player_One;

//Initialize the Left player sprite
bool PlayerL::init()
{

	canJump  = true;		//initialize so the player is able to jump
	canSlide = true;		//initialize so the player is able to slide
	canCollide = true;		//initialize so the player will collide with things

    if(!CCSprite::init())
    {
        return false;
    }

    CCSpriteFrameCache* framecache = CCSpriteFrameCache::sharedSpriteFrameCache();

    CCArray*            runAnimFrames;			//array to hold the run animation frames
    CCAnimation*        runAnim;				//run animation
    CCCallFunc*         jumpFuncAction;			//function to enable jump
    CCJumpBy*           jumpingAction;			//how the player moves when jumping
    CCArray*            jumpAnimFrames;			//array to hold the jump animation frames
    CCAnimation*        jumpAnim;				//jump animation
    CCAction*           animationAction;		//jump action
    CCSpawn*            jumping;				//spawn a jump action
    CCCallFunc*         slideFuncAction;		//function to enable slide
    CCArray*            slideAnimFrames;		//array to hold the slide animation frames
    CCAnimation*        slideAnim;				//slide animation
    CCFiniteTimeAction* slideanimationAction;	//slide action
    CCSpawn*            sliding;				//spawn a slide action

    switch (Player_One)
    {
        case 1:						//Player One is Blue
    	framecache->addSpriteFramesWithFile("CharacterSprites/BlueCharacter/blue_running.plist");
    	framecache->addSpriteFramesWithFile("CharacterSprites/BlueCharacter/blue_jumping.plist");
    	framecache->addSpriteFramesWithFile("CharacterSprites/BlueCharacter/blue_sliding.plist");

    	//Running Animation
		runAnimFrames = CCArray::create();

		//Add all the running frames to the run animation array
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
		jumpingAction = CCJumpBy::create(0.5, ccp(0, 0), 100 , 1);
		CC_SAFE_RETAIN(jumpingAction);
		jumpAnimFrames = CCArray::create();

		//Add all the jumping frames to the jump animation array
		for(int i = 1; i <= 7; i++)
		{
			jumpAnimFrames->
				addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->
						spriteFrameByName(CCString::createWithFormat("blue_jumping_%d.png", i)->getCString ()));
		}

		jumpAnim = CCAnimation::createWithSpriteFrames(jumpAnimFrames, 0.1f);
		CC_SAFE_RETAIN(jumpAnim);
		animationAction = CCAnimate::create(jumpAnim);

		jumping = CCSpawn::create(jumpingAction, animationAction, NULL);

		jumpAction = CCSequence::create(jumping, jumpFuncAction, NULL);

		//Sliding Animation
		slideFuncAction = CCCallFunc::create(this, callfunc_selector(PlayerL::enableSlide));

		slideAnimFrames = CCArray::create();

		//Add all the sliding frames to the slide animation array
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
    case 2:				//Player One Green
    	framecache->addSpriteFramesWithFile("CharacterSprites/GreenCharacter/green_running.plist");
    	framecache->addSpriteFramesWithFile("CharacterSprites/GreenCharacter/green_jumping.plist");
    	framecache->addSpriteFramesWithFile("CharacterSprites/GreenCharacter/green_sliding.plist");

    	//Running Animation
		runAnimFrames = CCArray::create();

		//Add all the running frames to the run animation array
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
		jumpingAction = CCJumpBy::create(0.5, ccp(0, 0), 100 , 1);
		CC_SAFE_RETAIN(jumpingAction);
		jumpAnimFrames = CCArray::create();

		//Add all the jumping frames to the jump animation array
		for(int i = 1; i <= 7; i++)
		{
			jumpAnimFrames->
				addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->
						spriteFrameByName(CCString::createWithFormat("green_jumping_%d.png", i)->getCString ()));
		}

		jumpAnim = CCAnimation::createWithSpriteFrames(jumpAnimFrames, 0.1f);
		CC_SAFE_RETAIN(jumpAnim);
		animationAction = CCAnimate::create(jumpAnim);

		jumping = CCSpawn::create(jumpingAction, animationAction, NULL);

		jumpAction = CCSequence::create(jumping, jumpFuncAction, NULL);

		//Sliding Animation
		slideFuncAction = CCCallFunc::create(this, callfunc_selector(PlayerL::enableSlide));

		slideAnimFrames = CCArray::create();

		//Add all the sliding frames to the slide animation array
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
    case 3:				//Player One is Red
        	framecache->addSpriteFramesWithFile("CharacterSprites/RedCharacter/red_running.plist");
        	framecache->addSpriteFramesWithFile("CharacterSprites/RedCharacter/red_jumping.plist");
        	framecache->addSpriteFramesWithFile("CharacterSprites/RedCharacter/red_sliding.plist");

        	//Running Animation
        	runAnimFrames = CCArray::create();

    		//Add all the running frames to the run animation array
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
    		jumpingAction = CCJumpBy::create(0.5, ccp(0, 0), 100 , 1);
    		CC_SAFE_RETAIN(jumpingAction);
    		jumpAnimFrames = CCArray::create();

    		//Add all the jumping frames to the jump animation array
    		for(int i = 1; i <= 7; i++)
    		{
    			jumpAnimFrames->
    				addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->
    						spriteFrameByName(CCString::createWithFormat("red_jumping_%d.png", i)->getCString ()));
    		}

    		jumpAnim = CCAnimation::createWithSpriteFrames(jumpAnimFrames, 0.1f);
    		CC_SAFE_RETAIN(jumpAnim);
    		animationAction = CCAnimate::create(jumpAnim);

    		jumping = CCSpawn::create(jumpingAction, animationAction, NULL);

    		jumpAction = CCSequence::create(jumping, jumpFuncAction, NULL);
    		//Sliding Animation
    		slideFuncAction = CCCallFunc::create(this, callfunc_selector(PlayerL::enableSlide));

    		slideAnimFrames = CCArray::create();

    		//Add all the sliding frames to the slide animation array
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

//Jump Action
void PlayerL::Jump()
{
	if(canJump && canSlide)
	{
		canJump = false;
		stopAction(runForever);
		runAction(jumpAction);
	}
}

//Slide Action
void PlayerL::Slide()
{
	if(canJump && canSlide)
	{
		canSlide = false;
		stopAction(runForever);
		runAction(slideAction);
	}
}

//Allows the player to jump
void PlayerL::enableJump()
{
    canJump = true;
    runAction(runForever);
}

//Allows the player to slide
void PlayerL::enableSlide()
{
    canSlide = true;
    runAction(runForever);
}

//Returns if the player can collide
bool PlayerL::CanCollide()
{
	return canCollide;
}

//Allows the player to collide with obstacle
void PlayerL::SetCollide()
{
	canCollide = true;
}

//Player flashes when colliding with an obstacle
void PlayerL::Blink()
{
	SimpleAudioEngine::sharedEngine()->playEffect("SFX/hit.wav");
	CCBlink *blinkAction = CCBlink::create(1.0, 8);
	CCCallFunc *funcAction = CCCallFunc::create(this, callfunc_selector(PlayerL::SetCollide));
	CCShow *showAction = CCShow::create();

	CCSequence *actions = CCSequence::create(blinkAction, showAction, funcAction, NULL);
	if(canCollide)
	{
		canCollide = false;
		runAction(actions);
	}
}
