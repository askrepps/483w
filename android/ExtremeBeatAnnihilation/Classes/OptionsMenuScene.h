#ifndef __OPTIONS_MENU_SCENE_H__
#define __OPTIONS_MENU_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

#include "Global.h"

#include "CCControlSlider.h"
#include "MainMenuScene.h"

class OptionsMenu : public cocos2d::CCLayer
{
public:
    virtual bool init();

    // there's no 'id' for android cocos2d, so we recommend to returning the exact class pointer
    static cocos2d::CCScene* Scene();

    void HandleMusicSliderChanged(cocos2d::extension::CCControlSlider* slider);
    void HandleSfxSliderChanged(cocos2d::extension::CCControlSlider* slider);

    // a selector callback
    //void MenuCloseCallback(CCObject* pSender);
    void MenuGoBack(CCObject* sender);

    // allows use of create() function which uses init() to create this layer
    CREATE_FUNC(OptionsMenu);
};

#endif // __OPTIONS_MENU_SCENE_H__

