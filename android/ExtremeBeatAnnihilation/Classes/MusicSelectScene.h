#ifndef __MUSIC_SELECT_SCENE_H__
#define __MUSIC_SELECT_SCENE_H__

#include <jni.h>
#include "platform/android/jni/JniHelper.h"

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

#include "LoadScene.h"
#include "CharacterSelectScene.h"

#define POS_HEADER_HEIGHT    0.9                 // factor of height to position the header
#define FONT_COLOR           ccc3(255, 255, 255) // RGB color of the menu items
#define MENU_PADDING         10                  // padding between menu items, most likely in pixels
#define MENU_POS_HEIGHT      0.45                // factor of screen height to position the menu

#define FIRST_SONG           "Music/LettingGo.mp3"
#define SECOND_SONG          "Music/TheCallOfStars.mp3"
#define THIRD_SONG           "Music/Waiting.mp3"

class MusicSelect : public cocos2d::CCLayer
{
public:
    virtual bool              init();
    static  cocos2d::CCScene* Scene();

    void HandleFirstSongPressed(CCObject* sender);
    void HandleSecondSongPressed(CCObject* sender);
    void HandleThirdSongPressed(CCObject* sender);
    void HandleYourMusicPressed(CCObject* sender);
    void HandlePlayPressed(CCObject* sender);
    void HandleBackPressed(CCObject* sender);

    // allows use of create() function which uses init() to create this layer
    CREATE_FUNC(MusicSelect);

private:
    cocos2d::CCLabelTTF*      m_header;        // the header font that tells the user what to do
    cocos2d::CCMenuItemLabel* m_itemPlay;      // menu item for starting the game scene

    bool m_haveJniData;                        // true when all the JNI data has been retrieved
    bool m_songSelected;                       // true when a song has been selected, false when not
    bool m_choseUserMusic;                     // true if the user selected from their own music,
                                               //   false if sample songs

    JNIEnv*   m_env;                           // pointer to the JNI environment of m_jvm
    jclass    m_extBeatAnniClass;              // the ExtremeBeatAnnihilation activity class
    jobject   m_extBeatAnniInstance;           // currently running instance of ExtremeBeatAnnihilation
    jmethodID m_startupFileExploreMethod;      // ID of the startupFileExplore method
    jmethodID m_getSelectedSongMethod;         // ID of the getSelectedSong method
};

#endif // __MUSIC_SELECT_SCENE_H__
