#include "CharacterSelectScene.h"

using namespace cocos2d;
using namespace CocosDenshion;

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
    CCMenuItemFont*  closeItem;					// Goes back to the previous scene
    CCLabelTTF*      label;						// The label to display current status
    CCMenuItemImage* characterOne;				// Character One for the select screen
    CCMenuItemImage* characterTwo;				// Character Two for the select screen

    // Super init, MUST DO
    if(!CCLayer::init())
    {
        return false;
    }

    // Set whether it is single player or not
    global.isSinglePlayer = true;

    // Initialize number of characters to 0
    m_numCharacters = 0;

    // get the window size from the director
    size = CCDirector::sharedDirector()->getWinSize();

    // add a "close" icon to exit the process
    closeItem = CCMenuItemFont::create("Back",  this,
                                           menu_selector(CharacterSelect::MenuCloseCallback));
    closeItem->setPosition(ccp(size.width / 2, 20));

	// Create the character menu items and load them into memory, set their tags
	characterOne = CCMenuItemImage::create("CharacterIcons/CharacterOne.png", "CharacterIcons/selectCharacterOne.png", this,
			menu_selector(CharacterSelect::MenuCharacterCallback));
	characterOne->setTag(1);
	characterTwo = CCMenuItemImage::create("CharacterIcons/CharacterTwo.png", "CharacterIcons/selectCharacterTwo.png", this,
			menu_selector(CharacterSelect::MenuCharacterCallback));
	characterTwo->setTag(2);

	// Set their positions relative to the screen size, I used 8 as it gave the most buffer room, we can add a third easily
	characterOne->setPosition( ccp(size.width / 8, CCDirector::sharedDirector()->getWinSize().height / 2));
	characterTwo->setPosition( ccp((size.width / 8) * 4 + 10, CCDirector::sharedDirector()->getWinSize().height / 2));

    // create menu, adding in all the MenuItems
    m_characterMenu = CCMenu::create(closeItem, characterOne, characterTwo, NULL);
    m_characterMenu->setPosition(CCPointZero);
    this->addChild(m_characterMenu, 1);

    // add a label that shows "Main Menu" on the center of the screen
    label = CCLabelTTF::create("Select your character!", "Thonburi", 34);
    label->setPosition( ccp(size.width / 2, size.height - 20) );
    this->addChild(label, 1);

    return true;
}

void CharacterSelect::LoadCharacters()
{

}

// a selector callback
void CharacterSelect::MenuCloseCallback(CCObject* sender)
{
	// Go back to the main menu
    CCDirector::sharedDirector()->replaceScene(MainMenu::Scene());
}

// Call back for character selection
void CharacterSelect::MenuCharacterCallback(CCObject* sender)
{
	// Increment the number of characters selected
	++m_numCharacters;
	// Convert the object that called this to a CCMenuItemImage (SHOULD ALWAYS BE CCMENUITEMIMAGE)
	CCMenuItemImage* convert = (CCMenuItemImage *)sender;

	// If we got one character, set the index to the tag, otherwise, we selected character two
	if(m_numCharacters == 1)
	{
		global.playerOne = convert->getTag();
	}
	else if(m_numCharacters == 2)
	{
		global.playerTwo = convert->getTag();
	}

	// Will move onto music library scene once we get that inplace
	if(m_numCharacters >= 2)
	{
	    CCDirector::sharedDirector()->replaceScene(MusicSelect::Scene());
	}
}
