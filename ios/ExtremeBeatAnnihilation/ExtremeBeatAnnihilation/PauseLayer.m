//
//  PauseLayer.m
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 12/5/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "PauseLayer.h"
#import "OptionsLayer.h"
#import "MenuLayer.h"
#import "Registry.h"
#import "GameScene.h"

@interface PauseLayer ()

@property (nonatomic, retain) GameScene *gameScene;

@end

@implementation PauseLayer


-(id)initWithGameScene:(GameScene *)scene
{
    if((self = [super init]))
    {
        _gameScene = scene;
        CCMenuItemFont *unPause = [CCMenuItemFont itemWithString:@"Return to Game" target:self selector:@selector(unPausePressed)];
        CCMenuItemFont *quit = [CCMenuItemFont itemWithString:@"Quit" target:self selector:@selector(quitPressed)];
        CCMenu *pauseMenu = [CCMenu menuWithItems:unPause, quit, nil];
        [pauseMenu alignItemsVertically];
        
        [self addChild: pauseMenu];
    }
    
    return self;
}

//will this work?

#pragma mark - Button presses

-(void)unPausePressed
{
    [[self gameScene] resumeGame];
}

-(void)quitPressed
{
    [Registry clean];
    [[CCDirector sharedDirector] replaceScene:[MenuLayer scene]];
    
}

@end
