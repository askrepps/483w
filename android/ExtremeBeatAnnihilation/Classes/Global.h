#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <string>
#include <vector>

#include "Obstacle.h"
// macros to be used by all files-----------------------------------------------------------------------
#define COCOS2D_DEBUG          1

#define VELOCITY               250   // speed factor at which to move objects on the game screen

#define MENU_MUSIC             "Music/MenuSong.mp3"   // song to play for the menus
#define INIT_MUSIC_VOL         50    // initial music volume; between 1 - 100
#define INIT_SFX_VOL           50    // initial sound effects volume; between 1 - 100
#define VOLUME_FACTOR          100   // factor to divide volume in order to get number between 0.0 - 1.0
#define NO_CHAR_SELECT 		   -1    // No character is currently selected

#define POS_HALF_SCREEN        0.5   // factor of screen width/height which give a position halfway
#define POS_QUARTER_SCREEN     0.25  // factor of screen width/height which gives a position quarter-way
#define POS_THREE_QUART_SCREEN 0.75  // factor of screen width/height which gives a position
								     //   three-quarter-way

#define PLAYER_Y_POS           0.175  // The position of the player vertically
#define JUMP_Y_POS             0.175  // The position for the jumping obstacle
#define SLIDE_Y_POS 		   0.185  // the position for the sliding obstacle

#define PLAYER_SCALE 1.4			 // The scale for the players to use

#define JUMPING_OBSTACLE 1			 // The obstacle is a jumping obstacle
#define SLIDING_OBSTACLE 0			 // The obstacle is a sliding obstacle

#define JUMPING_SPRITE "Obstacles/smallFire.png"		// The sprite location for jumping obstacles
#define SLIDING_SPRITE "Obstacles/smallCoil.png"		// The sprite location for sliding obstacles

#endif // __GLOBAL_H__
