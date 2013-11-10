//
//  CharacterSelectLayer.m
//  ExtremeBeatAnnihilation
//
//  Created by 483W on 11/2/13.
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
        
        NSInteger numCharacters = [self countCharacters];
        
        CCMenuItemImage *character1 = [CCMenuItemImage itemWithNormalImage:@"char1.png" selectedImage:@"char1.png" target:self selector:@selector(Character1Pressed:)];
        character1.position = ccp(size.width/2, size.height/2);
        
        CCMenuItemImage *character2 = [CCMenuItemImage itemWithNormalImage:@"char2.png" selectedImage:@"char2.png" target:self selector:@selector(Character2Pressed:)];
        character2.position = ccp(size.width/2, size.height/2);
        
        CCMenuItemImage *character3 = [CCMenuItemImage itemWithNormalImage:@"char3.png" selectedImage:@"char3.png" target:self selector:@selector(Character3Pressed:)];
        character3.position = ccp(size.width/2, size.height/2);
        
        CCMenuItemImage *character4 = [CCMenuItemImage itemWithNormalImage:@"char4.png" selectedImage:@"char4.png" target:self selector:@selector(Character4Pressed:)];
        character4.position = ccp(size.width/2, size.height/2);
        
        CCMenu *characterMenu = [CCMenu menuWithItems:character1, character2, character3, character4, nil];
        characterMenu.position = CGPointZero;
        
        CCMenuItemFont *back = [CCMenuItemFont itemWithString:@"Back" target:self selector:@selector(backPressed:)];
        back.position = ccp(size.width/2, size.height/2 - 32);
        [self addChild:characterMenu];
        [self addChild:back];
        
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
    NSLog(@"back pressed");
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



-(NSInteger)countCharacters
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
