#ifndef __CHARACTER_SELECT_SCENE_H__
#define __CHARACTER_SELECT_SCENE_H__

#include "cocos2d.h"
#include <vector>

#define CHARACTER_IMAGE_PATH "../Resources/CharacterImages"

class CharacterSelect : public cocos2d::CCLayer
{
public:
    virtual bool init(cocos2d:CCScene* callingScene);

    // there's no 'id' for android cocos2d, so we recommend to returning the exact class pointer
    static cocos2d::CCScene* scene();

    // a selector callback
    void menuCloseCallback(CCObject* pSender);

	// a selector callback for character selection
	int menuCharacterCallback(CCObject* pSender);

	// Probe the character image location and get the number of characters
	int getNumberOfCharacters(const char* charDirectory);

	// Load the characters into memory
	void loadCharacters(const char* charDirectory);

	// Arrange the characters into their proper location
	void arrangeCharacterLocations(void);


    // implement the "static node()" method manually
    CREATE_FUNC(CharacterSelect);
private:
	vector<CCMenuItemImage>* m_characterSelectionImages;
	int m_numCharacters;
	CCMenu* m_characterMenu;
};

#endif // __CHARACTER_SELECT_SCENE_H__
