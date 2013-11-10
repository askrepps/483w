//
//  CharacterSelectLayer.m
//  ExtremeBeatAnnihilation
//
//  Created by Russ Hogan on 11/2/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "CharacterSelectLayer.h"


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
        
        
        CCMenuItemImage *character1 = [CCMenuItemImage itemWithNormalImage:@"char1.png" selectedImage:@"char1.png" target:self selector:@selector(Character1Pressed:)];
        character1.position = ccp(size.width/4 - 25, size.height/2);
        
        CCMenuItemImage *character2 = [CCMenuItemImage itemWithNormalImage:@"char2.png" selectedImage:@"char2.png" target:self selector:@selector(Character2Pressed:)];
        character2.position = ccp(size.width/2 - 25, size.height/2);
        
        CCMenuItemImage *character3 = [CCMenuItemImage itemWithNormalImage:@"char3.png" selectedImage:@"char3.png" target:self selector:@selector(Character3Pressed:)];
        character3.position = ccp(size.width/4 * 3 - 25, size.height/2);
        
        CCMenuItemImage *character4 = [CCMenuItemImage itemWithNormalImage:@"char4.png" selectedImage:@"char4.png" target:self selector:@selector(Character4Pressed:)];
        character4.position = ccp(size.width - 25, size.height/2);
        
        CCMenuItemFont *continueButton = [CCMenuItemFont itemWithString:@"Continue" target:self selector:@selector(ContinuePressed:)];
        continueButton.position = ccp(size.width/2, 64);
        
        CCMenuItemFont *back = [CCMenuItemFont itemWithString:@"Back" target:self selector:@selector(backPressed:)];
        back.position = ccp(size.width/2, 32);
        
        CCMenu *characterMenu = [CCMenu menuWithItems:character1, character2, character3, character4, back, continueButton, nil];
        characterMenu.position = CGPointZero;
       
        [self addChild:characterMenu];

        [[CCDirector sharedDirector] setDisplayStats:NO];
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

-(void)Character1Pressed:(id)sender
{
    NSLog(@"Character 1 pressed");
}

-(void)Character2Pressed:(id)sender
{
    NSLog(@"Character 2 pressed");
}

-(void)Character3Pressed:(id)sender
{
    NSLog(@"Character 3 pressed");
}

-(void)Character4Pressed:(id)sender
{
    NSLog(@"Character 4 pressed");
}

-(void)ContinuePressed:(id)sender
{
    NSLog(@"Continue pressed");
}


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
}



@end
