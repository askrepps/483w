//
//  LevelData.h
//  ExtremeBeatAnnihilation
//
//  Created by ANDREW STEPHEN KREPPS on 10/22/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SoundEvent.h"

@interface LevelData : NSObject

@property (readonly) uint numSamples;
@property (readonly) float q1Freq;
@property (readonly) float medianFreq;
@property (readonly) float q3Freq;
@property (retain, nonatomic, readonly) NSMutableArray *events;

-(id) initDefault;
-(id) initWithAudioFile:(NSString *)filepath;

@end
