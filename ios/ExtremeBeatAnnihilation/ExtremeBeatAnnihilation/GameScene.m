//
//  GameScene.m
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 11/14/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "GameScene.h"
#import "LeftGroundLayer.h"
#import "LeftPlayerLayer.h"
#import "RightGroundLayer.h"
#import "RightPlayerLayer.h"
#import "Obstacle.h"
#import "SoundEvent.h"

@interface GameScene ()

@property (strong, nonatomic) LeftGroundLayer *leftGround;
@property (strong, nonatomic) RightGroundLayer *rightGround;
@property (strong, nonatomic) LeftPlayerLayer *leftPlayerLayer;
@property (strong, nonatomic) RightPlayerLayer *rightPlayerLayer;
@property (strong, nonatomic) NSMutableArray *obstacles;

@end

@implementation GameScene

-(id) initWithLevelData:(LevelData *)levelData
{
    if (self = [super init])
    {
        
        
        _obstacles = [[NSMutableArray alloc] init];
        for (SoundEvent *event in [levelData events])
        {
            // add constructed obstacle to obstacles / layer
        }
        
        [self scheduleUpdate];
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