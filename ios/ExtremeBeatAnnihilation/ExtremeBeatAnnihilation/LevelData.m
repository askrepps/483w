//
//  LevelData.m
//  ExtremeBeatAnnihilation
//
//  Created by ANDREW STEPHEN KREPPS on 10/22/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "LevelData.h"

@implementation LevelData

-(id) initDefault
{
    if (self = [super init])
    {
        _numSamples = 410000;
        _events = [[NSMutableArray alloc] init];
        
        for (int i = 0; i < 9; i++)
        {
            SoundEvent *event = [[SoundEvent alloc] initWithSample:(i+1)*44100 andFreq:i*200.0f];
            [_events addObject:event];
            [event release];
        }
        
        [self setStats];
        
        for (SoundEvent *event in _events)
        {
            [event setAttributesWithQ1:_q1Freq andMedian:_medianFreq andQ3:_q3Freq];
        }
    }
    
    return self;
}

// Not implemented for now. Audio file parsing will happen here!
-(id) initWithAudioFile:(NSString *)filepath
{
    return [self initDefault];
}

-(void) setStats
{
    NSMutableArray *freqs = [[NSMutableArray alloc] init];
    
    for (SoundEvent *event in _events)
    {
        [freqs addObject:[NSNumber numberWithFloat:event.freq]];
    }
    
    NSArray *sortedFreqs = [freqs sortedArrayUsingSelector:@selector(compare:)];
    
    uint median = [sortedFreqs count] / 2;
    uint q1 = median / 2;
    uint q3 = q1 + median;
    
    _q1Freq = [[sortedFreqs objectAtIndex:q1] floatValue];
    _medianFreq = [[sortedFreqs objectAtIndex:median] floatValue];
    _q3Freq = [[sortedFreqs objectAtIndex:q3] floatValue];
    
    [freqs release];
}

-(void) dealloc
{
    [_events release];
    [super dealloc];
}

@end
