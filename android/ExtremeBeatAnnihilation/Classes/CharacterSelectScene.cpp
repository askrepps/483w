#include "CharacterSelectScene.h"

using namespace cocos2d;
using namespace CocosDenshion;

// externs defined in Global.h
extern int Player_One;
extern int Player_Two;

CCScene* CharacterSelect::Scene()
{
    CCScene*         scene = CCScene::create();
    CharacterSelect* layer = CharacterSelect::create();

    // add layer as a child to scene
    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool CharacterSelect::init()
{
    CCSize           size;						// The size of the screen
    CCMenuItemFont*  backItem;					// Goes back to the previous selection
    CCMenuItemFont*  continueItem;				// Goes forward in the process
    CCMenuItemImage* characterOne;				// Character One for the select screen
    CCMenuItemImage* characterTwo;				// Character Two for the select screen
    CCMenuItemImage* characterThree;			// Character Three for the select screen
    CCMenuItemImage* selectedCharacterOne;
    CCMenuItemImage* selectedCharacterTwo;
    CCMenuItemImage* selectedCharacterThree;
   	CCLabelTTF*       label;					// The label to display current status
    CCMenu* 		  characterMenu;			// The menu

    // Super init, MUST DO
    if(!CCLayer::init())
    {
        return false;
    }

    // Initialize number of characters to 0
    m_numCharacters = 0;

    // Set the selected index to nothing being selected
    m_currentSelectedChar = NO_CHAR_SELECT;

    // get the window size from the director
    size = CCDirector::sharedDirector()->getWinSize();

    // add a "close" icon to exit the process
    backItem = CCMenuItemFont::create("Back",  this,
                                           menu_selector(CharacterSelect::MenuBackCallback));
    backItem->setPosition(ccp(size.width / 4 * 3, 50));

    // add a "continue" icon
    continueItem = CCMenuItemFont::create("Continue", this, menu_selector(CharacterSelect::MenuContinueCallback));
    continueItem->setPosition(ccp(size.width / 4, 50));

	// Create the character menu items and load them into memory, set their tags
	characterOne = CCMenuItemImage::create("CharacterIcons/CharacterOne.png", "CharacterIcons/selectCharacterOne.png");
	selectedCharacterOne = CCMenuItemImage::create("CharacterIcons/selectCharacterOne.png", "CharacterIcons/CharacterOne.png");
	CCLog("%p %p %p\n", this,  characterOne, selectedCharacterOne);
	m_charOne_Wrapper = CCMenuItemToggle::createWithTarget(this, menu_selector(CharacterSelect::MenuCharacterCallback), characterOne, selectedCharacterOne, NULL);
	m_charOne_Wrapper->setTag(1);

	// Create the character two
	characterTwo = CCMenuItemImage::create("CharacterIcons/CharacterTwo.png", "CharacterIcons/selectCharacterTwo.png");
	selectedCharacterTwo = CCMenuItemImage::create("CharacterIcons/selectCharacterTwo.png", "CharacterIcons/CharacterTwo.png");
	m_charTwo_Wrapper = CCMenuItemToggle::createWithTarget(this, menu_selector(CharacterSelect::MenuCharacterCallback), characterTwo, selectedCharacterTwo, NULL);
	m_charTwo_Wrapper->setTag(2);

	// Create the character three
	characterThree = CCMenuItemImage::create("CharacterIcons/CharacterThree.png", "CharacterIcons/selectCharacterThree.png");
	selectedCharacterThree = CCMenuItemImage::create("CharacterIcons/selectCharacterThree.png", "CharacterIcons/CharacterThree.png");
	m_charThree_Wrapper = CCMenuItemToggle::createWithTarget(this, menu_selector(CharacterSelect::MenuCharacterCallback), characterThree, selectedCharacterThree, NULL);
	m_charThree_Wrapper->setTag(3);

	// Set their positions relative to the screen size, I used 8 as it gave the most buffer room, we can add a third easily
	m_charOne_Wrapper->setPosition( ccp(size.width / 8, CCDirector::sharedDirector()->getWinSize().height / 2));
	m_charTwo_Wrapper->setPosition( ccp((size.width / 8) * 4 + 10, CCDirector::sharedDirector()->getWinSize().height / 2));
	m_charThree_Wrapper->setPosition( ccp((size.width / 8) * 7 + 10, CCDirector::sharedDirector()->getWinSize().height / 2));


    // create menu, adding in all the MenuItems
	characterMenu = CCMenu::create(continueItem, backItem, m_charOne_Wrapper, m_charTwo_Wrapper, m_charThree_Wrapper, NULL);
	characterMenu->setPosition(CCPointZero);
    this->addChild(characterMenu, 1);

    // add a label that shows "Main Menu" on the center of the screen
    label = CCLabelTTF::create("Select the left character!", "Thonburi", 34);
    label->setPosition( ccp(size.width / 2, size.height - 20) );
    this->addChild(label, 1);

    // Set the local variables to class members to store them for later
    m_label = label;
    m_characterMenu = characterMenu;

    return true;
}

void CharacterSelect::LoadCharacters()
{

}

// a selector callback
void CharacterSelect::MenuBackCallback(CCObject* sender)
{
	if(m_currentSelectedChar != NO_CHAR_SELECT)
		m_itemImage->setSelectedIndex(0);
	EnableMenu(true);
	// Go back to the main menu
	switch(m_numCharacters)
	{
	case 0:
    	CCDirector::sharedDirector()->replaceScene(MainMenu::Scene());
    	break;
	case 1:
		--m_numCharacters;
		m_currentSelectedChar = NO_CHAR_SELECT;
		m_label->setString("Select the left character!");
		break;
	case 2:
		--m_numCharacters;
		m_currentSelectedChar = NO_CHAR_SELECT;
		m_label->setString("Select the right character!");
		break;
	default:
		break;
	}
}

void CharacterSelect::MenuContinueCallback(CCObject* sender)
{
	if(m_numCharacters >= 2)
	{
		CCDirector::sharedDirector()->replaceScene(MusicSelect::Scene());
	}
	else if(m_currentSelectedChar != NO_CHAR_SELECT)
	{
		switch(m_numCharacters)
			{
			case 0:
				++m_numCharacters;
				Player_One = m_currentSelectedChar;
				m_currentSelectedChar = NO_CHAR_SELECT;
				m_label->setString("Select the right character!");
				break;
			case 1:
				++m_numCharacters;
				Player_Two = m_currentSelectedChar;
				m_currentSelectedChar = NO_CHAR_SELECT;
				m_label->setString("Hit continue to select music!");
				break;
			default:
				break;
			}
		m_itemImage->setSelectedIndex(0);
		if(m_numCharacters < 2)
			EnableMenu(true);
		else
			EnableMenu(false);
	}

}

// Call back for character selection
void CharacterSelect::MenuCharacterCallback(CCObject* sender)
{
	// Convert the object that called this to a CCMenuItemImage (SHOULD ALWAYS BE CCMENUITEMIMAGE)
	if(m_numCharacters < 2)
	{
		m_itemImage = (CCMenuItemToggle *)sender;

		if(m_currentSelectedChar == NO_CHAR_SELECT)
		{
			m_currentSelectedChar = m_itemImage->getTag();
			DisableMenu();
		}
		else
		{
			m_currentSelectedChar = NO_CHAR_SELECT;
			EnableMenu(true);
		}
	}
}


void CharacterSelect::DisableMenu(void)
{
	switch(m_itemImage->getTag())
	{
	case 1:
		m_charTwo_Wrapper->setEnabled(false);
		m_charThree_Wrapper->setEnabled(false);
		break;
	case 2:
		m_charOne_Wrapper->setEnabled(false);
		m_charThree_Wrapper->setEnabled(false);
		break;
	case 3:
		m_charTwo_Wrapper->setEnabled(false);
		m_charOne_Wrapper->setEnabled(false);
		break;
	default:
		break;
	}
}

void CharacterSelect::EnableMenu(bool val)
{
	m_charOne_Wrapper->setEnabled(val);
	m_charTwo_Wrapper->setEnabled(val);
	m_charThree_Wrapper->setEnabled(val);
}
