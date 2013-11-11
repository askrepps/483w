//
//  CharacterSelectLayer.m
//  ExtremeBeatAnnihilation
//
//  Created by Russ Hogan on 11/2/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "CharacterSelectLayer.h"

@interface CharacterSelectLayer ()

@property (nonatomic, strong)  NSMutableArray* unselectedChars;
@property (nonatomic, strong)  NSMutableArray* selectedChars;
@property (nonatomic, strong)  CCMenuItemFont *continueButton;
@property (nonatomic, strong)  CCMenuItemFont *back;
@property (nonatomic, strong)  CCMenu *characterMenu;
@property (nonatomic, strong)  CCMenu *navMenu;
@property (nonatomic, strong)  CCMenu *dummyMenu;

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
        
		CGSize size = [[CCDirector sharedDirector] winSize];
        label.position =  ccp(size.width/2, size.height - 32);
        [self addChild:label];
        
        self.unselectedChars = [[NSMutableArray alloc] init];
        self.selectedChars = [[NSMutableArray alloc] init];
        
        CCMenuItemImage *character1 = [CCMenuItemImage itemWithNormalImage:@"char1.png" selectedImage:@"char1selected.png" target:self selector:@selector(CharacterPressed:)];
        [_unselectedChars addObject:character1];
        
        CCMenuItemImage *character2 = [CCMenuItemImage itemWithNormalImage:@"char2.png" selectedImage:@"char2selected.png" target:self selector:@selector(CharacterPressed:)];
        [_unselectedChars addObject:character2];
        
        CCMenuItemImage *character3 = [CCMenuItemImage itemWithNormalImage:@"char3.png" selectedImage:@"char3selected.png" target:self selector:@selector(CharacterPressed:)];
        [_unselectedChars addObject:character3];
        
        CCMenuItemImage *character4 = [CCMenuItemImage itemWithNormalImage:@"char4.png" selectedImage:@"char4selected.png" target:self selector:@selector(CharacterPressed:)];
        [_unselectedChars addObject:character4];
        
        CCMenuItemImage *character1Selected = [CCMenuItemImage itemWithNormalImage:@"char1selected.png" selectedImage:@"char1.png" target:self selector:@selector(CharacterPressed:)];
        [_selectedChars addObject:character1Selected];
        
        CCMenuItemImage *character2Selected = [CCMenuItemImage itemWithNormalImage:@"char2selected.png" selectedImage:@"char2.png" target:self selector:@selector(CharacterPressed:)];
        [_selectedChars addObject:character2Selected];
        
        CCMenuItemImage *character3Selected = [CCMenuItemImage itemWithNormalImage:@"char3selected.png" selectedImage:@"char3.png"  target:self selector:@selector(CharacterPressed:)];
        [_selectedChars addObject:character3Selected];
        
        CCMenuItemImage *character4Selected = [CCMenuItemImage itemWithNormalImage:@"char4selected.png" selectedImage:@"char4.png" target:self selector:@selector(CharacterPressed:)];
        [_selectedChars addObject:character4Selected];
        
        self.continueButton = [CCMenuItemFont itemWithString:@"Continue" target:self selector:@selector(ContinuePressed:)];
        self.continueButton.position = ccp(size.width/2, 64);
        
        self.back = [CCMenuItemFont itemWithString:@"Back" target:self selector:@selector(backPressed:)];
        self.back.position = ccp(size.width/2, 32);
        
        self.characterMenu = [CCMenu menuWithItems:character1, character2, character3, character4, nil];
        self.characterMenu.position = CGPointZero;
        [self.characterMenu alignItemsHorizontallyWithPadding:size.width/4];
        
        self.navMenu = [CCMenu menuWithItems:self.continueButton, self.back, nil];
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
    NSLog(@"Character Button pressed");
    CCMenuItemImage *source = (CCMenuItemImage*) sender;
    [self.characterMenu removeChild:sender];
    
    NSInteger index;
    if ([self.unselectedChars containsObject:source])
    {
        index = [self.unselectedChars indexOfObject:source];
        [self.characterMenu addChild:[self.selectedChars objectAtIndex:index] z:index];
    }
    else
    {
        index = [self.selectedChars indexOfObject:source];
        [self.characterMenu addChild:[self.unselectedChars objectAtIndex:index] z:index];
    }
    
    
    
}

-(void)ContinuePressed:(id)sender
{
    NSLog(@"Continue pressed");
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
