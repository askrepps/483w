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
#import "CharacterSelectLayer.h"
#import "Registry.h"
#import "SimpleAudioEngine.h"

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

        // Add buttons for starting the game and accessing options
        CCMenuItemFont *single = [CCMenuItemFont itemWithString:@"Single Player" target:self selector:@selector(singlePressed:)];
        single.position = ccp(size.width/2, size.height/2);
        CCMenuItemFont *multi = [CCMenuItemFont itemWithString:@"Multiplayer" target:self selector:@selector(multiPressed:)];
        multi.position = ccp(size.width/2, size.height/2 - 32);
        CCMenuItemFont *options = [CCMenuItemFont itemWithString:@"Options" target:self selector:@selector(optionsPressed:)];
        options.position = ccp(size.width/2, size.height/2 - 64);
        
        CCMenu *startMenu = [CCMenu menuWithItems:single, multi, options, nil];
        startMenu.position = CGPointZero;
        [self addChild:startMenu];
    }
    
	return self;
}

-(void)onEnterTransitionDidFinish
{
    [super onEnterTransitionDidFinish];
    [[SimpleAudioEngine sharedEngine] playBackgroundMusic:@"ebaLoop.mp3" loop:YES];
    
    if (![Registry getIsMenuMusicPlaying])
    {
        [[SimpleAudioEngine sharedEngine] playBackgroundMusic:@"ebaLoop.mp3" loop:YES];
        [Registry setIsMenuMusicPlaying:YES];
    }
    
}

-(void)dealloc
{
	[super dealloc];
}

-(void)singlePressed:(id)sender
{
    [Registry setIsSinglePlayer:YES];
    [[CCDirector sharedDirector] replaceScene:[CharacterSelectLayer scene]];
    [[SimpleAudioEngine sharedEngine] playEffect:@"select.wav"];
    
}

-(void)multiPressed:(id)sender
{
    [Registry setIsSinglePlayer:NO];
    [[SimpleAudioEngine sharedEngine] playEffect:@"select.wav"];
    [[CCDirector sharedDirector] replaceScene:[CharacterSelectLayer scene]];

}

-(void)optionsPressed:(id)sender
{
    [[CCDirector sharedDirector] pushScene:[OptionsLayer scene]];
    [[SimpleAudioEngine sharedEngine] playEffect:@"select.wav"];
}
@end
