//
//  OptionsLayer.m
//  ExtremeBeatAnnihilation
//
//  Created by Robert William Carrier on 10/30/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "SettingsLayer.h"
#import "CCControlExtension.h"
#import "SimpleAudioEngine.h"
#import "MenuLayer.h"
#import "Registry.h"

@interface SettingsLayer ()
@property (nonatomic, strong) CCLabelTTF *displayValueLabel;
@property (nonatomic, strong) CCControlSlider *slider;

-(void)valueChanged:(CCControlSlider*)sender;

@end

@implementation SettingsLayer

+(CCScene *)scene
{
	CCScene *scene = [CCScene node];
	SettingsLayer *layer = [SettingsLayer node];
	[scene addChild: layer];

	return scene;
}

-(id)init
{
	if((self=[super init]))
    {
        CGSize size = [[CCDirector sharedDirector] winSize];
        
		CCLabelTTF *optionsLabel = [CCLabelTTF labelWithString:@"Options" fontName:@"Marker Felt" fontSize:32];
        optionsLabel.position = ccp(size.width/2, size.height - 32);
        [self addChild:optionsLabel];
        
        // Create the slider
        _slider = [CCControlSlider sliderWithBackgroundFile:@"sliderTrack.png" progressFile:@"sliderProgress.png" thumbFile:@"sliderThumb.png"];
        _slider.minimumValue = 0.0f;
        _slider.maximumValue = 1.0f;
        _slider.position = ccp(size.width/3, size.height/2);
        [_slider addTarget:self action:@selector(valueChanged:) forControlEvents:CCControlEventValueChanged];
        [self addChild:_slider];
        
        // Create the display label
        _displayValueLabel = [CCLabelTTF labelWithString:[NSString stringWithFormat:@"0.0%f", 100*_slider.value] fontName:@"Marker Felt" fontSize:28];
        _displayValueLabel.position = ccp(size.width/3 + _slider.contentSize.width/3*2, size.height/2);
		[self addChild:_displayValueLabel];

        // Postion Volume label
        CCLabelTTF *volumeLabel = [CCLabelTTF labelWithString:@"Volume:" fontName:@"Marker Felt" fontSize:28];
        volumeLabel.position = ccp(size.width/3 - _slider.contentSize.width/3, size.height/2 + _slider.contentSize.height);
        [self addChild:volumeLabel];
        
        // Create dismiss button
        CCMenuItemFont *dismiss = [CCMenuItemFont itemWithString:@"Dismiss" target:self selector:@selector(dismissPressed:)];
        dismiss.position = ccp(size.width/2, 30);
        CCMenu *menu = [CCMenu menuWithItems:dismiss, nil];
        menu.position = CGPointZero;
        [self addChild:menu];
	}
    
	return self;
}

-(void)dealloc
{
	[super dealloc];

    //[self.displayValueLabel release];
    //[self.slider release];
}

-(void)onEnterTransitionDidFinish
{
    [super onEnterTransitionDidFinish];
    
    NSUserDefaults *preferences = [NSUserDefaults standardUserDefaults];
    NSNumber *value = [preferences objectForKey:kVolume];
    
    [self.slider setValue:value.floatValue animated:NO];
}

-(void)dismissPressed:(id)sender
{
//    CCScene *scene = [CCScene node];
//    [scene addChild:[MenuLayer scene]];
//    [[CCDirector sharedDirector] replaceScene:scene];
    [[SimpleAudioEngine sharedEngine] playEffect:@"back.wav"];
    [[CCDirector sharedDirector] popScene];
}

-(void)valueChanged:(id)sender
{
    CCControlSlider *slider = sender;
    self.displayValueLabel.string = [NSString stringWithFormat:@"%0.0f", 100*slider.value];
    
    [[SimpleAudioEngine sharedEngine] setEffectsVolume:slider.value];
    [[SimpleAudioEngine sharedEngine] setBackgroundMusicVolume:slider.value];
    
    NSUserDefaults *preferences = [NSUserDefaults standardUserDefaults];
    [preferences setFloat:slider.value forKey:kVolume];
    [preferences synchronize];
}

@end
