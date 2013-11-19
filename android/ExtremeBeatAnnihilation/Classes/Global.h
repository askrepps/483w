#ifndef __GLOBAL_H__
#define __GLOBAL_H__

// macros to be used by all files
#define POS_HALF_SCREEN        0.5   // factor of screen width/height which give a position halfway
#define POS_QUARTER_SCREEN     0.25  // factor of screen width/height which gives a position quarter-way
#define POS_THREE_QUART_SCREEN 0.75  // factor of screen width/height which gives a position
                                     //   three-quarter-way

// statically created structure that holds all variables to share between scenes
static struct Global
{
	int  m_musicVolume;
	int  m_sfxVolume;
	bool m_isSinglePlayer;
	int  m_playerOne;
	int  m_playerTwo;
} global;

#endif // __GLOBAL_H__
