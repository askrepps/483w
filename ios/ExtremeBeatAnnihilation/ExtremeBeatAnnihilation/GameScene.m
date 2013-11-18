//
//  GameScene.m
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 11/14/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "GameScene.h"
#import "LeftPlayer.h"
#import "RightPlayer.h"
#import "Obstacle.h"
#import "SoundEvent.h"

@interface GameScene () 

@property (strong, nonatomic) CCLayer *leftGround;
@property (strong, nonatomic) CCLayer *rightGround;
@property (strong, nonatomic) CCLayer *leftPlayerLayer;
@property (strong, nonatomic) CCLayer *rightPlayerLayer;
@property (strong, nonatomic) NSMutableArray *obstacles;

@end

@implementation GameScene

-(id) initWithLevelData:(LevelData *)levelData
{
    if (self = [super init])
    {
        
        CGSize winSize = [[CCDirector sharedDirector] winSize];

        
        _obstacles = [[NSMutableArray alloc] init];
        for (SoundEvent *event in [levelData events])
        {
            // add constructed obstacle to obstacles / layer
        }
        
        [self scheduleUpdate];
        
        _leftGround = [CCLayer node];
        _rightGround = [CCLayer node];
        _leftPlayerLayer = [CCLayer node];
        _rightPlayerLayer = [CCLayer node];
        
        CCSprite *leftBackground = [CCSprite spriteWithFile:@"Resources/background.png"];
        CCSprite *rightBackground = [CCSprite spriteWithFile:@"Resources/background_inverted.png"];
        
        leftBackground.position = ccp(winSize.width/2, winSize.height/2);
        rightBackground.position = ccp(winSize.width/2, winSize.height/2);
        
        [_leftGround addChild:leftBackground];
        [_rightGround addChild:rightBackground];
        
        _leftPlayerLayer.touchEnabled = YES;
        _rightPlayerLayer.touchEnabled = YES;
        
        [self addChild:_leftGround z:0];
        [self addChild:_rightGround z:0];
        [self addChild:_leftPlayerLayer z:1];
        [self addChild:_rightPlayerLayer z:1];
         
        

    }
    
    return self;
}

-(void)update:(ccTime)delta
{
    
}

-(void) dealloc
{
    [_obstacles release];
    [super dealloc];
}

@end