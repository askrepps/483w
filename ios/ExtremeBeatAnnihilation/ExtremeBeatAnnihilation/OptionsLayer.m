//
//  OptionsLayer.m
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 10/30/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "OptionsLayer.h"
#import "CCControlExtension.h"

@implementation OptionsLayer

+(CCScene *)scene
{
	CCScene *scene = [CCScene node];
	OptionsLayer *layer = [OptionsLayer node];
	[scene addChild: layer];

	return scene;
}

-(id)init
{
	if((self=[super init]))
    {
		CCLabelTTF *label = [CCLabelTTF labelWithString:@"Options" fontName:@"Marker Felt" fontSize:32];
		CGSize size = [[CCDirector sharedDirector] winSize];
        label.position = ccp(size.width/2, size.height - 32);
        [self addChild:label];
        
        // Create the slider
        
        CCControlSlider *slider = [CCControlSlider sliderWithBackgroundFile:@"sliderTrack.png" progressFile:@"sliderProgress.png" thumbFile:@"sliderThumb.png"];
        slider.minimumValue = 0.0f; // Sets the min value of range
        slider.maximumValue = 1.0f; // Sets the max value of range
        slider.position = ccp(size.width/2, size.height/2);
        
        // When the value of the slider will change, the given selector will be call
        [slider addTarget:self action:@selector(valueChanged:) forControlEvents:CCControlEventValueChanged];
        
        [self addChild:slider];
        
        
        //        CCMenuItem *starMenuItem = [CCMenuItemImage
        //                                    itemFromNormalImage:@"ButtonStar.png" selectedImage:@"ButtonStarSel.png"
        //                                    target:self selector:@selector(starButtonTapped:)];
        //        starMenuItem.position = ccp(60, 60);
        
//        CCMenuItemFont *startGame = [CCMenuItemFont itemWithString:@"Start Game" target:self selector:@selector(startPressed:)];
//        startGame.position = ccp(size.width/2, size.height/2);
//        CCMenuItemFont *options = [CCMenuItemFont itemWithString:@"Options" target:self selector:@selector(optionsPressed:)];
//        options.position = ccp(size.width/2, size.height/2 - 32);
//        
//        CCMenu *startMenu = [CCMenu menuWithItems:startGame, options, nil];
//        startMenu.position = CGPointZero;
//        [self addChild:startMenu];
        
        
	}
    
	return self;
}

-(void)dealloc
{
	[super dealloc];
}

-(void)valueChanged:(id)sender
{
    NSLog(@"Slider moved");
}

@end
