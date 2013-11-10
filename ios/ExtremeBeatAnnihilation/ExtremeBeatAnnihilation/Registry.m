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

static NSInteger kCharOne;
static NSInteger kCharTwo;
static BOOL kIsSinglePlayer;
static NSURL *kMusicURL;

+(NSInteger)getCharOne
{
    return kCharOne;
}

+(void)setCharOne:(NSInteger)num
{
    kCharOne = num;
}

+(NSInteger)getCharTwo
{
    return kCharTwo;
}

+(void)setCharTwo:(NSInteger)num
{
    kCharTwo = num;
}

+(BOOL)getIsSinglePlayer
{
    return kIsSinglePlayer;
}

+(void)setIsSinglePlayer:(BOOL)mode
{
    kIsSinglePlayer = mode;
}

+(NSURL*)getMusicURL
{
    return kMusicURL;
}

+(void)setMusicURL:(NSURL*)URL
{
    kMusicURL = URL;
}
@end
