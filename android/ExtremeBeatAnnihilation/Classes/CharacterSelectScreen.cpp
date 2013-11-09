#include "CharacterSelectScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* CharacterSelect::Scene()
{
    CCScene*  scene = CCScene::create();
    MainMenu* layer = MainMenu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool CharacterSelect::Init(cocos2d:CCScene* callingScene, bool singlePlayer)
{
    CCSize           size;
    CCMenuItemImage* closeItem;
    CCLabelTTF*      label;
    CCSprite*        sprite;

    if(!CCLayer::init())
    {
        return false;
    }

    // Set whether it is single player or not
    isSinglePlayer = singlePlayer;

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
    label = CCLabelTTF::create("Main Menu", "Thonburi", 34);
    label->setPosition( ccp(size.width / 2, size.height - 20) );
    this->addChild(Label, 1);

    // add splash screen as a sprite on the center of the screen
    sprite = CCSprite::create("splashscreen.jpg");
    sprite->setPosition( ccp(size.width / 2, size.height / 2) );
    this->addChild(sprite, 0);

    return true;
}

void CharacterSelect::LoadCharacters(const char* charDirectory)
{
	CCMenuItemImage* characterOne;				// Character One for the select screen
	CCMenuItemImage* characterTwo;				// Character Two for the select screen


	// Create the character menu items
	characterOne = CCMenuItemImage::create("CharacterOne.png", "selectCharacterOne.png", this, menu_selector(CharacterSelect::MenuCharacterCallBack));
	characterOne = CCMenuItemImage::create("CharacterTwo.png", "selectCharacterTwo.png", this, menu_selector(CharacterSelect::MenuCharacterCallBack));

	// Set their positions
	//characterOne->setPosition( ccp())
}

// a selector callback
void CharacterSelect::MenuCloseCallback(CCObject &sender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


void CharacterSelect::CharacterCallBack(CCObject &sender)
{

}
