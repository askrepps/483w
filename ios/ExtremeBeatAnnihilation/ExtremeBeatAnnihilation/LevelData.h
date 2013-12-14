//
//  LevelData.h
//  ExtremeBeatAnnihilation
//
//  Created by ANDREW STEPHEN KREPPS on 10/22/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import <AudioToolbox/AudioToolbox.h>
#import <Accelerate/Accelerate.h>
#import "SoundEvent.h"

@interface LevelData : NSObject

typedef struct
{
    UInt32 sample;
    float amp;
    float freq;
} Peak;

@property (readonly) uint numSamples;
@property (readonly) float q1Freq;
@property (readonly) float medianFreq;
@property (readonly) float q3Freq;
@property (retain, nonatomic, readonly) NSMutableArray *events;
@property (readonly) NSInteger sampleRate;

-(id) initDefault;
-(id) initWithAudioFileURL:(NSURL *)url;
-(id) initWithAudioFilePath:(NSString *)filePath;

@end
