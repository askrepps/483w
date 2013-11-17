//
//  MusicSelectLayer.h
//  ExtremeBeatAnnihilation
//
//  Created by ANDREW STEPHEN KREPPS on 11/9/13.
//  Copyright (c) 2013 Crash Course Gaming. All rights reserved.
//

#import <MediaPlayer/MPMediaPickerController.h>
#import "cocos2d.h"

@interface MusicSelectLayer : CCLayer <MPMediaPickerControllerDelegate>

+(CCScene *)scene;

@end
