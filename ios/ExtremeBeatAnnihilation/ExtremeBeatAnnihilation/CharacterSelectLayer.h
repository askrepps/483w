//
//  CharacterSelectLayer.h
//  ExtremeBeatAnnihilation
//
//  Created by Russ Hogan on 11/2/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//


#import <GameKit/GameKit.h>
#import "cocos2d.h"
#import "MenuLayer.h"
#import "AppDelegate.h"
#import "BackgroundLayer.h"
#import "OptionsLayer.h"
#import "ModeSelectLayer.h"

#define CHARACTER_MENU 00
#define CHAR_1 01
#define CHAR_2 02
#define CHAR_3 03
#define CHAR_4 04
#define CHAR_1_SELECTED 11
#define CHAR_2_SELECTED 12
#define CHAR_3_SELECTED 13
#define CHAR_4_SELECTED 14

@interface CharacterSelectLayer : CCLayer

+(CCScene *)scene;

//// a selector callback
//void menuCloseCallback(NSObject* pSender);
//
//// a selector callback for character selection
//int menuCharacterCallback(NSObject* pSender);

//Count the characters in FOLDER_PATH
//-(NSInteger)countCharacters;

//// Load the characters into memory
//void loadCharacters(const char* charDirectory);
//
//// Arrange the characters into their proper location
//void arrangeCharacterLocations(void);

@end
