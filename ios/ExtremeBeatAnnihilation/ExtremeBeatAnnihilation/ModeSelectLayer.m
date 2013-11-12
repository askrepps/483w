//
//  ModeSelectLayer.m
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 11/7/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "ModeSelectLayer.h"
#import "BackgroundLayer.h"
#import "MenuLayer.h"
#import "CharacterSelectLayer.h"
#import "Registry.h"

@implementation ModeSelectLayer

+(CCScene *)scene
{
	CCScene *scene = [CCScene node];
	
    BackgroundLayer *background = [BackgroundLayer node];
	ModeSelectLayer *mode = [ModeSelectLayer node];
	
    [scene addChild:background z:-1];
	[scene addChild:mode];
	
	return scene;
}

-(id)init
{
	if((self=[super init]))
    {
        CGSize size = [[CCDirector sharedDirector] winSize];
        
        // Add buttons for selecting single player or multiplayer
        CCMenuItemFont *single = [CCMenuItemFont itemWithString:@"Single Player" target:self selector:@selector(singlePressed:)];
        single.position = ccp(size.width/2, size.height/2);
        CCMenuItemFont *multi = [CCMenuItemFont itemWithString:@"Multiplayer" target:self selector:@selector(multiPressed:)];
        multi.position = ccp(size.width/2, size.height/2 - 32);
        CCMenuItemFont *back = [CCMenuItemFont itemWithString:@"Back" target:self selector:@selector(backPressed:)];
        back.position = ccp(size.width/2, size.height/2 - 64);
        
        CCMenu *startMenu = [CCMenu menuWithItems:single, multi, back, nil];
        startMenu.position = CGPointZero;
        [self addChild:startMenu];
	}
    
	return self;
}

-(void)dealloc
{
	[super dealloc];
}

-(void)singlePressed:(id)sender
{
    [Registry setIsSinglePlayer:YES];
    [[CCDirector sharedDirector] replaceScene:[CharacterSelectLayer scene]];
}

-(void)multiPressed:(id)sender
{
    [Registry setIsSinglePlayer:NO];
}

-(void)backPressed:(id)sender
{
    [[CCDirector sharedDirector] replaceScene:[MenuLayer scene]];
}

@end