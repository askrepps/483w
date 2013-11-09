#include "CharacterSelectScene.h"
#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* CharacterSelect::Scene()
{
    CCScene*  scene = CCScene::create();
    CharacterSelect* layer = CharacterSelect::create();

    // add layer as a child to scene
    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool CharacterSelect::init()
{
    CCSize           size;						// The size of the screen
    CCMenuItemFont* closeItem;					// Goes back to the previous scene
    CCLabelTTF*      label;						// The label to display current status
    CCMenuItemImage* characterOne;				// Character One for the select screen
    CCMenuItemImage* characterTwo;				// Character Two for the select screen

    // Super init, MUST DO
    if(!CCLayer::init())
    {
        return false;
    }

    // Set whether it is single player or not
    m_isSinglePlayer = true;

    // Initialize number of characters to 0
    m_numCharacters = 0;

    // get the window size from the director
    size = CCDirector::sharedDirector()->getWinSize();


    // add a "close" icon to exit the process
    closeItem = CCMenuItemFont::create("Back",  this,
                                           menu_selector(CharacterSelect::MenuCloseCallback));
    closeItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 80, 20) );



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
    CCDirector::sharedDirector()->replaceScene(MainMenu::Scene());
}


void CharacterSelect::MenuCharacterCallback(CCObject* sender)
{
	++m_numCharacters;
	CCMenuItemImage* convert = (CCMenuItemImage *)sender;
	if(m_numCharacters == 1)
	{
		m_selectedCharOne = convert->getTag();
	}
	else if(m_numCharacters == 2)
	{
		m_selectedCharTwo = convert->getTag();
	}

	if(m_numCharacters >= 2)
	{

	}
}
