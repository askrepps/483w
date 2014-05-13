//
//  GameOverLayer.m
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 11/30/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "GameOverLayer.h"
#import "MenuLayer.h"
#import "Registry.h"

@implementation GameOverLayer

+(CCScene *)scene
{
	CCScene *scene = [CCScene node];

	GameOverLayer *gameOver = [GameOverLayer node];
	
	[scene addChild:gameOver];
	
	return scene;
}

-(id)init
{
	if((self=[super init]))
    {
        CGSize size = [[CCDirector sharedDirector] winSize];
        
        CCLabelTTF *overLabel = [CCLabelTTF labelWithString:@"Game Over" fontName:@"Marker Felt" fontSize:32];
        overLabel.position = ccp(size.width/2, size.height - 32);
        
        CCLabelTTF *titleLabel = [CCLabelTTF labelWithString:[Registry getMusicName] fontName:@"Marker Felt" fontSize:32];
        titleLabel.position = ccp(size.width/2, size.height - 64);
        
        CCLabelTTF *scoreLabel;
        
        if([Registry getIsSinglePlayer])
        {
            NSNumber *score = [Registry getScore][0];
            scoreLabel = [CCLabelTTF labelWithString:[NSString stringWithFormat:@"Final Score: %d", [score intValue]] fontName:@"Marker Felt" fontSize:32];
        }
        else
        {
            NSNumber *score1 = [Registry getScore][0];
            NSNumber *score2 = [Registry getScore][1];
            scoreLabel = [CCLabelTTF labelWithString:[NSString stringWithFormat:@"P1: %d   P2: %d", [score1 intValue], [score2 intValue]] fontName:@"Marker Felt" fontSize:32];
        }
        scoreLabel.position = ccp(size.width/2, size.height/2);
        
        CCMenuItemFont *playAgain = [CCMenuItemFont itemWithString:@"Play Again" target:self selector:@selector(againPressed)];
        playAgain.position = ccp(size.width/2, 32);
        
        CCMenu *menu = [CCMenu menuWithItems:playAgain, nil];
        menu.position = CGPointZero;
        
        [self addChild:overLabel];
        [self addChild:titleLabel];
        [self addChild:scoreLabel];
        [self addChild:menu];
    }
    
	return self;
}

-(void)dealloc
{
    [super dealloc];
}

-(void)againPressed
{
    // Clear the Registry and return to the main menu
    [Registry clean];
    
    [[CCDirector sharedDirector] replaceScene:[MenuLayer scene]];
}

@end
