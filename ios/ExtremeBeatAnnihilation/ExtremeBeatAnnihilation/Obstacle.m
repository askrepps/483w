//
//  Obstacle.m
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 11/14/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "Obstacle.h"
#import "Registry.h"

@implementation Obstacle

-(id)initWithX:(NSInteger)x andType:(Type)type
{
    NSString *file;
    NSInteger y;
    
    switch(type)
    {
        case JUMP:
            file = @"smallFire.png";
            y = 200;
            break;
        case SLIDE:
            file = @"smallCoil.png";
            y = 300;
            break;
        default:
            break;
    }
    
    if(self = [super initWithFile:file])
    {
        self.position = ccp(x, y);
    }
    return self;
}

@end
