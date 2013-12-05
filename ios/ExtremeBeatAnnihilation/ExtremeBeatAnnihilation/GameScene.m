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
#import "ClippingNode.h"
#import "GameOverLayer.h"
#import "PauseLayer.h"

@interface GameScene () 

@property (strong, nonatomic) ClippingNode *leftNode;
@property (strong, nonatomic) ClippingNode *rightNode;
@property (strong, nonatomic) CCLayer *leftGround;
@property (strong, nonatomic) CCLayer *rightGround;
@property (strong, nonatomic) CCLayer *leftPlayerLayer;
@property (strong, nonatomic) CCLayer *rightPlayerLayer;
@property (strong, nonatomic) LeftPlayer *leftPlayer;
@property (strong, nonatomic) RightPlayer *rightPlayer;
@property (strong, nonatomic) NSMutableArray *leftObstacles;
@property (strong, nonatomic) NSMutableArray *rightObstacles;
@property (strong, nonatomic) CCSprite *leftBG1;
@property (strong, nonatomic) CCSprite *leftBG2;
@property (strong, nonatomic) CCSprite *rightBG1;
@property (strong, nonatomic) CCSprite *rightBG2;
@property (strong, nonatomic) AVAudioPlayer *avPlayer;
@property (strong, nonatomic) CCLabelTTF *scoreLabel;
@property NSInteger score;
@property (strong, nonatomic) PauseLayer *pauseLayer;

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
        
        // Create the clipping nodes
        
        _leftNode = [ClippingNode node];
        [_leftNode setClippingRegion:CGRectMake(0, 0, winSize.width/2, winSize.height)];
        [self addChild:_leftNode];
        
        _rightNode = [ClippingNode node];
        [_rightNode setClippingRegion:CGRectMake(winSize.width/2, 0, winSize.width/2, winSize.height)];
        [self addChild:_rightNode];
        
        // Create layers

        _leftGround = [CCLayer node];
        _rightGround = [CCLayer node];
        
        _leftPlayerLayer = [CCLayer node];
        _rightPlayerLayer = [CCLayer node];
        
        // Add backgrounds
        
        _leftBG1 = [CCSprite spriteWithFile:@"background.png"];
        _leftBG2 = [CCSprite spriteWithFile:@"background.png"];
        _rightBG1 = [CCSprite spriteWithFile:@"background_inverted.png"];
        _rightBG2 = [CCSprite spriteWithFile:@"background_inverted.png"];
        
        _leftBG1.position = ccp(winSize.width/2, winSize.height/2);
        _leftBG2.position = ccp(winSize.width*3/2, winSize.height/2);
        _rightBG1.position = ccp(winSize.width/2, winSize.height/2);
        _rightBG2.position = ccp(-winSize.width/2, winSize.height/2);
        
        [_leftGround addChild:_leftBG1];
        [_leftGround addChild:_leftBG2];
        [_rightGround addChild:_rightBG1];
        [_rightGround addChild:_rightBG2];
        
        // Create players
        
        _leftPlayer = [[LeftPlayer alloc] init];
        _leftPlayer.position = ccp(winSize.width/6, winSize.height/3);
        [_leftGround addChild:_leftPlayer z:1];
        
        _rightPlayer = [[RightPlayer alloc] init];
        _rightPlayer.position = ccp(winSize.width/6*5, winSize.height/3);
        [_rightGround addChild:_rightPlayer z:1];
        
        _leftPlayerLayer.touchEnabled = YES;
        _rightPlayerLayer.touchEnabled = YES;
        
        // Create Obstacles
        
        _leftObstacles = [[NSMutableArray alloc] init];
        _rightObstacles = [[NSMutableArray alloc] init];
        
        uint layerWidth = (float)levelData.numSamples/levelData.sampleRate*kVelocity + kLevelOffset;
        
        for (SoundEvent *event in [levelData events])
        {
            // add constructed obstacle to obstacles / layer
            Obstacle *obs;
            NSInteger x;
            
            switch(event.side)
            {
                case LEFT:
                    x = (float)event.sample/levelData.sampleRate*kVelocity + kLevelOffset;
                    obs = [[Obstacle alloc] initWithX:x andType:event.type];
                    [_leftObstacles addObject:obs];
                    [_leftGround addChild:obs];
                    break;
                case RIGHT:
                    x = layerWidth - (float)event.sample/levelData.sampleRate*kVelocity - kLevelOffset;
                    obs = [[Obstacle alloc] initWithX:x andType:event.type];
                    [_rightObstacles addObject:obs];
                    [_rightGround addChild:obs];
                    break;
                default:
                    break;
            }
            
            [obs release];
        }
        
        [_leftNode addChild:_leftGround z:0];
        [_leftNode addChild:_leftPlayerLayer z:1];
        [_rightNode addChild:_rightGround z:0];
        [_rightNode addChild:_rightPlayerLayer z:1];
        
        // Create menu items
        
        _score = 0;
        _scoreLabel = [CCLabelTTF labelWithString:[NSString stringWithFormat:@"%d", _score] fontName:@"Marker Felt" fontSize:24];
        _scoreLabel.position = ccp(winSize.width/2, winSize.height - 24);
        
        CCMenuItemFont *pause = [CCMenuItemFont itemWithString:@"Pause" target:self selector:@selector(pausePressed)];
        pause.position = ccp(winSize.width/4, winSize.height - 24);
        
        CCMenu *menu = [CCMenu menuWithItems:pause, nil];
        menu.position = CGPointZero;
        
        [self addChild:_scoreLabel];
        [self addChild:menu];
        
        // Start playing music
        _avPlayer = [[AVAudioPlayer alloc] initWithContentsOfURL:[Registry getMusicURL] error:nil];
        NSUserDefaults *preferences = [NSUserDefaults standardUserDefaults];
        NSNumber *value = [preferences objectForKey:kVolume];
        _avPlayer.volume = value.floatValue;
        _avPlayer.delegate = self;
        [_avPlayer play];
    }
    
    return self;
}

