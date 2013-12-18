#ifndef __UI_LAYER_H__
#define __UI_LAYER_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

#include "Global.h"

#include "PauseScene.h"

#define PAUSE_WIDTH_POS      0.5                 // factor of screen with to position pause menu item
#define PAUSE_HEIGHT_POS     0.08                // factor of screen height to position pause menu item
#define MENU_COLOR           ccc3(255, 255, 255) // RGB color of the menu items
#define MENU_FONT_SIZE       50                  // size of the font for the menu items

class UILayer : public cocos2d::CCLayer
{
public:
    virtual bool init();
    void UpdateLayer(float delta);				 // Overrides update, update the scores
    void SetUpSinglePlayer(cocos2d::CCSize size);// Set up the UI for single player
    void SetUpMultiPlayer(cocos2d::CCSize size); // Set up the UI for multi player
    void UpdateScore(int delta);				 // Update the scores, it automatically converts for multiplayer
    void HandlePausePressed(CCObject* sender);   // Handle pause being pressed

    // allows use of create() function which uses init() to create this layer
    CREATE_FUNC(UILayer);
private:
    cocos2d::CCLabelTTF* m_scoreLabel;		  // The label to hold the score
    cocos2d::CCLabelTTF* m_p2scoreLabel;	  // Player 2 Score label
};

#endif // __UI_LAYER_H__
