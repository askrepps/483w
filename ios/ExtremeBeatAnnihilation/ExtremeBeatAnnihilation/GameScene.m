//
//  GameScene.m
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 11/14/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "GameScene.h"
#import "LeftGroundLayer.h"
#import "LeftPlayer.h"
#import "LeftPlayerLayer.h"
#import "RightGroundLayer.h"
#import "RightPlayer.h"
#import "RightPlayerLayer.h"
#import "Obstacle.h"

@interface GameScene ()

@property (strong, nonatomic) LeftGroundLayer *leftGround;
@property (strong, nonatomic) RightGroundLayer *rightGround;
@property (strong, nonatomic) LeftPlayerLayer *leftPlayerLayer;
@property (strong, nonatomic) RightPlayerLayer *rightPlayerLayer;
@property (strong, nonatomic) NSMutableArray *obstacles;

@end

@implementation GameScene

@end