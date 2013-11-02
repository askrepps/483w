//
//  BackgroundLayer.m
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 11/2/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "BackgroundLayer.h"

@implementation BackgroundLayer

-(id)init
{
	if((self=[super init]))
    {
        // Add background image
        CCSprite* background = [CCSprite spriteWithFile:@"TitleImage.jpg"];
        background.anchorPoint = CGPointMake(0.0, 0.0);
        [self addChild:background];
	}
    
	return self;
}

-(void)dealloc
{
    [super dealloc];
}

@end
