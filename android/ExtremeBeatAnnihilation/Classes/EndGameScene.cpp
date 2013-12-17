#include "EndGameScene.h"

using namespace cocos2d;
using namespace CocosDenshion;

// externs defined in Global.h
extern bool Is_Single_Player;      // Are we playing in single player?
extern int	Player_One_Score;      // Score for player one (or the score for single player)
extern int 	Player_Two_Score;	   // Score for player two (for multiplayer)

// Initialize the end game menu to display over the game scene
//
// return - false if there was an error in initializing, true otherwise
bool EndGame::init()
{
    CCLabelTTF*      header;         // the header which displays that this is an end game scene
    CCLabelTTF*      score;			 // the text for quit to main menu menu item
    CCLabelTTF*      labelMainMenu;  // the text for quit to main menu menu item
    CCMenuItemLabel* itemMainMenu;   // menu item for quitting to main menu
    CCMenu*          menu;           // menu to contain the menu items
    CCSize           size;           // the size of the window

    if(!CCLayer::init())
    {
        return false;
    }

    // get the window size from the director
    size = CCDirector::sharedDirector()->getWinSize();

    // create the header and add it to the scene
    header = CCLabelTTF::create("GAME OVER!", MENU_FONT_STYLE, MENU_FONT_SIZE);
    header->setColor(MENU_COLOR);
    header->setPosition( ccp(size.width * POS_HALF_SCREEN, size.height * POS_HEADER_HEIGHT) );
    this->addChild(header, 1);

    // Set up for single player or not
        if(Is_Single_Player)
        	SetUpSinglePlayer(size);
        else
        	SetUpMultiPlayer(size);

    // create the quit to main menu menu item
    labelMainMenu = CCLabelTTF::create("Go to Main Menu", MENU_FONT_STYLE, MENU_FONT_SIZE);
    itemMainMenu  = CCMenuItemLabel::create(labelMainMenu, this, menu_selector(EndGame::HandleMainMenuPressed));
    itemMainMenu->setColor(MENU_COLOR);

    // create the menu containing the menu items and add it to the scene
    menu = CCMenu::create(itemMainMenu, NULL);
    menu->alignItemsVerticallyWithPadding(MENU_ITEM_PADDING);
    menu->setPosition(size.width * POS_HALF_SCREEN, size.height * POS_HALF_SCREEN);
    this->addChild(menu, 1);

    return true;
}

// Create a end game scene that has a EndGame layer
//
// return - a newly created end game scene
CCScene* EndGame::Scene()
{
    CCScene*    scene = CCScene::create();       // the end game scene to return
    EndGame* 	layer = EndGame::create();       // the layer for the scene

    scene->addChild(layer);

    return scene;
}
// runs when the app enters the scene
void EndGame::onEnter()
{
    CCLayer::onEnter();
}

void EndGame::SetUpSinglePlayer(CCSize size)
{
	// Create the label in the top middle
	m_scoreLabel = CCLabelTTF::create(CCString::createWithFormat("Score: %d", Player_One_Score)->getCString(), MENU_FONT_STYLE, MENU_FONT_SIZE);
	m_scoreLabel->setColor(MENU_COLOR);
	m_scoreLabel->setPosition(ccp(size.width * POS_HALF_SCREEN, size.height * .8));

	// Add  the label to the layer
	this->addChild(m_scoreLabel, 1);
}

void EndGame::SetUpMultiPlayer(CCSize size)
{
	// Create the label for player one, in the top in the middle of the left hand side
	m_scoreLabel = CCLabelTTF::create(CCString::createWithFormat("Player One Score: %d", Player_One_Score)->getCString(), MENU_FONT_STYLE, MENU_FONT_SIZE);
	m_scoreLabel->setColor(MENU_COLOR);
	m_scoreLabel->setPosition(ccp(size.width * POS_HALF_SCREEN , size.height * .8));

	// Creat the label for player two, in the top in the middle of the right hand side
	m_p2scoreLabel = CCLabelTTF::create(CCString::createWithFormat("Player Two Score: %d", Player_Two_Score)->getCString(), MENU_FONT_STYLE, MENU_FONT_SIZE);
	m_p2scoreLabel->setColor(MENU_COLOR);
	m_p2scoreLabel->setPosition(ccp(size.width * POS_HALF_SCREEN, size.height * .7));

	// Add the labels to the layer
	this->addChild(m_scoreLabel, 1);
	this->addChild(m_p2scoreLabel, 1);
}

// On selecting the quit to main menu menu item, go to the main menu
//
// sender [in] - the object that sent the selected event
void EndGame::HandleMainMenuPressed(CCObject* sender)
{
    SimpleAudioEngine::sharedEngine()->playEffect("SFX/select.wav");

    // these lines can be done in this order, because each line is read and saved before executing them

    CCLog("trying to pop");
    // pop this scene off the stack which brings you to the game scene, and then replace with main menu
    CCDirector::sharedDirector()->popScene();
    CCLog("pop successful");
    CCLog("trying to replace Scene");
    CCDirector::sharedDirector()->replaceScene(MainMenu::Scene());
    CCLog("replace Scene success");

    // stop will destroy the game scene music data, and then start up the menu music
    CCLog("trying to stop background music");
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    CCLog("success");
    CCLog("trying to play menu music");
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic(MENU_MUSIC, true);
    CCLog("success");
}
