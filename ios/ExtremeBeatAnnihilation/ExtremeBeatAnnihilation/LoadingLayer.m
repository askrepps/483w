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
        CGSize size = [[CCDirector sharedDirector] winSize];
        
        CCLabelTTF *label = [CCLabelTTF labelWithString:@"Loading..." fontName:@"Marker Felt" fontSize:32];
        label.position = ccp(size.width/2, size.height/2);
        [self addChild:label];
        [self scheduleOnce:@selector(loadLevel) delay:0];
    }
    
    return self;
}
                                     
-(void) loadLevel
{
    [[SimpleAudioEngine sharedEngine] stopBackgroundMusic];
    NSLog(@"URL = %@", [Registry getMusicURL]);
    LevelData *data = [[LevelData alloc] initWithAudioFileURL:[Registry getMusicURL]];
    GameScene *gameScene = [[[GameScene alloc] initWithLevelData:data] autorelease];
    [data release];
    [[CCDirector sharedDirector] replaceScene:gameScene];
}



@end
