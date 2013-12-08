//
//  Constants.h
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 11/2/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import <Foundation/Foundation.h>

#define kVelocity 250
#define kLevelOffset 100
#define kFireY 100
#define kCoilY 200
#define kJumpHeight 100

#define kBufferSize 44100

@interface Registry : NSObject
FOUNDATION_EXPORT NSString *const kVolume;
//FOUNDATION_EXPORT NSNumber *const kHighScore;

+(void)setChar:(NSInteger)index;
+(void)removeChar:(NSInteger)index;
+(NSInteger)getCharOne;
+(NSInteger)getCharTwo;
+(BOOL)getIsSinglePlayer;
+(void)setIsSinglePlayer:(BOOL)mode;
+(NSString*)getMusicName;
+(void)setMusicName:(NSString*)name;
+(NSURL*)getMusicURL;
+(void)setMusicURL:(NSURL*)URL;
+(void)setScore:(NSInteger)score;
+(NSInteger)getScore;
+(void)clean;
@end
