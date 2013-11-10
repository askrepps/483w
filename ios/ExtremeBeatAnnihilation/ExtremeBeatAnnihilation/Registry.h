//
//  Constants.h
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 11/2/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Registry : NSObject
FOUNDATION_EXPORT NSString *const kVolume;
//FOUNDATION_EXPORT NSNumber *const kHighScore;

@property NSInteger kCharOne;
@property NSInteger kCharTwo;
@property BOOL kIsSinglePlayer;
@property (nonatomic, strong) NSURL *kMusicURL;
@end
