//
//  Constants.h
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 11/2/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import <Foundation/Foundation.h>

#define kBuffersPerSecond 4
#define kObstacleGap 40000
#define kVelocity 250
#define kLevelOffset 110
#define kRightCorrection 460
#define kFireY 100
#define kCoilY 152
#define kJumpHeight 100

@interface Registry : NSObject
FOUNDATION_EXPORT NSString *const kMusic;
FOUNDATION_EXPORT NSString *const kSFX;
FOUNDATION_EXPORT NSString *const GameReady;

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
+(void)setFirstScore:(NSInteger)score1 andSecondScore:(NSInteger)score2;
+(NSArray*)getScore;
+(void)setIsMenuMusicPlaying:(BOOL)playing;
+(BOOL)getIsMenuMusicPlaying;
+(void)setIsFileFromLibrary:(BOOL)fromLibrary;
+(BOOL)getIsFileFromLibrary;
+(void)clean;
@end
