//
//  LeftPlayer.m
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 10/20/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "LeftPlayer.h"
#import "Registry.h"

@implementation LeftPlayer

-(id)init
{
    NSString *file;
    
    // Get the appropriate sprite sheet
    switch([Registry getCharOne])
    {
        case 0:
            file = @"char1.png";
            break;
        case 1:
            file = @"char1.png";
            break;
        case 2:
            file = @"char1.png";
            break;
        case 3:
            file = @"";
            break;
        default:
            break;
    }
    
    if(self = [super initWithFile:file])
    {
        _canJump = YES;
        _canBlink = YES;
    }
    
    return self;
}

-(void)jump
{
    CCCallFunc *funcAction = [CCCallFunc actionWithTarget:self selector:@selector(enableJump)];
    CCJumpBy *jumpAction = [CCJumpBy actionWithDuration:0.5 position:ccp(0,0) height:kJumpHeight jumps:1];
    
    CCSequence *actions = [CCSequence actions:jumpAction, funcAction, nil];
    
    if(self.canJump)
    {
        self.canJump = NO;
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
    self.canJump = YES;
}

-(void)enableBlink
{
    self.canBlink = YES;
}

@end
