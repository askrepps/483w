//
//  RightPlayerLayer.m
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 11/14/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "RightPlayerLayer.h"
#import "RightPlayer.h"

@interface RightPlayerLayer ()
@property (strong, nonatomic) RightPlayer *player;
@end

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
