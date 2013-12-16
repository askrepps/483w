#ifndef __INTRO_SCENE_H__
#define __INTRO_SCENE_H__

#include "cocos2d.h"

#include "MainMenuScene.h"

#define LOGO_IMAGE      "CrashCourseLogo.png"     // the development group logo
#define LOGO_BACKGROUND "LogoBackgound.png"       // the background of the logo

class IntroScene : public cocos2d::CCLayer
{
public:
    virtual bool init();
    virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);

    static cocos2d::CCScene* Scene();

    // allows use of create() function which uses init() to create this layer
    CREATE_FUNC(IntroScene);
};

#endif // __INTRO_SCENE_H__
