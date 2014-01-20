//
//  GameScene.h
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 11/14/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>
#import "cocos2d.h"
#import "LevelData.h"

@interface GameScene : CCScene <CCTouchAllAtOnceDelegate, AVAudioPlayerDelegate>

@property (strong, nonatomic) AVAudioPlayer *avPlayer;

-(id)initWithLevelData:(LevelData *)levelData;
-(void)pausePressed;
-(void)resumeGame;

@end
