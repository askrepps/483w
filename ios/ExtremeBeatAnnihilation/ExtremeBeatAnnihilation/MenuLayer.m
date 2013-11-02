//
//  HelloWorldLayer.m
//  ExtremeBeatAnnihilation
//
//  Created by ROBERT WILLIAM CARRIER on 9/11/13.
//  Copyright Crash Course Gaming 2013. All rights reserved.
//

// Import the interfaces
#import "MenuLayer.h"
#import "AppDelegate.h"
#import "BackgroundLayer.h"
#import "OptionsLayer.h"

#pragma mark - MenuLayer

@implementation MenuLayer

// Helper class method that creates a Scene with the MenuLayer as the only child.
+(CCScene *)scene
{
	// 'scene' is an autorelease object.
	CCScene *scene = [CCScene node];
	
	// 'menu' is an autorelease object.
    BackgroundLayer *background = [BackgroundLayer node];
	MenuLayer *menu = [MenuLayer node];
	
	// add menu as a child to scene
    [scene addChild:background z:-1];
	[scene addChild: menu];
	
	// return the scene
	return scene;
}

-(id)init
{
	if((self=[super init]))
    {        
        CGSize size = [[CCDirector sharedDirector] winSize];
        
//        // Add background image
//        CCSprite* background = [CCSprite spriteWithFile:@"TitleImage.jpg"];
//        background.position = CGPointZero;
//        [self addChild:background];

        // Add buttons for starting the game and accessing options
        CCMenuItemFont *startGame = [CCMenuItemFont itemWithString:@"Start Game" target:self selector:@selector(startPressed:)];
        startGame.position = ccp(size.width/2, size.height/2);
        CCMenuItemFont *options = [CCMenuItemFont itemWithString:@"Options" target:self selector:@selector(optionsPressed:)];
        options.position = ccp(size.width/2, size.height/2 - 32);
        
        CCMenu *startMenu = [CCMenu menuWithItems:startGame, options, nil];
        startMenu.position = CGPointZero;
        [self addChild:startMenu];
        
        [[CCDirector sharedDirector] setDisplayStats:NO];
	}
    
	return self;
}

-(void)dealloc
{
	[super dealloc];
}

-(void)startPressed:(id)sender
{
    NSLog(@"start pressed");
}

-(void)optionsPressed:(id)sender
{
    CCScene *scene = [CCScene node];
    [scene addChild:[OptionsLayer node]];
    [[CCDirector sharedDirector] pushScene:scene];
}
@end
