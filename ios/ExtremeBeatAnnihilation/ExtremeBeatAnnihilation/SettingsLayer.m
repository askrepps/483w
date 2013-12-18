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
#import "Registry.h"

@interface SettingsLayer ()
@property (nonatomic, strong) CCLabelTTF *displayMusicLabel;
@property (nonatomic, strong) CCLabelTTF *displaySFXLabel;
@property (nonatomic, strong) CCControlSlider *musicSlider;
@property (nonatomic, strong) CCControlSlider *sfxSlider;

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
        
        // Create the sliders
        _musicSlider = [CCControlSlider sliderWithBackgroundFile:@"sliderTrack.png" progressFile:@"sliderProgress.png" thumbFile:@"sliderThumb.png"];
        _musicSlider.minimumValue = 0.0f;
        _musicSlider.maximumValue = 1.0f;
        _musicSlider.position = ccp(size.width/3, size.height/2 + 40);
        [_musicSlider addTarget:self action:@selector(musicValueChanged:) forControlEvents:CCControlEventValueChanged];
        [self addChild:_musicSlider];
        
        _sfxSlider = [CCControlSlider sliderWithBackgroundFile:@"sliderTrack.png" progressFile:@"sliderProgress.png" thumbFile:@"sliderThumb.png"];
        _sfxSlider.minimumValue = 0.0f;
        _sfxSlider.maximumValue = 1.0f;
        _sfxSlider.position = ccp(size.width/3, size.height/2 - 40);
        [_sfxSlider addTarget:self action:@selector(sfxValueChanged:) forControlEvents:CCControlEventValueChanged];
        [self addChild:_sfxSlider];
        
        // Create the display labels
        _displayMusicLabel = [CCLabelTTF labelWithString:[NSString stringWithFormat:@"0.0%f", 100*_musicSlider.value] fontName:@"Marker Felt" fontSize:28];
        _displayMusicLabel.position = ccp(size.width/3 + _musicSlider.contentSize.width/3*2, size.height/2);
		[self addChild:_displayMusicLabel];
        
        _displaySFXLabel = [CCLabelTTF labelWithString:[NSString stringWithFormat:@"0.0%f", 100*_sfxSlider.value] fontName:@"Marker Felt" fontSize:28];
        _displaySFXLabel.position = ccp(size.width/3 + _sfxSlider.contentSize.width/3*2, size.height/2);
		[self addChild:_displaySFXLabel];

        // Postion labell
        CCLabelTTF *volumeLabel = [CCLabelTTF labelWithString:@"Music:" fontName:@"Marker Felt" fontSize:28];
        volumeLabel.position = ccp(size.width/3 - _musicSlider.contentSize.width/3, size.height/2 + _musicSlider.contentSize.height);
        [self addChild:volumeLabel];
        
        CCLabelTTF *sfxLabel = [CCLabelTTF labelWithString:@"SFX:" fontName:@"Marker Felt" fontSize:28];
        sfxLabel.position = ccp(size.width/3 - _sfxSlider.contentSize.width/3, size.height/2 + _sfxSlider.contentSize.height);
        [self addChild:sfxLabel];
        
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
}

-(void)onEnterTransitionDidFinish
{
    [super onEnterTransitionDidFinish];
    
    NSUserDefaults *preferences = [NSUserDefaults standardUserDefaults];
    NSNumber *musicValue = [preferences objectForKey:kMusic];
    NSNumber *sfxValue = [preferences objectForKey:kSFX];
    
    [self.musicSlider setValue:musicValue.floatValue animated:NO];
    [self.sfxSlider setValue:sfxValue.floatValue animated:NO];
}

-(void)dismissPressed:(id)sender
{
    [[SimpleAudioEngine sharedEngine] playEffect:@"back.wav"];
    [[CCDirector sharedDirector] popScene];
}

-(void)musicValueChanged:(id)sender
{
    CCControlSlider *slider = sender;
    self.displayMusicLabel.string = [NSString stringWithFormat:@"%0.0f", 100*slider.value];
    
    [[SimpleAudioEngine sharedEngine] setBackgroundMusicVolume:slider.value];
    
    NSUserDefaults *preferences = [NSUserDefaults standardUserDefaults];
    [preferences setFloat:slider.value forKey:kMusic];
    [preferences synchronize];
}

-(void)sfxValueChanged:(id)sender
{
    CCControlSlider *slider = sender;
    self.displaySFXLabel.string = [NSString stringWithFormat:@"%0.0f", 100*slider.value];
    
    [[SimpleAudioEngine sharedEngine] setEffectsVolume:slider.value];
    
    NSUserDefaults *preferences = [NSUserDefaults standardUserDefaults];
    [preferences setFloat:slider.value forKey:kSFX];
    [preferences synchronize];
}

@end
