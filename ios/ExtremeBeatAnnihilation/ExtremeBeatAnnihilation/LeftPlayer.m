//
//  LeftPlayer.m
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 10/20/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "LeftPlayer.h"
#import "Registry.h"

@implementation LeftPlayer

-(id)init
{
    // Get the appropriate sprite sheet
    switch([Registry getCharOne])
    {
        case 0:
            self.fileName = @"red";
            break;
        case 1:
            self.fileName = @"blue";
            break;
        case 2:
            self.fileName = @"green";
            break;
        default:
            break;
    }
    
    if(self = [super init])
    {
        self.flipX = NO;
    }
    
    return self;
}

@end
