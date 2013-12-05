#include "Global.h"

// global variables to use between all files (extern them to use them)----------------------------------
std::string Game_Song;             // file path to the song to play for the game scene
bool        Is_Single_Player;      // true when single player, false when multiplayer
bool        Prev_Was_Main_Menu;    // true when previous scene was main menu, false when game scene
int         Player_One;            // id of the character selected for player one (left player)
int         Player_Two;            // id of the character selected for player two (right player)
