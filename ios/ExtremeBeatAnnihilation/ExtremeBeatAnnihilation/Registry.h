//
//  Constants.h
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 11/2/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import <Foundation/Foundation.h>

#define kVelocity 100

@interface Registry : NSObject
FOUNDATION_EXPORT NSString *const kVolume;
//FOUNDATION_EXPORT NSNumber *const kHighScore;

+(void)setChar:(NSInteger)index;
+(void)removeChar:(NSInteger)index;
+(NSInteger)getCharOne;
+(NSInteger)getCharTwo;
+(BOOL)getIsSinglePlayer;
+(void)setIsSinglePlayer:(BOOL)mode;
+(NSURL*)getMusicURL;
+(void)setMusicURL:(NSURL*)URL;
@end
