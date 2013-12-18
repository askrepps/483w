#include "UILayer.h"

using namespace cocos2d;
using namespace CocosDenshion;

extern bool Is_Single_Player;      // Are we playing in single player?
extern int	Player_One_Score;      // Score for player one (or the score for single player)
extern int 	Player_Two_Score;	   // Score for player two (for multiplayer)

// Initialize the UI for the main game scene
//
// return - false if there was an error in initializing, true otherwise
bool UILayer::init()
{
    CCLabelTTF*      labelPause;  // the text for pause menu item
    CCMenuItemLabel* itemPause;   // menu item for opening the pause menu
    CCMenu*          menu;        // menu to contain the menu item
    CCSize           size;        // the size of the window

    if(!CCLayer::init())
    {
        return false;
    }

    // get the window size from the director
    size = CCDirector::sharedDirector()->getWinSize();

    // create the pause menu item, and add an outline around it to make it readable
    labelPause = CCLabelTTF::create("Pause", FONT_STYLE, MENU_FONT_SIZE);
    labelPause->enableStroke(FONT_STROKE_COLOR, FONT_STROKE_THICK);

    // Set up for single player or not
    if(Is_Single_Player)
    	SetUpSinglePlayer(size);
    else
    	SetUpMultiPlayer(size);

    itemPause  = CCMenuItemLabel::create(labelPause, this, menu_selector(UILayer::HandlePausePressed));
    itemPause->setColor(MENU_COLOR);
    itemPause->setPosition(ccp(size.width * PAUSE_WIDTH_POS, size.height * PAUSE_HEIGHT_POS));

    // create the menu containing the pause item
    menu = CCMenu::create(itemPause, NULL);
    menu->setPosition(CCPointZero);
    this->addChild(m_scoreLabel, 1);
    this->addChild(menu, 1);

    return true;
}

void UILayer::SetUpSinglePlayer(CCSize size)
{
	// Set the score to 0
	Player_One_Score = 0;

	// Create the label in the top middle
	m_scoreLabel = CCLabelTTF::create(CCString::createWithFormat("%d", Player_One_Score)->getCString(), FONT_STYLE, MENU_FONT_SIZE);
	m_scoreLabel->setColor(MENU_COLOR);
	m_scoreLabel->enableStroke(FONT_STROKE_COLOR, FONT_STROKE_THICK);
	m_scoreLabel->setPosition(ccp(size.width * POS_HALF_SCREEN, size.height * .95));

	// Add  the label to the layer
	this->addChild(m_scoreLabel, 1);
}

void UILayer::SetUpMultiPlayer(CCSize size)
{
	// Set the score to 0 to start with
	Player_One_Score = 0;
	Player_Two_Score = 0;

	// Create the label for player one, in the top in the middle of the left hand side
	m_scoreLabel = CCLabelTTF::create(CCString::createWithFormat("%d", Player_One_Score)->getCString(), FONT_STYLE, MENU_FONT_SIZE);
	m_scoreLabel->setColor(MENU_COLOR);
	m_scoreLabel->enableStroke(FONT_STROKE_COLOR, FONT_STROKE_THICK);
	m_scoreLabel->setPosition(ccp(size.width * POS_QUARTER_SCREEN , size.height * .95));

	// Create the label for player two, in the top in the middle of the right hand side
	m_p2scoreLabel = CCLabelTTF::create(CCString::createWithFormat("%d", Player_Two_Score)->getCString(), FONT_STYLE, MENU_FONT_SIZE);
	m_p2scoreLabel->setColor(MENU_COLOR);
	m_p2scoreLabel->enableStroke(FONT_STROKE_COLOR, FONT_STROKE_THICK);
	m_p2scoreLabel->setPosition(ccp(size.width * POS_THREE_QUART_SCREEN, size.height * .95));

	// Add the labels to the layer
	this->addChild(m_scoreLabel, 1);
	this->addChild(m_p2scoreLabel, 1);
}

void UILayer::UpdateLayer(float delta)
{
	UpdateScore(10);
}

void UILayer::UpdateScore(int delta)
{
	Player_One_Score += delta;
	m_scoreLabel->setString(CCString::createWithFormat("%d", Player_One_Score)->getCString());

	if(!Is_Single_Player)
	{
		Player_Two_Score += delta;
		m_p2scoreLabel->setString(CCString::createWithFormat("%d", Player_Two_Score)->getCString());
	}
}

// On selecting the pause menu item, pause the game and bring up the pause menu
//
// sender [in] - the object that sent the selected event
void UILayer::HandlePausePressed(CCObject* sender)
{
    SimpleAudioEngine::sharedEngine()->playEffect("SFX/select.wav");
    CCDirector::sharedDirector()->pushScene(PauseLayer::Scene());
}
