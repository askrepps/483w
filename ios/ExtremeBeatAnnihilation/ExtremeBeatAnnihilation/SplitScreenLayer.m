//
//  SplitScreenLayer.m
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 11/28/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "SplitScreenLayer.h"

@implementation SplitScreenLayer

-(void)visit
{
    glEnable(GL_SCISSOR_TEST);
    
    CGPoint worldPosition = [self convertToWorldSpace:CGPointZero];
    self.anchorPoint = ccp(worldPosition.x/self.contentSize.width, worldPosition.y/self.contentSize.height);
//    self.rotation = 180.0f;
//    glScissor(0,bounds.height/2,bounds.width,bounds.height/2);
    glScissor(0, 0, self.boundingBox.size.width/2, self.boundingBox.size.height);
    
    CCSprite *leftBG1 = [CCSprite spriteWithFile:@"background.png"];
    leftBG1.position = ccp(0,0);
    [self addChild:leftBG1];
    
    [super visit];
    glDisable(GL_SCISSOR_TEST);
}

@end
