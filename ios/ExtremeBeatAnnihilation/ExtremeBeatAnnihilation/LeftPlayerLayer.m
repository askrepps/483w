//
//  LeftPlayerLayer.m
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 11/14/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "LeftPlayerLayer.h"
#import "LeftPlayer.h"

@interface LeftPlayerLayer ()
@property (strong, nonatomic) LeftPlayer *player;
@end

@implementation LeftPlayerLayer

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
