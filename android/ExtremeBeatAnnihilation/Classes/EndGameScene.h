#ifndef __END_GAME__
#define __END_GAME__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

#include "Global.h"

#include "MainMenuScene.h"
#include "OptionsMenuScene.h"

#define POS_HEADER_HEIGHT    0.9                 // factor of height to position the header
#define MENU_COLOR           ccc3(255, 255, 255) // RGB color of the menu items
#define MENU_FONT_SIZE       50                  // size of the font for the menu items
#define MENU_ITEM_PADDING    20                  // padding between menu items, most likely in pixels

class EndGame : public cocos2d::CCLayer
{
public:
    virtual bool init();

    static cocos2d::CCScene* Scene();

    void SetUpSinglePlayer(cocos2d::CCSize size);// Set up the EndGame for single player
    void SetUpMultiPlayer(cocos2d::CCSize size); // Set up the EndGame for multi player

    void HandleMainMenuPressed(CCObject* sender);

    // allows use of create() function which uses init() to create this layer
    CREATE_FUNC(EndGame);

private:
    cocos2d::CCLabelTTF* m_scoreLabel;		  // The label to hold the score
    cocos2d::CCLabelTTF* m_p2scoreLabel;	  // Player 2 Score label
};

#endif // __END_GAME__
