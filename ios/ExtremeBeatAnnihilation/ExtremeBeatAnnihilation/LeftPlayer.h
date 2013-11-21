//
//  LeftPlayer.h
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 10/20/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "cocos2d.h"

@interface LeftPlayer : CCSprite
@property BOOL canJump;
@property BOOL canBlink;
@property BOOL canSlide;

-(void)jump;
-(void)slide;
-(void)blink;
@end
