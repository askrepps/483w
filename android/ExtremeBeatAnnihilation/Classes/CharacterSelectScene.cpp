#include "CharacterSelectScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* CharacterSelect::scene()
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
    CCSize           size;
    CCMenuItemImage* closeItem;
    CCLabelTTF*      label;

    if(!CCLayer::init())
    {
        return false;
    }

    // Set whether it is single player or not
    isSinglePlayer = true;

    // get the window size from the director
    size = CCDirector::sharedDirector()->getWinSize();

    // add a "close" icon to exit the process
    closeItem = CCMenuItemImage::create("CloseNormal.png", "CloseSelected.png", this,
                                           menu_selector(CharacterSelect::MenuCloseCallback));
    closeItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    // create menu
    m_characterMenu = CCMenu::create(closeItem, NULL);
    m_characterMenu->setPosition(CCPointZero);
    this->addChild(m_characterMenu, 1);

    // add a label that shows "Main Menu" on the center of the screen
    label = CCLabelTTF::create("Select your character!", "Thonburi", 34);
    label->setPosition( ccp(size.width / 2, size.height - 20) );
    this->addChild(label, 1);

    return true;
}

void CharacterSelect::LoadCharacters(const char* charDirectory)
{
	CCMenuItemImage* characterOne;				// Character One for the select screen
	CCMenuItemImage* characterTwo;				// Character Two for the select screen


	// Create the character menu items
	characterOne = CCMenuItemImage::create("CharacterIcons/CharacterOne.png", "CharacterIcons/selectCharacterOne.png", this,
			menu_selector(CharacterSelect::MenuCharacterCallback));
	characterOne = CCMenuItemImage::create("CharacterIcons/CharacterTwo.png", "CharacterIcons/selectCharacterTwo.png", this,
			menu_selector(CharacterSelect::MenuCharacterCallback));

	// Set their positions
	characterOne->setPosition( ccp(20, CCDirector::sharedDirector()->getWinSize().height - 40));
	characterTwo->setPosition( ccp(20 + 400, CCDirector::sharedDirector()->getWinSize().height - 40));
}

// a selector callback
void CharacterSelect::MenuCloseCallback(CCObject* sender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


void CharacterSelect::MenuCharacterCallback(CCObject* sender)
{

}
