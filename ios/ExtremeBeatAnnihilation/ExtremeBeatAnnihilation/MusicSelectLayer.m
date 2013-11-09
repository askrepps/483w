//
//  MusicSelectLayer.m
//  ExtremeBeatAnnihilation
//
//  Created by ANDREW STEPHEN KREPPS on 11/9/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import "MusicSelectLayer.h"
#import "BackgroundLayer.h"
#import "cocos2d.h"

@implementation MusicSelectLayer
{
    UIViewController *musicController;
}

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
        CCMenu *musicMenu = [CCMenu menuWithItems:sampleSong1, sampleSong2, sampleSong3, chooseSong, nil];
        
        
		CGSize size = [[CCDirector sharedDirector] winSize];
        label.position =  ccp(size.width/2, size.height - 32);
        sampleSong1.position = ccp(size.width/2, size.height - 96);
        sampleSong2.position = ccp(size.width/2, size.height - 128);
        sampleSong3.position = ccp(size.width/2, size.height - 160);
        chooseSong.position = ccp(size.width/2, size.height - 224);
        musicMenu.position = CGPointZero;
        
        [self addChild:label];
        [self addChild:musicMenu];
        
    }
    
    return self;
}

-(void) loadSample1
{
    NSLog(@"Loading Sample Track #1...");
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
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Warning" message:@"Media picker doesn't work in the simulator, please run this app on a device." delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
    [alert show];
#else
    [[CCDirector sharedDirector] pause];
    
    musicController = [[UIViewController alloc] init];
    [musicController setView:[[CCDirector sharedDirector] view]];
    [musicController setModalTransitionStyle: UIModalTransitionStyleCoverVertical];
    
    MPMediaPickerController *picker = [[MPMediaPickerController alloc] initWithMediaTypes:MPMediaTypeAnyAudio];
    picker.delegate = self;
    picker.allowsPickingMultipleItems = NO;
    picker.prompt = @"Select a Song...";
    [musicController presentViewController:picker animated:YES completion:NULL];
#endif

}

- (void)mediaPicker:(MPMediaPickerController *) mediaPicker didPickMediaItems:(MPMediaItemCollection *) collection
{    
    [musicController dismissViewControllerAnimated:YES completion:NULL];
    [musicController release];
    
    [[CCDirector sharedDirector] resume];
    
    MPMediaItem *item = [[collection items] objectAtIndex:0];
    NSURL *url = [item valueForProperty:MPMediaItemPropertyAssetURL];
    
    // Initialize LevelData object here!!!
    NSLog(@"Loading File URL: %@", url);
}


- (void)mediaPickerDidCancel:(MPMediaPickerController *) mediaPicker
{
    [musicController dismissViewControllerAnimated:YES completion:NULL];
    [musicController release];
    [[CCDirector sharedDirector] resume];
}

@end
