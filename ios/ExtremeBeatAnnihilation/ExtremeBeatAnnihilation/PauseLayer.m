//
//  PauseLayer.m
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 12/5/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "PauseLayer.h"

@implementation PauseLayer

+(CCScene *)scene
{
	CCScene *scene = [CCScene node];
	PauseLayer *layer = [PauseLayer node];
	[scene addChild: layer];
    
	return scene;
}

@end
