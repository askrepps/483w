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
        UInt32 nChannels;
        AudioStreamBasicDescription asbd;
        AudioStreamBasicDescription format;
        AudioBufferList bufList;
        float *buffer;
        UInt32 bufferSize;
        Peak *envelope;
        
        status = ExtAudioFileOpenURL((CFURLRef)url, &audioFile);
        NSLog(@"opened file: status = %d", (int)status);
        
        propertySize = sizeof(asbd);
        status = ExtAudioFileGetProperty(audioFile, kExtAudioFileProperty_FileDataFormat, &propertySize, &asbd);
        NSLog(@"read ASBD: status = %d", (int)status);
        
        _sampleRate = asbd.mSampleRate;
        nChannels = asbd.mChannelsPerFrame;
        NSLog(@"sampleRate: %f  |  numChannels: %d", asbd.mSampleRate, (unsigned int)asbd.mChannelsPerFrame);
        
        propertySize = sizeof(SInt64);
        status = ExtAudioFileGetProperty(audioFile, kExtAudioFileProperty_FileLengthFrames, &propertySize, &nFrames);
        _numSamples = nFrames;
        NSLog(@"numSamples: %d", _numSamples);
        
        format.mSampleRate = _sampleRate;
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
        
        bufferSize = (UInt32)(_sampleRate / 4);
        buffer = malloc(sizeof(float) * bufferSize);
        envelope = malloc(sizeof(Peak) * ((nFrames / bufferSize) + 2));
        
        bufList.mNumberBuffers = 1;
        bufList.mBuffers[0].mNumberChannels = 1;
        bufList.mBuffers[0].mDataByteSize = bufferSize * sizeof(float);
        bufList.mBuffers[0].mData = buffer;
        
        int count = 0;
        int offset;
        float max = 0;
        
        do
        {
            propertySize = bufferSize;
            status = ExtAudioFileRead(audioFile, &propertySize, &bufList);
            
            NSLog(@"Reading %d samples... status = %d", (unsigned int)propertySize, (int)status);
            
            max = 0;
            for (int i = 0; i < bufferSize; i++)
            {
                if (buffer[i] > max)
                {
                    max = buffer[i];
                    offset = i;
                }
            }
            
            envelope[count].sample = count*bufferSize + offset;
            envelope[count].amp = max;
            envelope[count].freq = 0;
            count++;
        } while (propertySize > 0);
        
        NSLog(@"%d", count);
        
        _events = [[NSMutableArray alloc] init];
        
        if (count > 1 && envelope[0].amp > envelope[1].amp)
        {
            NSLog(@"sample: %d  | amp: %f", (unsigned int)envelope[0].sample, envelope[0].amp);
            SoundEvent *event = [[SoundEvent alloc] initWithSample:envelope[0].sample andFreq:100];
            [_events addObject:event];
            [event release];
        }
        
        for (int i = 1; i < count-1; i++)
        {
            if (envelope[i].amp > envelope[i+1].amp && envelope[i].amp > envelope[i-1].amp)
            {
                NSLog(@"sample: %d  | amp: %f", (unsigned int)envelope[i].sample, envelope[i].amp);
                SoundEvent *event = [[SoundEvent alloc] initWithSample:envelope[i].sample andFreq:100];
                [_events addObject:event];
                [event release];
            }
        }
        
        if (count > 1 && envelope[count-1].amp > envelope[count-2].amp)
        {
            NSLog(@"sample: %d  | amp: %f", (unsigned int)envelope[count-1].sample, envelope[count-1].amp);
            SoundEvent *event = [[SoundEvent alloc] initWithSample:envelope[count-1].sample andFreq:100];
            [_events addObject:event];
            [event release];
        }
        
        [self setStats];
        
        free(buffer);
        free(envelope);
    }
    
    return self;
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
