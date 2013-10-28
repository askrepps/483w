//
//  HelloWorldLayer.m
//  ExtremeBeatAnnihilation
//
//  Created by ANDREW STEPHEN KREPPS on 9/11/13.
//  Copyright Crash Course Gaming 2013. All rights reserved.
//

// Import the interfaces
#import "MenuLayer.h"
#import "AppDelegate.h"

#pragma mark - MenuLayer

@implementation MenuLayer

// Helper class method that creates a Scene with the MenuLayer as the only child.
+(CCScene *)scene
{
	// 'scene' is an autorelease object.
	CCScene *scene = [CCScene node];
	
	// 'layer' is an autorelease object.
	MenuLayer *layer = [MenuLayer node];
	
	// add layer as a child to scene
	[scene addChild: layer];
	
	// return the scene
	return scene;
}

-(id)init
{
	if((self=[super init]))
    {
		CCLabelTTF *label = [CCLabelTTF labelWithString:@"Extreme Beat Annihilation" fontName:@"Marker Felt" fontSize:32];
        
		CGSize size = [[CCDirector sharedDirector] winSize];
        label.position =  ccp(size.width/2, size.height - 32);
        [self addChild:label];

//        CCMenuItem *starMenuItem = [CCMenuItemImage
//                                    itemFromNormalImage:@"ButtonStar.png" selectedImage:@"ButtonStarSel.png"
//                                    target:self selector:@selector(starButtonTapped:)];
//        starMenuItem.position = ccp(60, 60);

        CCMenuItemFont *startGame = [CCMenuItemFont itemWithString:@"Start Game" target:self selector:@selector(startPressed:)];
        startGame.position = ccp(size.width/2, size.height/2);
        CCMenuItemFont *options = [CCMenuItemFont itemWithString:@"Options" target:self selector:@selector(optionsPressed:)];
        options.position = ccp(size.width/2, size.height/2 - 32);
        
        CCMenu *startMenu = [CCMenu menuWithItems:startGame, options, nil];
        startMenu.position = CGPointZero;
        [self addChild:startMenu];
        
        [[CCDirector sharedDirector] setDisplayStats:NO];
	}
    
	return self;
}

-(void)dealloc
{
	[super dealloc];
}

-(void)startPressed:(id)sender
{
    NSLog(@"start pressed");
}

-(void)optionsPressed:(id)sender
{
    NSLog(@"options pressed");
}

#pragma mark GameKit delegate

//-(void) achievementViewControllerDidFinish:(GKAchievementViewController *)viewController
//{
//	AppController *app = (AppController*) [[UIApplication sharedApplication] delegate];
//	[[app navController] dismissViewControllerAnimated:YES completion:nil];
//}
//
//-(void) leaderboardViewControllerDidFinish:(GKLeaderboardViewController *)viewController
//{
//	AppController *app = (AppController*) [[UIApplication sharedApplication] delegate];
//	[[app navController] dismissViewControllerAnimated:YES completion:nil];
//}
@end
