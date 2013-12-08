//
//  RightPlayer.m
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 10/20/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "RightPlayer.h"
#import "Registry.h"

@implementation RightPlayer

-(id)init
{
    // Get the appropriate sprite sheet
    switch([Registry getCharTwo])
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
        self.flipX = YES;
    }
    
    return self;
}

@end