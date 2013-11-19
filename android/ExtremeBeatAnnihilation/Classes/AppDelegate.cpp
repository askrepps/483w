#include "AppDelegate.h"

USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());

    // start up the menu song
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic(MENU_MUSIC, true);

    // turn on fps for testing
    //pDirector->setDisplayStats(true);
    //pDirector->setAnimationInterval(1.0 / 60);

    // start up the main menu as the first scene
    CCScene* pScene = MainMenu::Scene();
    pDirector->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive, or when a phone call comes in.
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->pause();

    // pause background music
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->resume();

    // resume background music
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
