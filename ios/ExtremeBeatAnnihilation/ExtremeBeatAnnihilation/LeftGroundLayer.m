//
//  LeftGroundLayer.m
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 11/14/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "LeftGroundLayer.h"

@implementation LeftGroundLayer

-(id)init
{
	if((self=[super init]))
    {
        CGSize winSize = [[CCDirector sharedDirector] winSize];
        
        CCSprite *leftBackground = [CCSprite spriteWithFile:@"Resources/background.png"];
        background.position = ccp(winSize.width/2, winSize.height/2);
        [self addChild:background];
        
    }
    
    return self;
}
@end
