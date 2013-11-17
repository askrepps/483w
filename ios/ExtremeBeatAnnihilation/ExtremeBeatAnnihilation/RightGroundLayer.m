//
//  RightGroundLayer.m
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 11/14/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "RightGroundLayer.h"

@implementation RightGroundLayer

-(id)init
{
	if((self=[super init]))
    {
        CGSize winSize = [[CCDirector sharedDirector] winSize];
        
        CCSprite *background = [CCSprite spriteWithFile:@"Resources/background_inverted.png"];
        background.position = ccp(winSize.width/2, winSize.height/2);
        [self addChild:background];
        
    }
    
    return self;
}

@end
