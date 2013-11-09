#ifndef __CHARACTER_SELECT_SCENE_H__
#define __CHARACTER_SELECT_SCENE_H__

#include "cocos2d.h"
#include <vector>

//#define CHARACTER_IMAGE_PATH "../Resources/CharacterImages"

class CharacterSelect : public cocos2d::CCLayer
{
public:
    virtual bool Init(cocos2d:CCScene* callingScene, bool singlePlayer);

    // there's no 'id' for android cocos2d, so we recommend to returning the exact class pointer
    static cocos2d::CCScene* Scene();

    // a selector callback
    void MenuCloseCallback(CCObject* pSender);

	// a selector callback for character selection
	int MenuCharacterCallback(CCObject* pSender);

	// Probe the character image location and get the number of characters
	int GetNumberOfCharacters(const char* charDirectory);

	// Load the characters into memory
	void LoadCharacters(const char* charDirectory);

	// Arrange the characters into their proper location
	void ArrangeCharacterLocations(void);


    // implement the "static node()" method manually
    CREATE_FUNC(CharacterSelect);
private:
	vector<CCMenuItemImage>* m_characterSelectionImages;
	int m_numCharacters;
	CCMenu* m_characterMenu;
	bool isSinglePlayer;
};

#endif // __CHARACTER_SELECT_SCENE_H__
