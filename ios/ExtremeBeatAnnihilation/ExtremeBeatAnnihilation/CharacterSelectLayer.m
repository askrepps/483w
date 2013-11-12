//
//  CharacterSelectLayer.m
//  ExtremeBeatAnnihilation
//
//  Created by Russ Hogan on 11/2/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "CharacterSelectLayer.h"
#import "MusicSelectLayer.h"
#import "Registry.h"

@interface CharacterSelectLayer ()

@property (nonatomic, strong) NSMutableArray* characters;
@property (nonatomic, strong) NSMutableArray* charSelections;
@property (nonatomic, strong) CCMenu *characterMenu;
@property (nonatomic, strong) CCMenu *navMenu;
@property (nonatomic, strong) CCMenu *dummyMenu;
@property NSInteger numSelected;

@end

@implementation CharacterSelectLayer

// Helper class method that creates a Scene with the MenuLayer as the only child.
+(CCScene *)scene
{
	// 'scene' is an autorelease object.
	CCScene *scene = [CCScene node];
	
	// 'layer' is an autorelease object.
	CharacterSelectLayer *layer = [CharacterSelectLayer node];
	
	// add layer as a child to scene
	[scene addChild: layer];
	
	// return the scene
	return scene;
}

-(id)init
{
	if((self=[super init]))
    {
		CCLabelTTF *label = [CCLabelTTF labelWithString:@"Choose Your Characters" fontName:@"Marker Felt" fontSize:32];
        
        _numSelected = 0;
        
		CGSize size = [[CCDirector sharedDirector] winSize];
        label.position =  ccp(size.width/2, size.height - 32);
        [self addChild:label];
        
        self.characters = [[NSMutableArray alloc] init];
        self.charSelections = [[NSMutableArray alloc] init];
        

        CCMenuItemImage *character1Unselected = [CCMenuItemImage itemWithNormalImage:@"char1.png" selectedImage:@"char1selected.png" target:self selector:@selector(CharacterPressed:)];
        
        CCMenuItemImage *character1Selected = [CCMenuItemImage itemWithNormalImage:@"char1selected.png" selectedImage:@"char1.png" target:self selector:@selector(CharacterPressed:)];
        
        [_charSelections addObject:[NSNumber numberWithBool:NO]];
        
        CCMenuItemToggle *character1 = [CCMenuItemToggle itemWithTarget:self selector:@selector(CharacterPressed:) items:character1Unselected, character1Selected, nil];
        [_characters addObject:character1];
        
        CCMenuItemImage *character2Unselected = [CCMenuItemImage itemWithNormalImage:@"char2.png" selectedImage:@"char2selected.png" target:self selector:@selector(CharacterPressed:)];
        
        CCMenuItemImage *character2Selected = [CCMenuItemImage itemWithNormalImage:@"char2selected.png" selectedImage:@"char2.png" target:self selector:@selector(CharacterPressed:)];
        
        [_charSelections addObject:[NSNumber numberWithBool:NO]];
        
        CCMenuItemToggle *character2 = [CCMenuItemToggle itemWithTarget:self selector:@selector(CharacterPressed:) items:character2Unselected, character2Selected, nil];
        [_characters addObject:character2];
        
        // Char 3
        
        CCMenuItemImage *character3Unselected = [CCMenuItemImage itemWithNormalImage:@"char3.png" selectedImage:@"char3selected.png" target:self selector:@selector(CharacterPressed:)];
        
        CCMenuItemImage *character3Selected = [CCMenuItemImage itemWithNormalImage:@"char3selected.png" selectedImage:@"char3.png"  target:self selector:@selector(CharacterPressed:)];
        
        [_charSelections addObject:[NSNumber numberWithBool:NO]];
        
        CCMenuItemToggle *character3 = [CCMenuItemToggle itemWithTarget:self selector:@selector(CharacterPressed:) items:character3Unselected, character3Selected, nil];
        [_characters addObject:character3];
//
//        CCMenuItemImage *character4 = [CCMenuItemImage itemWithNormalImage:@"char4.png" selectedImage:@"char4selected.png" target:self selector:@selector(CharacterPressed:)];
//        [_unselectedChars addObject:character4];


//
//        CCMenuItemImage *character4Selected = [CCMenuItemImage itemWithNormalImage:@"char4selected.png" selectedImage:@"char4.png" target:self selector:@selector(CharacterPressed:)];
//        [_selectedChars addObject:character4Selected];
        
        CCMenuItemFont *continueButton = [CCMenuItemFont itemWithString:@"Continue" target:self selector:@selector(ContinuePressed:)];
        continueButton.position = ccp(size.width/2, 64);
        
        CCMenuItemFont *back = [CCMenuItemFont itemWithString:@"Back" target:self selector:@selector(backPressed:)];
        back.position = ccp(size.width/2, 32);
        
//        self.characterMenu = [CCMenu menuWithItems:character1, character2, character3, character4, nil];
        self.characterMenu = [CCMenu menuWithItems:character1, character2, character3, nil];
        self.characterMenu.position = ccp(size.width/2, size.height/2);
        [self.characterMenu alignItemsHorizontallyWithPadding:size.width/3];
        
        self.navMenu = [CCMenu menuWithItems:continueButton, back, nil];
        self.navMenu.position = CGPointZero;
        
        [self addChild:self.characterMenu z:0 tag:CHARACTER_MENU];
        [self addChild:self.navMenu];
	}
    
	return self;
}

-(void)dealloc
{
	[super dealloc];
}

-(void)backPressed:(id)sender
{
    [[CCDirector sharedDirector] replaceScene:[ModeSelectLayer scene]];
}

-(void)CharacterPressed:(id)sender
{
    CCMenuItemToggle *source = (CCMenuItemToggle*) sender;
        
    NSInteger index = [self.characters indexOfObject:source];
    if (source.selectedIndex == 0)
    {
        [self.charSelections replaceObjectAtIndex:index withObject:[NSNumber numberWithBool:NO]];
        self.numSelected--;
        [Registry removeChar:index];
    }
    else
    {
        [self.charSelections replaceObjectAtIndex:index withObject:[NSNumber numberWithBool:YES]];
        self.numSelected++;
        [Registry setChar:index];
    }
    
    [self toggleSelections];
}

-(void)toggleSelections
{
    for(CCMenuItemToggle *t in self.characters)
    {
        if(self.numSelected == 2 && t.isEnabled == YES && t.selectedIndex == 0)
        {
            t.isEnabled = NO;
        }
        else
        {
            t.isEnabled = YES;
        }
    }
}

-(void)ContinuePressed:(id)sender
{
    if([Registry getCharOne] != -1 && [Registry getCharTwo] != -1)
    {
        [[CCDirector sharedDirector] pushScene:[MusicSelectLayer scene]];
    }
    else
    {
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Warning" message:@"Must select two characters." delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
        [alert show];
    }
}

/*
 -(NSInteger)countCharacters  //unused function
 {
 NSMutableArray *files = [[NSMutableArray alloc] init];
 NSArray *itemsInFolder = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:FOLDER_PATH error:NULL];
 
 NSString *itemPath;
 BOOL isDirectory;
 for (NSString *item in itemsInFolder){
 itemPath = [NSString stringWithFormat:@"%@/%@", FOLDER_PATH, item];
 [[NSFileManager defaultManager] fileExistsAtPath:item isDirectory:&isDirectory];
 if (!isDirectory) {
 [files addObject:item];
 }
 }
 
 return [files count];
 }*/



@end
