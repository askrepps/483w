//
//  PlayerSprite.m
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 12/8/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "PlayerSprite.h"
#import "Registry.h"

@interface PlayerSprite ()

@property (strong, nonatomic) CCAction *runAction;
@property (strong, nonatomic) CCAction *jumpAction;
@property (strong, nonatomic) CCAction *slideAction;
@property BOOL canJump;
@property BOOL canBlink;
@property BOOL canSlide;

@end

@implementation PlayerSprite

-(id)init
{
    if(self = [super init])
    {
        _canJump = YES;
        _canSlide = YES;
        _canBlink = YES;
        
        [[CCSpriteFrameCache sharedSpriteFrameCache] addSpriteFramesWithFile:[NSString stringWithFormat:@"%@_running.plist", _fileName]];
        [[CCSpriteFrameCache sharedSpriteFrameCache] addSpriteFramesWithFile:[NSString stringWithFormat:@"%@_jumping.plist", _fileName]];
        [[CCSpriteFrameCache sharedSpriteFrameCache] addSpriteFramesWithFile:[NSString stringWithFormat:@"%@_sliding.plist", _fileName]];
        
        // Running action
        
        NSMutableArray *runAnimFrames = [NSMutableArray array];
        for(int i = 1; i <= 7; i++)
        {
            [runAnimFrames addObject:
             [[CCSpriteFrameCache sharedSpriteFrameCache] spriteFrameByName:
              [NSString stringWithFormat:@"%@_running_%d.png", self.fileName, i]]];
        }
        
        CCAnimation *runAnim = [CCAnimation
                                animationWithSpriteFrames:runAnimFrames delay:0.1f];
        
        self.runAction = [CCRepeatForever actionWithAction:
                          [CCAnimate actionWithAnimation:runAnim]];
        
        // Jumping action
        
        CCCallFunc *jumpFuncAction = [CCCallFunc actionWithTarget:self selector:@selector(enableJump)];
        CCJumpBy *moveAction = [CCJumpBy actionWithDuration:0.5 position:ccp(0,0) height:kJumpHeight jumps:1];
        
        NSMutableArray *jumpAnimFrames = [NSMutableArray array];
        for(int i = 1; i <= 7; i++)
        {
            [jumpAnimFrames addObject:
             [[CCSpriteFrameCache sharedSpriteFrameCache] spriteFrameByName:
              [NSString stringWithFormat:@"%@_jumping_%d.png", self.fileName, i]]];
        }
        
        CCAnimation *jumpAnim = [CCAnimation animationWithSpriteFrames:jumpAnimFrames delay:0.1f];
        CCAction *animationAction = [CCAnimate actionWithAnimation:jumpAnim];
        
        CCSpawn *jumping = [CCSpawn actions:moveAction, animationAction, nil];
        
        self.jumpAction = [CCSequence actions:jumping, jumpFuncAction, nil];
        
        // Slide action
        
        CCCallFunc *slideFuncAction = [CCCallFunc actionWithTarget:self selector:@selector(enableSlide)];
        
        NSMutableArray *slideAnimFrames = [NSMutableArray array];
        for(int i = 1; i <= 2; i++)
        {
            [slideAnimFrames addObject:
             [[CCSpriteFrameCache sharedSpriteFrameCache] spriteFrameByName:
              [NSString stringWithFormat:@"%@_slide_%d.png", self.fileName, i]]];
        }
        for(int i = 1; i < 7; i++)
        {
            [slideAnimFrames addObject:
             [[CCSpriteFrameCache sharedSpriteFrameCache] spriteFrameByName:
              [NSString stringWithFormat:@"%@_slide_2.png", self.fileName]]];
        }
        
        CCAnimation *slideAnim = [CCAnimation animationWithSpriteFrames:slideAnimFrames delay:0.1f];
        CCAction *slideAnimationAction = [CCAnimate actionWithAnimation:slideAnim];
        
        CCSpawn *sliding = [CCSpawn actions:slideAnimationAction, nil];
        
        self.slideAction = [CCSequence actions:sliding, slideFuncAction, nil];
        
        // Start initial action
        self.scale = 2.0;
        [self runAction:self.runAction];
    }
    
    return self;
}

-(void)jump
{
    if(self.canJump)
    {
        self.canJump = NO;
        [self stopAction:self.runAction];
        [self runAction:self.jumpAction];
    }
}

-(void)slide
{
    if(self.canSlide)
    {
        self.canSlide = NO;
        [self stopAction:self.runAction];
        [self runAction:self.slideAction];
    }
}

-(void)blink
{
    CCBlink *blinkAction = [CCBlink actionWithDuration:0.8 blinks:6];
    CCCallFunc *funcAction = [CCCallFunc actionWithTarget:self selector:@selector(enableBlink)];
    CCShow *showAction = [CCShow action];
    
    CCSequence *actions = [CCSequence actions:blinkAction, showAction, funcAction, nil];
    
    if (self.canBlink)
    {
        self.canBlink = NO;
        [self runAction:actions];
    }
}

-(void)enableJump
{
    [self stopAction:self.jumpAction];
    self.canJump = YES;
    [self runAction:self.runAction];
}

-(void)enableSlide
{
    [self stopAction:self.slideAction];
    self.canSlide = YES;
    [self runAction:self.runAction];
}

-(void)enableBlink
{
    self.canBlink = YES;
}

-(BOOL)isBlinking
{
    return !self.canBlink;
}

-(BOOL)isJumping
{
    return !self.canJump;
}

-(BOOL)isSliding
{
    return !self.canSlide;
}

@end