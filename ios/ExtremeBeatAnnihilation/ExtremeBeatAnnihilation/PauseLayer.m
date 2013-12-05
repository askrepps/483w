//
//  PauseLayer.m
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 12/5/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "PauseLayer.h"
#import "OptionsLayer.h"

@implementation PauseLayer

+(CCScene *)scene
{
	CCScene *scene = [CCScene node];
	PauseLayer *layer = [PauseLayer node];
	[scene addChild: layer];
    
	return scene;
}

-(id)init
{
    if((self = [super init]))
    {
        CCMenuItemFont *unPause = [CCMenuItemFont itemWithString:@"Return to Game" target:self selector:@selector(unPausePressed)];
        CCMenuItemFont *back = [CCMenuItemFont itemWithString:@"Back" target:self selector:@selector(backPressed)];
        CCMenu *pauseMenu = [CCMenu menuWithItems:unPause, back, nil];
        
        [self addChild: pauseMenu];
    }
    
    return self;
}

#pragma mark - Button presses

-(void)unPausePressed
{
    
}

-(void)backPressed
{
    
}

@end
