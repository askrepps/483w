//
//  PlayerSprite.h
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 12/8/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "cocos2d.h"

@interface PlayerSprite : CCSprite
@property (strong, nonatomic) NSString *fileName;

-(void)jump;
-(void)slide;
-(void)blink;
-(BOOL)isBlinking;
-(BOOL)isJumping;
-(BOOL)isSliding;
-(void)pause;
-(void)move;
@end