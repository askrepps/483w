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
    NSString *file;
    
    // Get the appropriate sprite sheet
    switch([Registry getCharOne])
    {
        case 0:
            file = @"char1.png";
            break;
        case 1:
            file = @"char1.png";
            break;
        case 2:
            file = @"char1.png";
            break;
        case 3:
            file = @"";
            break;
        default:
            break;
    }
    
    if(self = [super initWithFile:file])
    {
        
    }
    
    return self;
}

@end
