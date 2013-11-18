//
//  GameScene.m
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 11/14/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "GameScene.h"
#import "Registry.h"
#import "LeftPlayer.h"
#import "RightPlayer.h"
#import "Obstacle.h"
#import "SoundEvent.h"
#import "LeftPlayer.h"
#import "RightPlayer.h"

@interface GameScene () 

@property (strong, nonatomic) CCLayer *leftGround;
@property (strong, nonatomic) CCLayer *rightGround;
@property (strong, nonatomic) CCLayer *leftPlayerLayer;
@property (strong, nonatomic) CCLayer *rightPlayerLayer;
@property (strong, nonatomic) LeftPlayer *leftPlayer;
@property (strong, nonatomic) RightPlayer *rightPlayer;
@property (strong, nonatomic) NSMutableArray *leftObstacles;
@property (strong, nonatomic) NSMutableArray *rightObstacles;

@end

@implementation GameScene

-(id) initWithLevelData:(LevelData *)levelData
{
    if (self = [super init])
    {
        CGSize winSize = [[CCDirector sharedDirector] winSize];
        
        [[[CCDirector sharedDirector] touchDispatcher] addStandardDelegate:self priority:0];
        [[[CCDirector sharedDirector] view] setMultipleTouchEnabled:YES];
        
        [self scheduleUpdate];
        
        // Create layers
        
        _leftGround = [CCLayer node];
        _rightGround = [CCLayer node];
        _leftPlayerLayer = [CCLayer node];
        _rightPlayerLayer = [CCLayer node];
        
        // Add backgrounds
        
        CCSprite *leftBackground = [CCSprite spriteWithFile:@"background.png"];
        CCSprite *rightBackground = [CCSprite spriteWithFile:@"background_inverted.png"];
        
        leftBackground.position = ccp(winSize.width/2, winSize.height/2);
        rightBackground.position = ccp(winSize.width/2, winSize.height/2);
        
        // Create players
        
        _leftPlayer = [[LeftPlayer alloc] init];
        _leftPlayer.position = ccp(winSize.width/4, winSize.height/2);
        [_leftGround addChild:_leftPlayer z:1];
        
        _rightPlayer = [[RightPlayer alloc] init];
        _rightPlayer.position = ccp(winSize.width/4*3, winSize.height/2);
        [_rightGround addChild:_rightPlayer z:1];
        
        [_leftGround addChild:leftBackground];
        [_rightGround addChild:rightBackground];
        
        _leftPlayerLayer.touchEnabled = YES;
        _rightPlayerLayer.touchEnabled = YES;
        
        // Create Obstacles
        
        _leftObstacles = [[NSMutableArray alloc] init];
        _rightObstacles = [[NSMutableArray alloc] init];
        
        uint layerWidth = (float)levelData.numSamples/levelData.sampleRate*kVelocity;
        
        for (SoundEvent *event in [levelData events])
        {
            // add constructed obstacle to obstacles / layer
            Obstacle *obs;
            NSInteger x;
            
            switch(event.side)
            {
                case LEFT:
                    x = (float)event.sample/levelData.sampleRate*kVelocity;
                    obs = [[Obstacle alloc] initWithX:x andType:event.type];
                    [_leftObstacles addObject:obs];
                    [_leftGround addChild:obs];
                    break;
                case RIGHT:
                    x = layerWidth - (float)event.sample/levelData.sampleRate*kVelocity;
                    obs = [[Obstacle alloc] initWithX:x andType:event.type];
                    [_rightObstacles addObject:obs];
                    [_rightGround addChild:obs];
                    break;
                default:
                    break;
            }
            
            [obs release];
        }
        
        [self addChild:_leftGround z:0];
        [self addChild:_rightGround z:0];
        [self addChild:_leftPlayerLayer z:1];
        [self addChild:_rightPlayerLayer z:1];
    }
    
    return self;
}

-(void)update:(ccTime)delta
{
    // Move left player
    self.leftPlayer.position = ccp(self.leftPlayer.position.x + kVelocity*delta, self.leftPlayer.position.y);
    self.leftGround.position = ccp(self.leftGround.position.x - kVelocity*delta, self.leftGround.position.y);
    
    // Move right player
    self.rightPlayer.position = ccp(self.rightPlayer.position.x - kVelocity*delta, self.rightPlayer.position.y);
    self.rightGround.position = ccp(self.rightGround.position.x + kVelocity*delta, self.rightGround.position.y);
}

-(void) dealloc
{
    [_leftObstacles release];
    [_rightObstacles release];
    [super dealloc];
}

#pragma mark - Touch Handling

-(void)ccTouchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    CGSize winSize = [[CCDirector sharedDirector] winSize];
    
    CGPoint currentLocation;
    
    for(UITouch *touch in [event allTouches])
    {
        currentLocation = [touch locationInView:[touch view]];
        currentLocation = [[CCDirector sharedDirector] convertToGL:currentLocation];
        
        if(CGRectContainsPoint(CGRectMake(0, 0, winSize.width/2, winSize.height/2), currentLocation))
        {
            // left player slide
        }
        else if(CGRectContainsPoint(CGRectMake(0, winSize.height/2, winSize.width/2, winSize.height/2), currentLocation))
        {
            // left player jump
            [self.leftPlayer jump];
        }
        else if(CGRectContainsPoint(CGRectMake(winSize.width/2, 0, winSize.width/2, winSize.height/2), currentLocation))
        {
            // right player slide
        }
        else if(CGRectContainsPoint(CGRectMake(winSize.width/2, winSize.height/2, winSize.width/2, winSize.height/2), currentLocation))
        {
            // right player jump
            [self.rightPlayer jump];
        }
        else
        {
            NSLog(@"Fuck we dun goofed.");
        }
    }
}

@end