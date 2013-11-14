#ifndef __CHARACTER_SELECT_SCENE_H__
#define __CHARACTER_SELECT_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "MainMenuScene.h"
#include "MusicSelectScene.h"
#include "Global.h"

class CharacterSelect : public cocos2d::CCLayer
{
public:
    virtual bool init();

    // there's no 'id' for android cocos2d, so we recommend to returning the exact class pointer
    static cocos2d::CCScene* Scene();

    // a selector callback
    void MenuCloseCallback(CCObject* pSender);

	// a selector callback for character selection
	void MenuCharacterCallback(CCObject* pSender);

	// Probe the character image location and get the number of characters
	int GetNumberOfCharacters(const char* charDirectory);

	// Load the characters into memory
	void LoadCharacters();

	// Arrange the characters into their proper location
	void ArrangeCharacterLocations(void);


    // implement the "static node()" method manually
    CREATE_FUNC(CharacterSelect);
private:
	//std::vector<CCMenuItemImage>* m_characterSelectionImages;
	int m_numCharacters;
	cocos2d::CCMenu* m_characterMenu;
	bool m_isSinglePlayer;
	Global global;
};

#endif // __CHARACTER_SELECT_SCENE_H__
