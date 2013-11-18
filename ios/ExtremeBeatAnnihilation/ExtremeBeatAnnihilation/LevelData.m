//
//  LevelData.m
//  ExtremeBeatAnnihilation
//
//  Created by ANDREW STEPHEN KREPPS on 10/22/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "LevelData.h"
#import "Registry.h"

@implementation LevelData

-(id) initDefault
{
    if (self = [super init])
    {
        _numSamples = 410000;
        _events = [[NSMutableArray alloc] init];
        _sampleRate = 44100;
        
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
-(id) initWithAudioFileURL:(NSURL *)url;
{
    if (self = [super init])
    {
        AudioFileID audioFile;
        UInt32 propertySize = 0;
        CFDictionaryRef dictionary;
        
        NSLog(@"Loading url: %@", url);
        
        OSStatus status = AudioFileOpenURL((CFURLRef)url, kAudioFileReadPermission, 0, &audioFile);
        NSLog(@"open status: %ld", status);
        status = AudioFileGetPropertyInfo(audioFile, kAudioFilePropertyInfoDictionary, &propertySize, 0);
        NSLog(@"dicitonary size: %d  | status: %ld", (unsigned int)propertySize, status);
        status = AudioFileGetProperty(audioFile, kAudioFilePropertyInfoDictionary, &propertySize, &dictionary);
        NSLog(@"dictionary status: %ld", status);
        
        NSLog(@"Audio file info: %@", dictionary);
        CFRelease(dictionary);
        
        AudioFileClose(audioFile);
    }
    
    return [self initDefault];
}

-(id) initWithAudioFilePath:(NSString *)filePath
{
    return [self initWithAudioFileURL:[NSURL fileURLWithPath:filePath]];
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
