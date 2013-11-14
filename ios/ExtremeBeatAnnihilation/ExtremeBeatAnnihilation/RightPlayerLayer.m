//
//  RightPlayerLayer.m
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 11/14/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "RightPlayerLayer.h"

@implementation RightPlayerLayer

-(id)init
{
    if([super init])
    {
        self.touchEnabled = YES;
    }
    return self;
}

#pragma mark - Touch Controls

-(void)ccTouchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    
}

@end
