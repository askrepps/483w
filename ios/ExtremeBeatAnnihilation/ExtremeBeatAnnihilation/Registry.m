//
//  Constants.m
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 11/2/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "Registry.h"

@implementation Registry
NSString *const kVolume = @"Volume";

static NSInteger kCharOne = -1;
static NSInteger kCharTwo = -1;
static BOOL kIsSinglePlayer;
static NSString *kMusicName;
static NSURL *kMusicURL;
static NSInteger kScore = 0;

+(void)setChar:(NSInteger)index
{
    if(kCharOne == -1)
    {
        kCharOne = index;
    }
    else if(kCharTwo == -1)
    {
        kCharTwo = index;
    }
}

+(void)removeChar:(NSInteger)index
{
    if(kCharOne == index)
    {
        kCharOne = -1;
    }
    else if(kCharTwo == index)
    {
        kCharTwo = -1;
    }
}

+(NSInteger)getCharOne
{
    return kCharOne;
}

+(NSInteger)getCharTwo
{
    return kCharTwo;
}

+(BOOL)getIsSinglePlayer
{
    return kIsSinglePlayer;
}

+(void)setIsSinglePlayer:(BOOL)mode
{
    kIsSinglePlayer = mode;
}

+(NSString*)getMusicName;
{
    return kMusicName;
}

+(void)setMusicName:(NSString*)name
{
    kMusicName = name;
}

+(NSURL*)getMusicURL
{
    return kMusicURL;
}

+(void)setMusicURL:(NSURL*)URL
{
    kMusicURL = [[URL copy] retain];//[[NSURL alloc] initWithString:URL.absoluteString];
}

+(void)setScore:(NSInteger)score
{
    kScore = score;
}

+(NSInteger)getScore
{
    return kScore;
}

+(void)clean
{
    kCharOne = -1;
    kCharTwo = -1;
    kIsSinglePlayer = nil;
    kMusicName = nil;
    kMusicURL = nil;
    kScore = 0;
}
@end
