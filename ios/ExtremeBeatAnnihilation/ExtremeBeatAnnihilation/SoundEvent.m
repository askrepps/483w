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
        self.sample = s;
        self.freq = f;
    }
    
    return self;
}

-(void) setAttributesWithQ1:(float)q1Freq andMedian:(float)medianFreq andQ3:(float)q3Freq
{
    if (self.freq < q1Freq)
    {
        self.side = LEFT;
        self.type = SLIDE;
    }
    else if (self.freq < medianFreq)
    {
        self.side = LEFT;
        self.type = JUMP;
    }
    else if (self.freq < q3Freq)
    {
        self.side = RIGHT;
        self.type = SLIDE;
    }
    else
    {
        self.side = RIGHT;
        self.type = JUMP;
    }
}

@end
