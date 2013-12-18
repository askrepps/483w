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
-(id) initWithURL:(NSURL *)url
{    
    BOOL __block isSuccessful = NO;
    
    if (self = [super init])
    {
        if ([Registry getIsFileFromLibrary])
        {
            BOOL __block isWaiting = YES;
            AVURLAsset *songAsset = [AVURLAsset assetWithURL:url];
            AVAssetExportSession *exporter = [[AVAssetExportSession alloc] initWithAsset:songAsset presetName:AVAssetExportPresetAppleM4A];
            exporter.outputFileType = @"com.apple.m4a-audio";
            
            NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
            NSString *exportPath = [[paths objectAtIndex:0] stringByAppendingPathComponent:@"exported.m4a"];
            NSURL *exportUrl = [NSURL fileURLWithPath:exportPath];
            exporter.outputURL = exportUrl;
            [Registry setMusicURL:exportUrl];
            
            // delete previously exported song if it exists
            if ([[NSFileManager defaultManager] fileExistsAtPath:exportPath])
            {
                NSError *deleteErr = nil;
                [[NSFileManager defaultManager] removeItemAtPath:exportPath error:&deleteErr];
                if (deleteErr)
                {
                    NSLog (@"Can't delete %@: %@", exportPath, deleteErr);
                }
            }
            
            // export song
            [exporter exportAsynchronouslyWithCompletionHandler:^{
                int exportStatus = exporter.status;
                switch (exportStatus)
                {
                    case AVAssetExportSessionStatusFailed:
                    {
                        NSError *exportError = exporter.error;
                        NSLog (@"AVAssetExportSessionStatusFailed: %@", exportError);
                        isWaiting = NO;
                        isSuccessful = NO;
                        break;
                    }
                    case AVAssetExportSessionStatusCompleted:
                    {
                        NSLog (@"AVAssetExportSessionStatusCompleted");
                        isWaiting = NO;
                        isSuccessful = YES;
                        break;
                    }
                    case AVAssetExportSessionStatusUnknown: { NSLog (@"AVAssetExportSessionStatusUnknown"); break;}
                    case AVAssetExportSessionStatusExporting: { NSLog (@"AVAssetExportSessionStatusExporting"); break;}
                    case AVAssetExportSessionStatusCancelled: { NSLog (@"AVAssetExportSessionStatusCancelled"); break;}
                    case AVAssetExportSessionStatusWaiting: { NSLog (@"AVAssetExportSessionStatusWaiting"); break;}
                    default: { NSLog (@"didn't get export status"); break;}
                }
            }];
            
            // wait for export to finish
            while (isWaiting) ;
            
            if (isSuccessful)
            {
                [self readAudioDataFromURL:exportUrl];
            }
        }
        else
        {
            [self readAudioDataFromURL:url];
            isSuccessful = YES;
        }
    }
    
    if (isSuccessful)
    {
        return self;
    }
    else
    {
        return NULL;
    }
    
}

-(void) readAudioDataFromURL:(NSURL *)url
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
    
    FFTSetup fftSettings;
    UInt32 log2n;
    COMPLEX_SPLIT fftData;
    
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
    
    bufferSize = (UInt32)(_sampleRate / kBuffersPerSecond);
    buffer = malloc(sizeof(float) * bufferSize);
    envelope = malloc(sizeof(Peak) * ((nFrames / bufferSize) + 2));
    
    bufList.mNumberBuffers = 1;
    bufList.mBuffers[0].mNumberChannels = 1;
    bufList.mBuffers[0].mDataByteSize = bufferSize * sizeof(float);
    bufList.mBuffers[0].mData = buffer;
    
    log2n = log2f(bufferSize);
    fftSettings = vDSP_create_fftsetup(log2n, kFFTRadix2);
    fftData.realp = malloc(sizeof(float) * bufferSize/2);
    fftData.imagp = malloc(sizeof(float) * bufferSize/2);
    
    int count = 0;
    int offset;
    float maxAmp;
    int maxFreqBin;
    float freqPerBin = _sampleRate / bufferSize;
    float maxFreqBinValue;
    
    do
    {
        propertySize = bufferSize;
        status = ExtAudioFileRead(audioFile, &propertySize, &bufList);
        
        NSLog(@"Reading %d samples... status = %d", (unsigned int)propertySize, (int)status);
        
        maxAmp = 0;
        for (int i = 0; i < bufferSize; i++)
        {
            if (buffer[i] > maxAmp)
            {
                maxAmp = buffer[i];
                offset = i;
            }
        }
        
        vDSP_ctoz((COMPLEX *) buffer, 2, &fftData, 1, bufferSize/2);
        vDSP_fft_zrip(fftSettings, &fftData, 1, log2n, kFFTDirection_Forward);
        
        maxFreqBinValue = 0;
        maxFreqBin = 0;
        for (int i = 1; i < bufferSize/2; i++)
        {
            if (fftData.realp[i] > maxFreqBinValue)
            {
                maxFreqBinValue = fftData.realp[i];
                maxFreqBin = i;
            }
        }
        
        envelope[count].sample = count*bufferSize + offset;
        envelope[count].amp = maxAmp;
        envelope[count].freq = maxFreqBin * freqPerBin;
        count++;
    } while (propertySize > 0);
    
    NSLog(@"%d", count);
    
    _events = [[NSMutableArray alloc] init];
    
    if (count > 1 && envelope[0].amp > envelope[1].amp)
    {
        NSLog(@"s: %d  | amp: %f  | freq: %f", (unsigned int)envelope[0].sample, envelope[0].amp, envelope[0].freq);
        SoundEvent *event = [[SoundEvent alloc] initWithSample:envelope[0].sample andFreq:envelope[0].freq];
        [_events addObject:event];
        [event release];
    }
    
    for (int i = 1; i < count-1; i++)
    {
        if (envelope[i].amp > envelope[i+1].amp && envelope[i].amp > envelope[i-1].amp)
            //&& ([_events count] == 0 || envelope[i].sample - [[_events objectAtIndex:[_events count]-1] sample] >= kObstacleGap))
        {
            NSLog(@"s: %d  | amp: %f  | freq: %f", (unsigned int)envelope[i].sample, envelope[i].amp, envelope[i].freq);
            SoundEvent *event = [[SoundEvent alloc] initWithSample:envelope[i].sample andFreq:envelope[i].freq];
            [_events addObject:event];
            [event release];
        }
    }
    
    if (count > 1 && envelope[count-1].amp > envelope[count-2].amp)
        //&& ([_events count] == 0 || envelope[count-1].sample - [[_events objectAtIndex:[_events count]-1] sample] > kObstacleGap))
    {
        NSLog(@"s: %d  | amp: %f  | freq: %f", (unsigned int)envelope[count-1].sample, envelope[count-1].amp, envelope[count-1].freq);
        SoundEvent *event = [[SoundEvent alloc] initWithSample:envelope[count-1].sample andFreq:envelope[count-1].freq];
        [_events addObject:event];
        [event release];
    }
    
    [self setStats];
    
    for (SoundEvent *event in _events)
    {
        [event setAttributesWithQ1:_q1Freq andMedian:_medianFreq andQ3:_q3Freq];
    }
    
    free(buffer);
    free(envelope);
    free(fftData.realp);
    free(fftData.imagp);
    vDSP_destroy_fftsetup(fftSettings);
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
