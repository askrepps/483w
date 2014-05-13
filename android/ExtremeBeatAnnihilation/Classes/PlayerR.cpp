#include "PlayerR.h"

using namespace cocos2d;
using namespace CocosDenshion;

// externs defined in Global.cpp
extern int Player_Two;

//Initialize the Right player sprite
bool PlayerR::init()
{
    m_canJump    = true;      //initialize so the player is able to jump
    m_canSlide   = true;      //initialize so the player is able to slide
    m_canCollide = true;      //initialize so the player will collide with things

    if(!CCSprite::init())
    {
        return false;
    }

    CCSpriteFrameCache* framecache = CCSpriteFrameCache::sharedSpriteFrameCache();

    CCArray*            runAnimFrames;          // array to hold the run animation frames
    CCAnimation*        runAnim;                // run animation
    CCCallFunc*         jumpFuncAction;         // function to enable jump
    CCJumpBy*           jumpingAction;          // how the player moves when jumping
    CCArray*            jumpAnimFrames;         // array to hold the jump animation frames
    CCAnimation*        jumpAnim;               // jump animation
    CCAction*           animationAction;        // jump action
    CCSpawn*            jumping;                // spawn a jump action
    CCCallFunc*         slideFuncAction;        // function to enable slide
    CCArray*            slideAnimFrames;        // array to hold the slide animation frames
    CCAnimation*        slideAnim;              // slide animation
    CCFiniteTimeAction* slideanimationAction;   // slide action
    CCSpawn*            sliding;                // spawn a slide action

    char* playerColor;

    switch (Player_Two)
    {
    case 1:             //Player One is Blue
        framecache->addSpriteFramesWithFile("CharacterSprites/BlueCharacter/blue_running.plist");
        framecache->addSpriteFramesWithFile("CharacterSprites/BlueCharacter/blue_jumping.plist");
        framecache->addSpriteFramesWithFile("CharacterSprites/BlueCharacter/blue_sliding.plist");

        playerColor = "blue";

        break;

    case 2:             //Player One Green
        framecache->addSpriteFramesWithFile("CharacterSprites/GreenCharacter/green_running.plist");
        framecache->addSpriteFramesWithFile("CharacterSprites/GreenCharacter/green_jumping.plist");
        framecache->addSpriteFramesWithFile("CharacterSprites/GreenCharacter/green_sliding.plist");

        playerColor = "green";

        break;

    case 3:             //Player One is Red
        framecache->addSpriteFramesWithFile("CharacterSprites/RedCharacter/red_running.plist");
        framecache->addSpriteFramesWithFile("CharacterSprites/RedCharacter/red_jumping.plist");
        framecache->addSpriteFramesWithFile("CharacterSprites/RedCharacter/red_sliding.plist");

        playerColor = "red";

        break;

    default:
        break;
    }

    // Running Animation -------------------------------------------------------------------------------
    runAnimFrames = CCArray::create();

    // Add all the running frames to the run animation array
    for(int i = 1; i <= 7; ++i)
    {
        runAnimFrames->
            addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->
                spriteFrameByName(CCString::createWithFormat("%s_running_%d.png", playerColor, i)->
                    getCString()));
    }

    // Create the animation
    runAnim = CCAnimation::createWithSpriteFrames(runAnimFrames, 0.1f);
    CC_SAFE_RETAIN(runAnim);
    m_runForever = CCRepeatForever::create(CCAnimate::create(runAnim));

    // Jumping Animation -------------------------------------------------------------------------------
    jumpFuncAction = CCCallFunc::create(this, callfunc_selector(PlayerR::EnableJump));
    jumpingAction  = CCJumpBy::create(0.5, ccp(0, 0), 100 , 1);
    jumpAnimFrames = CCArray::create();

    CC_SAFE_RETAIN(jumpingAction);

    // Add all the jumping frames to the jump animation array
    for(int i = 1; i <= 7; ++i)
    {
        jumpAnimFrames->
            addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->
                spriteFrameByName(CCString::createWithFormat("%s_jumping_%d.png", playerColor, i)->
                    getCString()));
    }

    // Create the animation
    jumpAnim        = CCAnimation::createWithSpriteFrames(jumpAnimFrames, 0.1f);
    CC_SAFE_RETAIN(jumpAnim);
    animationAction = CCAnimate::create(jumpAnim);
    jumping         = CCSpawn::create(jumpingAction, animationAction, NULL);
    m_jumpAction    = CCSequence::create(jumping, jumpFuncAction, NULL);

    // Sliding Animation -------------------------------------------------------------------------------
    slideFuncAction = CCCallFunc::create(this, callfunc_selector(PlayerR::EnableSlide));
    slideAnimFrames = CCArray::create();

    // Add all the sliding frames to the slide animation array
    for(int i = 1; i <= 7; ++i)
    {
        int j = i;

        if(j > 2)
        {
            j = 2;
        }

        slideAnimFrames->
            addObject(CCSpriteFrameCache::sharedSpriteFrameCache()->
                spriteFrameByName(CCString::createWithFormat("%s_slide_%d.png", playerColor, j)->
                    getCString()));
    }

    // Create the animation
    slideAnim            = CCAnimation::createWithSpriteFrames(slideAnimFrames, 0.1f);
    CC_SAFE_RETAIN(slideAnim);
    slideanimationAction = CCAnimate::create(slideAnim);
    sliding              = CCSpawn::create(slideanimationAction, NULL);
    m_slideAction        = CCSequence::create(sliding, slideFuncAction, NULL);

    CC_SAFE_RETAIN(m_slideAction);
    CC_SAFE_RETAIN(m_runForever);
    CC_SAFE_RETAIN(m_jumpAction);

    // Flip the sprite to face the other direction
    CCSprite::setFlipX(true);

    runAction(m_runForever);

    return true;
}

// Jump Action
void PlayerR::Jump()
{
    if(m_canJump && m_canSlide)
    {
        m_canJump = false;
        stopAction(m_runForever);
        runAction(m_jumpAction);
    }
}

// Slide Action
void PlayerR::Slide()
{
    if(m_canJump && m_canSlide)
    {
        m_canSlide = false;
        stopAction(m_runForever);
        runAction(m_slideAction);
    }
}

// Allows the player to jump
void PlayerR::EnableJump()
{
    m_canJump = true;
    runAction(m_runForever);
}

// Allows the player to slide
void PlayerR::EnableSlide()
{
    m_canSlide = true;
    runAction(m_runForever);
}

// Returns if the player can collide
bool PlayerR::CanCollide()
{
    return m_canCollide;
}

// Allows the player to collide with obstacle
void PlayerR::SetCollide()
{
    m_canCollide = true;
}

// Player flashes when colliding with an obstacle
void PlayerR::Blink()
{
    SimpleAudioEngine::sharedEngine()->playEffect("SFX/hit.wav");

    CCBlink*    blinkAction = CCBlink::create(1.0, 8);
    CCCallFunc* funcAction  = CCCallFunc::create(this, callfunc_selector(PlayerR::SetCollide));
    CCShow*     showAction  = CCShow::create();

    CCSequence* actions = CCSequence::create(blinkAction, showAction, funcAction, NULL);

    if(m_canCollide)
    {
        m_canCollide = false;
        runAction(actions);
    }
}
