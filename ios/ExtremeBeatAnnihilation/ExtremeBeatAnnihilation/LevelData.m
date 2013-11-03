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
        self.numSamples = 410000;
        self.events = [[NSMutableArray alloc] init];
        
        for (int i = 0; i < 9; i++)
        {
            SoundEvent *event = [[SoundEvent alloc] initWithSample:(i+1)*44100 andFreq:i*200.0f];
            [self.events addObject:event];
            [event release];
        }
        
        [self setStats];
        
        for (SoundEvent *event in self.events)
        {
            [event setAttributesWithQ1:self.q1Freq andMedian:self.medianFreq andQ3:self.q3Freq];
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
    
    for (SoundEvent *event in self.events)
    {
        [freqs addObject:[NSNumber numberWithFloat:event.freq]];
    }
    
    NSArray *sortedFreqs = [freqs sortedArrayUsingSelector:@selector(compare:)];
    
    uint median = [sortedFreqs count] / 2;
    uint q1 = median / 2;
    uint q3 = q1 + median;
    
    self.q1Freq = [[sortedFreqs objectAtIndex:q1] floatValue];
    self.medianFreq = [[sortedFreqs objectAtIndex:median] floatValue];
    self.q3Freq = [[sortedFreqs objectAtIndex:q3] floatValue];
    
    [freqs release];
}

-(void) dealloc
{
    [self.events release];
    [super dealloc];
}

@end
