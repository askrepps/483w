//
//  MenuLayer.m
//  ExtremeBeatAnnihilation
//
//  Created by ROBERT WILLIAM CARRIER on 9/11/13.
//  Copyright Crash Course Gaming 2013. All rights reserved.
//

// Import the interfaces
#import "MenuLayer.h"
#import "AppDelegate.h"
#import "BackgroundLayer.h"
#import "SettingsLayer.h"
#import "CharacterSelectLayer.h"
#import "Registry.h"
#import "SimpleAudioEngine.h"

#pragma mark - MenuLayer

@implementation MenuLayer

+(CCScene *)scene
{
	CCScene *scene = [CCScene node];
	
    BackgroundLayer *background = [BackgroundLayer node];
	MenuLayer *menu = [MenuLayer node];
	
    [scene addChild:background z:-1];
	[scene addChild: menu];
	
	return scene;
}

-(id)init
{
	if((self=[super init]))
    {
        // Add buttons for starting the game and accessing options
        CCMenuItemFont *single = [CCMenuItemFont itemWithString:@"Single Player" target:self selector:@selector(singlePressed:)];
        CCMenuItemFont *multi = [CCMenuItemFont itemWithString:@"Multiplayer" target:self selector:@selector(multiPressed:)];
        CCMenuItemFont *options = [CCMenuItemFont itemWithString:@"Settings" target:self selector:@selector(optionsPressed:)];
        
        CCMenu *startMenu = [CCMenu menuWithItems:single, multi, options, nil];
        [startMenu alignItemsVertically];
        [self addChild:startMenu];
    }
    
	return self;
}

-(void)onEnterTransitionDidFinish
{
    [super onEnterTransitionDidFinish];
    if (![Registry getIsMenuMusicPlaying])
    {
        NSUserDefaults *preferences = [NSUserDefaults standardUserDefaults];
        NSNumber *value = [preferences objectForKey:kVolume];
        [[SimpleAudioEngine sharedEngine] setEffectsVolume:value.floatValue];
        [[SimpleAudioEngine sharedEngine] setBackgroundMusicVolume:value.floatValue];
        
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
    [[CCDirector sharedDirector] pushScene:[SettingsLayer scene]];
    [[SimpleAudioEngine sharedEngine] playEffect:@"select.wav"];
}
@end
