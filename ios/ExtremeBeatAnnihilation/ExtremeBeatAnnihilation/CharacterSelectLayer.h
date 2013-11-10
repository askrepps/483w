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

#define FOLDER_PATH @"../Resources/CharacterIcons"

@interface CharacterSelectLayer : CCLayer

// returns a CCScene that contains the MenuLayer as the only child
+(CCScene *)scene;

// a selector callback
void menuCloseCallback(NSObject* pSender);

// a selector callback for character selection
int menuCharacterCallback(NSObject* pSender);

//Count the characters in FOLDER_PATH
-(NSInteger)countCharacters;

// Load the characters into memory
void loadCharacters(const char* charDirectory);

// Arrange the characters into their proper location
void arrangeCharacterLocations(void);



@end
