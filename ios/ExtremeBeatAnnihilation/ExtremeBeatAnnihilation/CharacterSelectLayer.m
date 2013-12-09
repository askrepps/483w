//
//  CharacterSelectLayer.m
//  ExtremeBeatAnnihilation
//
//  Created by Russ Hogan on 11/2/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "CharacterSelectLayer.h"
#import "MenuLayer.h"
#import "MusicSelectLayer.h"
#import "Registry.h"
#import "SimpleAudioEngine.h"

@interface CharacterSelectLayer ()

@property (nonatomic, strong) NSMutableArray* characters;
@property (nonatomic, strong) NSMutableArray* charSelections;
@property NSInteger numSelected;

@end

@implementation CharacterSelectLayer

+(CCScene *)scene
{
	CCScene *scene = [CCScene node];
	
	CharacterSelectLayer *layer = [CharacterSelectLayer node];
	
	[scene addChild: layer];
	
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
        
        // Char 1
        
        CCMenuItemImage *character1Unselected = [CCMenuItemImage itemWithNormalImage:@"red_icon.png" selectedImage:@"red_icon_selected.png" target:self selector:@selector(CharacterPressed:)];
        
        CCMenuItemImage *character1Selected = [CCMenuItemImage itemWithNormalImage:@"red_icon_selected.png" selectedImage:@"red_icon.png" target:self selector:@selector(CharacterPressed:)];
        
        [_charSelections addObject:[NSNumber numberWithBool:NO]];
        
        CCMenuItemToggle *character1 = [CCMenuItemToggle itemWithTarget:self selector:@selector(CharacterPressed:) items:character1Unselected, character1Selected, nil];
        [_characters addObject:character1];
        
        // Char 2
        
        CCMenuItemImage *character2Unselected = [CCMenuItemImage itemWithNormalImage:@"blue_icon.png" selectedImage:@"blue_icon_selected.png" target:self selector:@selector(CharacterPressed:)];
        
        CCMenuItemImage *character2Selected = [CCMenuItemImage itemWithNormalImage:@"blue_icon_selected.png" selectedImage:@"blue_icon.png" target:self selector:@selector(CharacterPressed:)];
        
        [_charSelections addObject:[NSNumber numberWithBool:NO]];
        
        CCMenuItemToggle *character2 = [CCMenuItemToggle itemWithTarget:self selector:@selector(CharacterPressed:) items:character2Unselected, character2Selected, nil];
        [_characters addObject:character2];
        
        // Char 3
        
        CCMenuItemImage *character3Unselected = [CCMenuItemImage itemWithNormalImage:@"green_icon.png" selectedImage:@"green_icon_selected.png" target:self selector:@selector(CharacterPressed:)];
        
        CCMenuItemImage *character3Selected = [CCMenuItemImage itemWithNormalImage:@"green_icon_selected.png" selectedImage:@"green_icon.png"  target:self selector:@selector(CharacterPressed:)];
        
        [_charSelections addObject:[NSNumber numberWithBool:NO]];
        
        CCMenuItemToggle *character3 = [CCMenuItemToggle itemWithTarget:self selector:@selector(CharacterPressed:) items:character3Unselected, character3Selected, nil];
        [_characters addObject:character3];
        
        CCMenuItemFont *continueButton = [CCMenuItemFont itemWithString:@"Continue" target:self selector:@selector(ContinuePressed:)];
        continueButton.position = ccp(size.width/2, 68);
        
        CCMenuItemFont *back = [CCMenuItemFont itemWithString:@"Back" target:self selector:@selector(backPressed:)];
        back.position = ccp(size.width/2, 32);
                
        // Check if any characters already set
        if([Registry getCharOne] != -1 && [Registry getCharTwo] != -1)
        {
            NSInteger indexOne = [Registry getCharOne];
            NSInteger indexTwo = [Registry getCharTwo];
            
            CCMenuItemToggle *selectedOne = [self.characters objectAtIndex:indexOne];
            CCMenuItemToggle *selectedTwo = [self.characters objectAtIndex:indexTwo];
            
            [selectedOne setSelectedIndex:1];
            [selectedTwo setSelectedIndex:1];
            self.numSelected = 2;
            [self toggleSelections];
        }
        
        CCMenu *characterMenu = [CCMenu menuWithItems:character1, character2, character3, nil];
        characterMenu.position = ccp(size.width/2, size.height/2);
        [characterMenu alignItemsHorizontallyWithPadding:size.width/3];
        
        CCMenu *navMenu = [CCMenu menuWithItems:continueButton, back, nil];
        navMenu.position = CGPointZero;
        
        [self addChild:characterMenu z:0];
        [self addChild:navMenu];
	}
    
	return self;
}

-(void)dealloc
{
	[super dealloc];
}

-(void)backPressed:(id)sender
{
    [[SimpleAudioEngine sharedEngine] playEffect:@"back.wav"];
    [Registry clean];
    [[CCDirector sharedDirector] replaceScene:[MenuLayer scene]];
}

-(void)CharacterPressed:(id)sender
{
    CCMenuItemToggle *source = (CCMenuItemToggle*) sender;
    
    NSInteger index = [self.characters indexOfObject:source];
    if (source.selectedIndex == 0)
    {
        [[SimpleAudioEngine sharedEngine] playEffect:@"back.wav"];
        [self.charSelections replaceObjectAtIndex:index withObject:[NSNumber numberWithBool:NO]];
        self.numSelected--;
        [Registry removeChar:index];
    }
    else
    {
        [[SimpleAudioEngine sharedEngine] playEffect:@"select.wav"];
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
        [[SimpleAudioEngine sharedEngine] playEffect:@"select.wav"];
        [[CCDirector sharedDirector] replaceScene:[MusicSelectLayer scene]];
    }
    else
    {
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Warning" message:@"Must select two characters." delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
        [alert show];
    }
}

@end