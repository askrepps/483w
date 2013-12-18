//
//  LoadingLayer.m
//  ExtremeBeatAnnihilation
//
//  Created by Andrew Krepps on 11/15/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "LoadingLayer.h"
#import "Registry.h"
#import "MenuLayer.h"
#import "GameScene.h"
#import "SimpleAudioEngine.h"
#import "MusicSelectLayer.h"

@interface LoadingLayer ()

@property (strong, nonatomic) LevelData *data;

@end

@implementation LoadingLayer

+(CCScene *)scene
{
	CCScene *scene = [CCScene node];
	LoadingLayer *layer = [LoadingLayer node];
	[scene addChild: layer];
    
	return scene;
}

-(id) init
{
    if (self = [super init])
    {
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(loadGame:) name:GameReady object:nil];
        
        CGSize size = [[CCDirector sharedDirector] winSize];
        
        CCLabelTTF *label = [CCLabelTTF labelWithString:@"Loading..." fontName:@"Marker Felt" fontSize:32];
        label.position = ccp(size.width/2, size.height/2);
        [self addChild:label];
        [self scheduleOnce:@selector(loadLevel) delay:0];
    }
    
    return self;
}

-(void) onEnter
{
    [super onEnter];
    [[SimpleAudioEngine sharedEngine] stopBackgroundMusic];
    [Registry setIsMenuMusicPlaying:NO];
}

-(void)dealloc
{
    [super dealloc];
    [_data release];
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}
                                     
-(void) loadLevel
{
    NSLog(@"URL = %@", [Registry getMusicURL]);
    _data = [[[LevelData alloc] initWithURL:[Registry getMusicURL]] retain];
}

-(void) loadGame:(NSNotification*)notification
{
    LevelData *data = [notification.userInfo objectForKey:@"levelData"];
    
    if (data != NULL)
    {
        GameScene *gameScene = [[[GameScene alloc] initWithLevelData:data] autorelease];
        [data release];
        [[CCDirector sharedDirector] replaceScene:gameScene];
    }
    else
    {
        NSLog(@"uh oh...");
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Error" message:@"Error loading song. Please choose another song." delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
        [alert show];
        [[CCDirector sharedDirector] replaceScene:[MusicSelectLayer scene]];
    }
}



@end
