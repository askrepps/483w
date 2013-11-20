#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <string>

// macros to be used by all files-----------------------------------------------------------------------
#define COCOS2D_DEBUG          1

#define MENU_MUSIC             "Music/MenuSong.mp3"   // song to play for the menus
#define INIT_MUSIC_VOL         0.5                    // initial music volume; between 0.0 - 1.0
#define INIT_SFX_VOL           0.5                    // initial sound effects volume; between 0.0 - 1.0

#define POS_HALF_SCREEN        0.5   // factor of screen width/height which give a position halfway
#define POS_QUARTER_SCREEN     0.25  // factor of screen width/height which gives a position quarter-way
#define POS_THREE_QUART_SCREEN 0.75  // factor of screen width/height which gives a position
                                     //   three-quarter-way

// statically created structure that holds all variables to share between scenes------------------------
static struct Global
{
    std::string gameSong;
	bool        isSinglePlayer;
	int         playerOne;
	int         playerTwo;
} global;

#endif // __GLOBAL_H__
