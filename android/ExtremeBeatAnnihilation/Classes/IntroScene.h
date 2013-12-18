#ifndef __INTRO_SCENE_H__
#define __INTRO_SCENE_H__

#include "cocos2d.h"

#include "Global.h"

#include "MainMenuScene.h"

#define POS_NOTE_HEIGHT   0.08                      // factor of screen height to position the note
#define POS_LOGO_HEIGHT   0.57                      // factor of screen height to position the logo
#define LOGO_IMAGE        "CrashCourseLogo.png"     // the development group logo
#define LOGO_BACKGROUND   "LogoBackgound.png"       // the background of the logo
#define LOGO_HEIGHT_SCALE 0.80                      // factor of screen height to scale the logo
#define INTRO_FONT_SIZE   50                        // size of the font
#define INTRO_FONT_COLOR  ccc3(0, 0, 0)             // RGB color of the font

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
