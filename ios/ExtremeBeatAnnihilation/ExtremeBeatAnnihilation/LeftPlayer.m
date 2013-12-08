//
//  LeftPlayer.m
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 10/20/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "LeftPlayer.h"
#import "Registry.h"

@interface LeftPlayer ()

@property (strong, nonatomic) CCAction *runAction;
@property (strong, nonatomic) CCAction *jumpAction;
@property (strong, nonatomic) CCAction *slideAction;

@end

@implementation LeftPlayer

-(id)init
{
    NSString *file;
    
    // Get the appropriate sprite sheet
    switch([Registry getCharOne])
    {
        case 0:
            file = @"red";
            break;
        case 1:
            file = @"blue";
            break;
        case 2:
            file = @"green";
            break;
        default:
            break;
    }
    
    if(self = [super init])
    {
        _canJump = YES;
        _canSlide = YES;
        _canBlink = YES;
        
        [[CCSpriteFrameCache sharedSpriteFrameCache] addSpriteFramesWithFile:[NSString stringWithFormat:@"%@_running.plist", file]];
        [[CCSpriteFrameCache sharedSpriteFrameCache] addSpriteFramesWithFile:[NSString stringWithFormat:@"%@_jumping.plist", file]];
        [[CCSpriteFrameCache sharedSpriteFrameCache] addSpriteFramesWithFile:[NSString stringWithFormat:@"%@_sliding.plist", file]];
                
        NSMutableArray *runAnimFrames = [NSMutableArray array];
        for(int i = 1; i <= 7; i++)
        {
            [runAnimFrames addObject:
             [[CCSpriteFrameCache sharedSpriteFrameCache] spriteFrameByName:
              [NSString stringWithFormat:@"running_%d.png",i]]];
        }
        
        CCAnimation *runAnim = [CCAnimation
                                 animationWithSpriteFrames:runAnimFrames delay:0.1f];
        
        self.runAction = [CCRepeatForever actionWithAction:
                           [CCAnimate actionWithAnimation:runAnim]];
        [self runAction:self.runAction];
        
        self.scale = 2.0;
    }
    
    return self;
}

-(void)jump
{
    CCCallFunc *funcAction = [CCCallFunc actionWithTarget:self selector:@selector(enableJump)];
    CCJumpBy *moveAction = [CCJumpBy actionWithDuration:0.5 position:ccp(0,0) height:kJumpHeight jumps:1];
    
    NSMutableArray *jumpAnimFrames = [NSMutableArray array];
    for(int i = 1; i <= 7; i++)
    {
        [jumpAnimFrames addObject:
         [[CCSpriteFrameCache sharedSpriteFrameCache] spriteFrameByName:
          [NSString stringWithFormat:@"jumping_%d.png",i]]];
    }
    
    CCAnimation *jumpAnim = [CCAnimation animationWithSpriteFrames:jumpAnimFrames delay:0.1f];
    CCAction *act = [CCAnimate actionWithAnimation:jumpAnim];
    CCAction *jumpingAction = [CCRepeatForever actionWithAction:[CCAnimate actionWithAnimation:jumpAnim]];
//    self.jumpAction = [CCRepeatForever actionWithAction:[CCAnimate actionWithAnimation:jumpAnim]];
    self.jumpAction = [CCSequence actions:moveAction, act, funcAction, nil];
    
//    CCSequence *actions = [CCSequence actions:jumpAction, self.jumpAction, funcAction, nil];
    
    if(self.canJump)
    {
        self.canJump = NO;
        [self stopAction:self.runAction];
        [self runAction:self.jumpAction];
    }
}

-(void)slide
{
    // TO BE FILLED OUT LATER
    CCCallFunc *funcAction = [CCCallFunc actionWithTarget:self selector:@selector(enableSlide)];
    
    CCSequence *actions = [CCSequence actions:funcAction, nil];
    
    if(self.canSlide)
    {
        self.canSlide = NO;
        [self runAction:actions];
    }
}

-(void)blink
{
    CCBlink *blinkAction = [CCBlink actionWithDuration:1.0 blinks:6];
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
    self.canSlide = YES;
}

-(void)enableBlink
{
    self.canBlink = YES;
}

-(BOOL)isBlinking
{
    return !self.canBlink;
}

@end
