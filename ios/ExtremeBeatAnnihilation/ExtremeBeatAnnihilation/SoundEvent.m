//
//  SoundEvent.m
//  ExtremeBeatAnnihilation
//
//  Created by Andrew Krepps on 11/2/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "SoundEvent.h"

@implementation SoundEvent

-(id) initWithSample:(uint)s andFreq:(float)f
{
    if (self = [super init])
    {
        _sample = s;
        _freq = f;
    }
    
    return self;
}

-(void) setAttributesWithQ1:(float)q1Freq andMedian:(float)medianFreq andQ3:(float)q3Freq
{
    if (_freq <= q1Freq)
    {
        _side = LEFT;
        _type = JUMP;
    }
    else if (self.freq <= medianFreq)
    {
        _side = LEFT;
        _type = JUMP;
    }
    else if (self.freq <= q3Freq)
    {
        _side = RIGHT;
        _type = SLIDE;
    }
    else
    {
        _side = RIGHT;
        _type = JUMP;
    }
}

@end
