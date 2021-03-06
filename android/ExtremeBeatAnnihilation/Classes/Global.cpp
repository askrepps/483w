#include "Global.h"

// global variables to use between all files (extern them to use them)----------------------------------
int         Font_Size_Default;     // default size of all font
int         Font_Size_Small;       // font size for smaller text

std::string Game_Song;             // file path to the song to play for the game scene

bool        Is_Single_Player;      // true when single player, false when multiplayer
bool        Prev_Was_Main_Menu;    // true when previous scene was main menu, false when game scene

int         Player_One;            // id of the character selected for player one (left player)
int         Player_Two;            // id of the character selected for player two (right player)

int			Player_One_Score;      // Score for player one (or the score for single player)
int  		Player_Two_Score;	   // Score for player two (for multiplayer)

int 		Jump_Y_Pos;			   // The jump y position
int         Slide_Y_Pos;           // The slide y position

bool        Allow_Volume_Set;      // true when volume levels are allowed to change, false when not
float       Music_Volume;          // volume level for the music
float       SFX_Volume;            // volume level for the sound effects

std::vector<Obstacle*>  Left_Obstacles;   // The obstacles for the left side of the screen
std::vector<Obstacle*>  Right_Obstacles;  // The obstacles for the right side of the screen
std::vector<SoundEvent> Events;         // Events generate to make the obstacles
