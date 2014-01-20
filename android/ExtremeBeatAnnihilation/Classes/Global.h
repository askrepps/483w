#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "Obstacle.h"
#include "SoundEvent.h"

// macros to be used by all files-----------------------------------------------------------------------
#define COCOS2D_DEBUG          1

#define VELOCITY               250   // speed factor at which to move objects on the game screen

#define MENU_MUSIC             "Music/MenuSong.mp3"   // song to play for the menus
#define INIT_MUSIC_VOL         50    // initial music volume; between 1 - 100
#define INIT_SFX_VOL           50    // initial sound effects volume; between 1 - 100
#define VOLUME_FACTOR          100   // factor to divide volume in order to get number between 0.0 - 1.0
#define NO_CHAR_SELECT 		   -1    // No character is currently selected

#define FONT_STYLE             "Fonts/BlackWolf.ttf"  // font style for all text in the game

#define POS_HALF_SCREEN        0.5   // factor of screen width/height which give a position halfway
#define POS_QUARTER_SCREEN     0.25  // factor of screen width/height which gives a position quarter-way
#define POS_THREE_QUART_SCREEN 0.75  // factor of screen width/height which gives a position
								     //   three-quarter-way

#define PLAYER_Y_POS           0.175  // The position of the player vertically
#define JUMP_Y_POS             0.160  // The position for the jumping obstacle
#define SLIDE_Y_POS 		   0.340  // the position for the sliding obstacle

#define PLAYER_SCALE 0.15			 // The factor of screen height to scale players in the game scene

#define JUMPING_OBSTACLE 1			 // The obstacle is a jumping obstacle
#define SLIDING_OBSTACLE 0			 // The obstacle is a sliding obstacle

#define OFFSET 500				     // The offset offscreen to spawn the obstacles

#define JUMPING_SPRITE "Obstacles/smallFire.png"		// The sprite location for jumping obstacles
#define SLIDING_SPRITE "Obstacles/smallCoil.png"		// The sprite location for sliding obstacles

#define SINGLE_PLAYER_DEDUCTION -500					// Score to deduct in single player
#define MULTI_PLAYER_DEDUCTION -1000					// Score to deduct in multi player

#define NUM_OBSTACLES 225			 // The number of obstacles to create

#define SLIDING_OFFSET 10			 // How much higher do we make the obstacle
#define JUMPING_OFFSET 81			 // How much do we offset the obstacle

#define INVULN_PERIOD 1.0			 // How long the player is invulnerable - in seconds

#endif // __GLOBAL_H__
