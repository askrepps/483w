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
        
        for (int i = 0; i < 225; i++)
        {
            SoundEvent *event = [[SoundEvent alloc] initWithSample:(i+1)*44100 andFreq:arc4random_uniform(4)];//i*200.0f];
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
        ExtAudioFileRef audioFile;
        OSStatus status;
        UInt32 propertySize;
        SInt64 nFrames;
        UInt32 nFrames32;
        UInt32 nChannels;
        Float64 sampleRate;
        AudioStreamBasicDescription asbd;
        AudioStreamBasicDescription format;
        AudioBufferList bufList;
        float *buffer;
        
        status = ExtAudioFileOpenURL((CFURLRef)url, &audioFile);
        NSLog(@"opened file: status = %d", (int)status);
        
        propertySize = sizeof(asbd);
        status = ExtAudioFileGetProperty(audioFile, kExtAudioFileProperty_FileDataFormat, &propertySize, &asbd);
        NSLog(@"read ASBD: status = %d", (int)status);
        
        sampleRate = asbd.mSampleRate;
        nChannels = asbd.mChannelsPerFrame;
        NSLog(@"sampleRate: %f  |  numChannels: %d", asbd.mSampleRate, (unsigned int)asbd.mChannelsPerFrame);
        
        propertySize = sizeof(SInt64);
        status = ExtAudioFileGetProperty(audioFile, kExtAudioFileProperty_FileLengthFrames, &propertySize, &nFrames);
        nFrames32 = (UInt32)nFrames;
        NSLog(@"numFrames: %d", (unsigned int)nFrames32);
        
        format.mSampleRate = sampleRate;
        format.mFormatID = kAudioFormatLinearPCM;
        format.mFormatFlags = kAudioFormatFlagsNativeFloatPacked;
        format.mBitsPerChannel = 32;
        format.mChannelsPerFrame = 1;
        format.mBytesPerFrame = format.mChannelsPerFrame * sizeof(float);
        format.mFramesPerPacket = 1;
        format.mBytesPerPacket = format.mFramesPerPacket * format.mBytesPerFrame;
        
        propertySize = sizeof(format);
        status = ExtAudioFileSetProperty(audioFile, kExtAudioFileProperty_ClientDataFormat, propertySize, &format);
        NSLog(@"set client format: status = %d", (int)status);

        buffer = malloc(sizeof(UInt32) * kBufferSize);
        
        bufList.mNumberBuffers = 1;
        bufList.mBuffers[0].mNumberChannels = 1;
        bufList.mBuffers[0].mDataByteSize = kBufferSize * sizeof(float);
        bufList.mBuffers[0].mData = buffer;
        
        int count = 0;
        do {
            propertySize = kBufferSize;
            status = ExtAudioFileRead(audioFile, &propertySize, &bufList);
            
            NSLog(@"Reading %d samples... status = %d", (unsigned int)propertySize, (int)status);
            count++;
        } while (propertySize > 0);
        
        NSLog(@"%d", count);
        
        free(buffer);
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
