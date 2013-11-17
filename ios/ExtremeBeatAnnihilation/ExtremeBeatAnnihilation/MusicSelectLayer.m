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

@implementation MusicSelectLayer

+(CCScene *)scene
{
	CCScene *scene = [CCScene node];
	
    BackgroundLayer *background = [BackgroundLayer node];
	MusicSelectLayer *mode = [MusicSelectLayer node];
	
    [scene addChild:background z:-1];
	[scene addChild:mode];
	
	return scene;
}

-(id) init
{
    if (self = [super init])
    {
        CCLabelTTF *label = [CCLabelTTF labelWithString:@"Music Select" fontName:@"Marker Felt" fontSize:32];
        
        CCMenuItemFont *sampleSong1 = [CCMenuItemFont itemWithString:@"Sample Track #1" target:self selector:@selector(loadSample1)];
        CCMenuItemFont *sampleSong2 = [CCMenuItemFont itemWithString:@"Sample Track #2" target:self selector:@selector(loadSample2)];
        CCMenuItemFont *sampleSong3 = [CCMenuItemFont itemWithString:@"Sample Track #3" target:self selector:@selector(loadSample3)];
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
    [[CCDirector sharedDirector] popScene];
}

-(void) loadSample1
{
    [Registry setMusicURL:[NSURL fileURLWithPath:@"Resources/SampleTracks/LettingGo.mp3"]];
    [[CCDirector sharedDirector] replaceScene:[LoadingLayer scene]];
}

-(void) loadSample2
{
    NSLog(@"Loading Sample Track #2...");
}

-(void) loadSample3
{
    NSLog(@"Loading Sample Track #3...");
}

-(void) loadFromLibrary
{
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
