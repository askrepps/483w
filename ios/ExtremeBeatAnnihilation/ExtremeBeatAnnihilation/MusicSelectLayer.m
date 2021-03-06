//
//  MusicSelectLayer.m
//  ExtremeBeatAnnihilation
//
//  Created by ANDREW STEPHEN KREPPS on 11/9/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "MusicSelectLayer.h"
#import "BackgroundLayer.h"
#import "AppDelegate.h"
#import "Registry.h"
#import "LoadingLayer.h"
#import "CharacterSelectLayer.h"
#import "SimpleAudioEngine.h"

@implementation MusicSelectLayer

+(CCScene *)scene
{
	CCScene *scene = [CCScene node];
	
    //BackgroundLayer *background = [BackgroundLayer node];
	MusicSelectLayer *mode = [MusicSelectLayer node];
	
    //[scene addChild:background z:-1];
	[scene addChild:mode];
	
	return scene;
}

-(id) init
{
    if (self = [super init])
    {
        CCLabelTTF *label = [CCLabelTTF labelWithString:@"Music Select" fontName:@"Marker Felt" fontSize:32];
        
        CCMenuItemFont *sampleSong1 = [CCMenuItemFont itemWithString:@"Letting Go - UltraMax" target:self selector:@selector(loadSample1)];
        CCMenuItemFont *sampleSong2 = [CCMenuItemFont itemWithString:@"The Call of Stars - UltraMax" target:self selector:@selector(loadSample2)];
        CCMenuItemFont *sampleSong3 = [CCMenuItemFont itemWithString:@"Piano Test File" target:self selector:@selector(loadSample3)];
        CCMenuItemFont *chooseSong = [CCMenuItemFont itemWithString:@"Choose from Library..." target:self selector:@selector(loadFromLibrary)];
        CCMenuItemFont *back = [CCMenuItemFont itemWithString:@"Back" target:self selector:@selector(backPressed)];
        CCMenu *musicMenu = [CCMenu menuWithItems:sampleSong1, sampleSong2, sampleSong3, chooseSong, back, nil];
        
		CGSize size = [[CCDirector sharedDirector] winSize];
        label.position =  ccp(size.width/2, size.height - 32);
        sampleSong1.position = ccp(size.width/2, size.height - 96);
        sampleSong2.position = ccp(size.width/2, size.height - 128);
        sampleSong3.position = ccp(size.width/2, size.height - 160);
        chooseSong.position = ccp(size.width/2, size.height - 224);
        back.position = ccp(size.width/2, 32);

        musicMenu.position = CGPointZero;
                
        [self addChild:label];
        [self addChild:musicMenu];
    }
    
    return self;
}

-(void) backPressed
{
    [[SimpleAudioEngine sharedEngine] playEffect:@"back.wav"];
    [[CCDirector sharedDirector] replaceScene:[CharacterSelectLayer scene]];
}

-(void) loadSample1
{
    [[SimpleAudioEngine sharedEngine] playEffect:@"select.wav"];
    NSURL *url = [[NSBundle mainBundle] URLForResource:@"LettingGo" withExtension:@"mp3"];
    [Registry setMusicName:@"Letting Go"];
    [Registry setMusicURL:url];
    [Registry setIsFileFromLibrary:NO];
    [url release];
    [[CCDirector sharedDirector] replaceScene:[LoadingLayer scene]];
}

-(void) loadSample2
{
    [[SimpleAudioEngine sharedEngine] playEffect:@"select.wav"];
    NSURL *url = [[NSBundle mainBundle] URLForResource:@"TheCallOfStars" withExtension:@"mp3"];
    [Registry setMusicName:@"The Call of Stars"];
    [Registry setMusicURL:url];
    [Registry setIsFileFromLibrary:NO];
    [url release];
    [[CCDirector sharedDirector] replaceScene:[LoadingLayer scene]];
}

-(void) loadSample3
{
    [[SimpleAudioEngine sharedEngine] playEffect:@"select.wav"];
    NSURL *url = [[NSBundle mainBundle] URLForResource:@"test2" withExtension:@"m4a"];
    [Registry setMusicName:@"Piano Test File"];
    [Registry setMusicURL:url];
    [Registry setIsFileFromLibrary:NO];
    [url release];
    [[CCDirector sharedDirector] replaceScene:[LoadingLayer scene]];
}

-(void) loadFromLibrary
{
    [[SimpleAudioEngine sharedEngine] playEffect:@"select.wav"];
#if TARGET_IPHONE_SIMULATOR
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Warning" message:@"Media picker unavailable in the simulator, please run this app on a device." delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
    [alert show];
#else
    [[CCDirector sharedDirector] pause];
    
    MPMediaPickerController *picker = [[MPMediaPickerController alloc] initWithMediaTypes:MPMediaTypeAnyAudio];
    picker.delegate = self;
    picker.allowsPickingMultipleItems = NO;
    picker.prompt = @"Select a Song...";
    
    AppController *app = (AppController*) [[UIApplication sharedApplication] delegate];
    [app.navController presentViewController:picker animated:YES completion:NULL];
#endif
}

- (void)mediaPicker:(MPMediaPickerController *) mediaPicker didPickMediaItems:(MPMediaItemCollection *) collection
{
    MPMediaItem *item = [[collection items] objectAtIndex:0];
    NSURL *url = [item valueForProperty:MPMediaItemPropertyAssetURL];
    
    [Registry setMusicURL:url];
    [Registry setIsFileFromLibrary:YES];
    [Registry setMusicName:[item valueForProperty:MPMediaItemPropertyTitle]];
    
    AppController *app = (AppController*) [[UIApplication sharedApplication] delegate];
    [app.navController dismissViewControllerAnimated:YES completion:NULL];
    
    [[CCDirector sharedDirector] resume];
    [[CCDirector sharedDirector] replaceScene:[LoadingLayer scene]];
}


- (void)mediaPickerDidCancel:(MPMediaPickerController *) mediaPicker
{
    AppController *app = (AppController*) [[UIApplication sharedApplication] delegate];
    [app.navController dismissViewControllerAnimated:YES completion:NULL];
    [[CCDirector sharedDirector] resume];
}

@end