-(void) dealloc
{
    [_leftObstacles release];
    [_rightObstacles release];
    [_avPlayer release];
    [super dealloc];
}

-(void)update:(ccTime)delta
{
    CGSize winSize = [[CCDirector sharedDirector] winSize];
    
    
    // Shift left background
    if (self.leftBG1.position.x + self.leftGround.position.x < -winSize.width/2)
    {
        self.leftBG1.position = ccp(self.leftBG2.position.x + winSize.width, winSize.height/2);
    }
    if (self.leftBG2.position.x + self.leftGround.position.x < -winSize.width/2)
    {
        self.leftBG2.position = ccp(self.leftBG1.position.x + winSize.width, winSize.height/2);
    }
    
    // Shift right background
    if (self.rightBG1.position.x + self.rightGround.position.x > winSize.width + winSize.width/2)
    {
        self.rightBG1.position = ccp(self.rightBG2.position.x - winSize.width, winSize.height/2);
    }
    if (self.rightBG2.position.x + self.rightGround.position.x > winSize.width + winSize.width/2)
    {
        self.rightBG2.position = ccp(self.rightBG1.position.x - winSize.width, winSize.height/2);
    }
    
    // Move left player
    self.leftPlayer.position = ccp(self.leftPlayer.position.x + kVelocity*delta, self.leftPlayer.position.y);
    self.leftGround.position = ccp(self.leftGround.position.x - kVelocity*delta, self.leftGround.position.y);
    
    // Move right player
    self.rightPlayer.position = ccp(self.rightPlayer.position.x - kVelocity*delta, self.rightPlayer.position.y);
    self.rightGround.position = ccp(self.rightGround.position.x + kVelocity*delta, self.rightGround.position.y);
    
    // Collision detection
    for (Obstacle *obs in self.leftObstacles)
    {
        if (!self.leftPlayer.isBlinking && CGRectIntersectsRect(self.leftPlayer.boundingBox, obs.boundingBox))
        {
            [self.leftPlayer blink];
            //[obs hitByCharacter];
            self.score-=1000;
        }
    }
    
    for (Obstacle *obs in self.rightObstacles)
    {
        if (!self.rightPlayer.isBlinking && CGRectIntersectsRect(self.rightPlayer.boundingBox, obs.boundingBox))
        {
            [self.rightPlayer blink];
            self.score-=1000;
        }
    }
    
    self.score+=10;
    [self.scoreLabel setString:[NSString stringWithFormat:@"%d", self.score]];
}

#pragma mark - AVAudioPlayerDelegate Methods

-(void)audioPlayerDidFinishPlaying:(AVAudioPlayer *)player successfully:(BOOL)flag
{
    [Registry setScore:self.score];
    [[CCDirector sharedDirector] replaceScene:[GameOverLayer scene]];
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
            NSLog(@"Congratulations, you have broken the physical laws of reality.");
        }
    }
}

#pragma mark - Button Presses

-(void)pausePressed
{
    //Present pause screen as primary layer
    [self.avPlayer pause];
    [self unscheduleUpdate];
    
    [self.avPlayer play];
    [self scheduleUpdate];
}

@end