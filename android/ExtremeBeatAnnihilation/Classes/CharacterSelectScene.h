#ifndef __CHARACTER_SELECT_SCENE_H__
#define __CHARACTER_SELECT_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "MainMenuScene.h"
#include "MusicSelectScene.h"
#include "Global.h"
#include <cstdarg>

class CharacterSelect : public cocos2d::CCLayer
{
public:
    virtual bool init();

    // there's no 'id' for android cocos2d, so we recommend to returning the exact class pointer
    static cocos2d::CCScene* Scene();

    // a selector callback
    void MenuBackCallback(CCObject* pSender);

    void MenuContinueCallback(CCObject* pSender);

	// a selector callback for character selection
	void MenuCharacterCallback(CCObject* pSender);

	// Probe the character image location and get the number of characters
	int GetNumberOfCharacters(const char* charDirectory);

	// Load the characters into memory
	void LoadCharacters();

	// allows use of create() function which uses init() to create this layer
    CREATE_FUNC(CharacterSelect);

private:
    void DisableMenu(void);
    void EnableMenu(bool val);
	int                        m_numCharacters;         // The number of characters selected
	int                        m_currentSelectedChar;   // The current selected character
	cocos2d::CCMenuItemToggle* m_itemImage;             // The image for enabling on continue and such.
	cocos2d::CCLabelTTF*       m_label;                 // The label to display current status
	cocos2d::CCMenu*           m_characterMenu;         // The menu
	cocos2d::CCMenuItemToggle* m_charOne_Wrapper;
	cocos2d::CCMenuItemToggle* m_charTwo_Wrapper;
	cocos2d::CCMenuItemToggle* m_charThree_Wrapper;
};

#endif // __CHARACTER_SELECT_SCENE_H__
