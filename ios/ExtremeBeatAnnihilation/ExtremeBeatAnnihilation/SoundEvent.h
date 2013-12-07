//
//  SoundEvent.h
//  ExtremeBeatAnnihilation
//
//  Created by Andrew Krepps on 11/2/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SoundEvent : NSObject

typedef enum { LEFT, RIGHT } Side;
typedef enum { JUMP, SLIDE } Type;

@property (readonly) uint sample;
@property (readonly) float freq;
@property (readonly) Side side;
@property (readonly) Type type;

-(id) initWithSample:(uint)s andFreq:(float)f;
-(void) setAttributesWithQ1:(float)q1Freq andMedian:(float)medianFreq andQ3:(float)q3Freq;

@end
