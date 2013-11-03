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

@property uint numSamples;
@property float q1Freq;
@property float medianFreq;
@property float q3Freq;
@property NSMutableArray *events;

-(id) initDefault;
-(id) initWithAudioFile:(NSString *)filepath;

@end
