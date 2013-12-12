//
//  Constants.h
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 11/2/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import <Foundation/Foundation.h>

#define kObstacleGap 44100
#define kVelocity 250
#define kLevelOffset 80
#define kRightCorrection 460
#define kFireY 100
#define kCoilY 155
#define kJumpHeight 100

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
+(void)setFirstScore:(NSInteger)score1 andSecondScore:(NSInteger)score2;
+(NSArray*)getScore;
+(void)setIsMenuMusicPlaying:(BOOL)playing;
+(BOOL)getIsMenuMusicPlaying;
+(void)clean;
@end
