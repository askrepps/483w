//
//  LoadingLayer.m
//  ExtremeBeatAnnihilation
//
//  Created by Andrew Krepps on 11/15/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "LoadingLayer.h"

@implementation LoadingLayer

+(CCScene *)scene
{
	CCScene *scene = [CCScene node];
	LoadingLayer *layer = [LoadingLayer node];
	[scene addChild: layer];
    
	return scene;
}

-(id) init
{
    if (self = [super init])
    {
        CGSize size = [[CCDirector sharedDirector] winSize];
        
        CCLabelTTF *label = [CCLabelTTF labelWithString:@"Loading..." fontName:@"Marker Felt" fontSize:32];
        label.position = ccp(size.width/2, size.height/2);
        [self addChild:label];
    }
    
    return self;
}

@end
