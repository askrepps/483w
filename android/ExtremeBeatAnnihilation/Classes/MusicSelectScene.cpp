#include "MusicSelectScene.h"

using namespace cocos2d;
using namespace CocosDenshion;

// externs defined in Global.h
extern std::string Game_Song;

// Initialize the menu items, background, and overall setup of the music selection menu
//
// return - false if there was an error in initializing, true otherwise
bool MusicSelect::init()
{
    CCLabelTTF*      labelFirstSong;    // the text for the first song menu item
    CCLabelTTF*      labelSecondSong;   // the text for the second song menu item
    CCLabelTTF*      labelThirdSong;    // the text for the third song menu item
    CCLabelTTF*      labelYourMusic;    // the text for your music menu item
    CCLabelTTF*      labelPlay;         // the text for play menu item
    CCLabelTTF*      labelBack;         // the text for back menu item
    CCMenuItemLabel* itemFirstSong;     // menu item for choosing the first song
    CCMenuItemLabel* itemSecondSong;    // menu item for choosing the second song
    CCMenuItemLabel* itemThirdSong;     // menu item for choosing the third song
    CCMenuItemLabel* itemYourMusic;     // menu item for opening your music selection
    CCMenuItemLabel* itemBack;          // menu item for going back to character select
    CCMenu*          menu;              // menu to contain the menu items
    CCSize           size;              // the size of the window

    if(!CCLayer::init())
    {
        return false;
    }

    // get the window size from the director
    size = CCDirector::sharedDirector()->getWinSize();

    // create the header for the scene
    m_header = CCLabelTTF::create("Choose a song", FONT_STYLE, FONT_SIZE);
    m_header->setPosition( ccp(size.width * POS_HALF_SCREEN, size.height * POS_HEADER_HEIGHT) );
    m_header->setColor(MENU_COLOR);
    this->addChild(m_header, 1);

    // create the text for the menu items
    labelFirstSong  = CCLabelTTF::create("Letting Go - UltraMax", FONT_STYLE, FONT_SIZE);
    labelSecondSong = CCLabelTTF::create("The Call of Stars - UltraMax", FONT_STYLE, FONT_SIZE);
    labelThirdSong  = CCLabelTTF::create("Need Song - Artist", FONT_STYLE, FONT_SIZE);
    labelYourMusic  = CCLabelTTF::create("Select from SD card", FONT_STYLE, FONT_SIZE);
    labelBack       = CCLabelTTF::create("Back", FONT_STYLE, FONT_SIZE);
    labelPlay       = CCLabelTTF::create("Play", FONT_STYLE, FONT_SIZE);

    // create the items for the menu
    itemFirstSong  = CCMenuItemLabel::create(labelFirstSong, this, menu_selector(MusicSelect::HandleFirstSongPressed));
    itemSecondSong = CCMenuItemLabel::create(labelSecondSong, this, menu_selector(MusicSelect::HandleSecondSongPressed));
    itemThirdSong  = CCMenuItemLabel::create(labelThirdSong, this, menu_selector(MusicSelect::HandleThirdSongPressed));
    itemYourMusic  = CCMenuItemLabel::create(labelYourMusic, this, menu_selector(MusicSelect::HandleYourMusicPressed));
    itemBack       = CCMenuItemLabel::create(labelBack, this, menu_selector(MusicSelect::HandleBackPressed));
    m_itemPlay     = CCMenuItemLabel::create(labelPlay, this, menu_selector(MusicSelect::HandlePlayPressed));

    // set the color of the menu items
    itemFirstSong->setColor(FONT_COLOR);
    itemSecondSong->setColor(FONT_COLOR);
    itemThirdSong->setColor(FONT_COLOR);
    itemYourMusic->setColor(FONT_COLOR);
    itemBack->setColor(FONT_COLOR);
    m_itemPlay->setColor(FONT_COLOR);

    // disable the play menu item, because user needs to pick a song first
    m_itemPlay->setVisible(false);
    m_itemPlay->setEnabled(false);

    // create menu to contain the menu items
    menu = CCMenu::create(itemFirstSong, itemSecondSong, itemThirdSong, itemYourMusic, m_itemPlay, itemBack, NULL);
    menu->alignItemsVerticallyWithPadding(MENU_PADDING);
    menu->setPosition(size.width * POS_HALF_SCREEN, size.height * MENU_POS_HEIGHT);
    this->addChild(menu, 1);

    // initialize the booleans
    m_choseUserMusic = false;
    m_haveJniData    = false;
    m_songSelected   = false;

    return true;
}

// Create a music select scene that has a MusicSelect layer
//
// return - a newly created music select scene
CCScene* MusicSelect::Scene()
{
    CCScene*     scene = CCScene::create();       // the music select scene to return
    MusicSelect* layer = MusicSelect::create();   // the layer for the scene

    scene->addChild(layer);

    return scene;
}

// On selecting the first song menu item, change the selected song to the first sample track
//
// sender [in] - the object that sent the selected event
void MusicSelect::HandleFirstSongPressed(CCObject* sender)
{
    SimpleAudioEngine::sharedEngine()->playEffect("SFX/select.wav");
    Game_Song = FIRST_SONG;

    // if song wasn't selected previously, set up the scene to start the game
    if (!m_songSelected)
    {
        m_header->setString("Song selected! Press Play or choose another!");
        m_itemPlay->setVisible(true);
        m_itemPlay->setEnabled(true);
        m_songSelected = true;
    }
}

// On selecting the second song menu item, change the selected song to the second sample track
//
// sender [in] - the object that sent the selected event
void MusicSelect::HandleSecondSongPressed(CCObject* sender)
{
    SimpleAudioEngine::sharedEngine()->playEffect("SFX/select.wav");
    Game_Song = SECOND_SONG;

    // if song wasn't selected previously, set up the scene to start the game
    if (!m_songSelected)
    {
        m_header->setString("Song selected! Press Play or choose another!");
        m_itemPlay->setVisible(true);
        m_itemPlay->setEnabled(true);
        m_songSelected = true;
    }
}

// On selecting the third song menu item, change the selected song to the third sample track
//
// sender [in] - the object that sent the selected event
void MusicSelect::HandleThirdSongPressed(CCObject* sender)
{
    SimpleAudioEngine::sharedEngine()->playEffect("SFX/select.wav");
    Game_Song = THIRD_SONG;

    // if song wasn't selected previously, set up the scene to start the game
    if (!m_songSelected)
    {
        m_header->setString("Song selected! Press Play or choose another!");
        m_itemPlay->setVisible(true);
        m_itemPlay->setEnabled(true);
        m_songSelected = true;
    }
}

// On selecting the your music menu item, start the file explore activity for the user to choose a song
//   on their SD card
//
// sender [in] - the object that sent the selected event?
void MusicSelect::HandleYourMusicPressed(CCObject* sender)
{
    jclass tmpClass;            // Prevent a stale local ref bug
    jobject tmpObject;          // Prevent a stale local ref bug

	SimpleAudioEngine::sharedEngine()->playEffect("SFX/select.wav");

	// if we haven't before, retrieve all the JNI data to be able to call java methods
    if (!m_haveJniData)
    {
        JavaVM* jvm = cocos2d::JniHelper::getJavaVM();
        if (NULL == jvm)
            CCLog("Failed to get the JavaVM");

        jint ret = jvm->GetEnv((void**)&m_env, JNI_VERSION_1_4);
        if (ret != JNI_OK)
            CCLog("Failed to get then JNIEnv");

        tmpClass = m_env->FindClass("org/cocos2dx/extbeatanni/ExtremeBeatAnnihilation");
        if (!tmpClass)
            CCLog("Failed to find class ExtremeBeatAnnihilation");
        m_extBeatAnniClass = (jclass)m_env->NewGlobalRef(tmpClass);

        jmethodID getObjectMethod = m_env->GetStaticMethodID(m_extBeatAnniClass, "getObject", "()Ljava/lang/Object;");
        if(!getObjectMethod)
            CCLog("Failed to find method getObject");

        tmpObject = m_env->CallStaticObjectMethod(m_extBeatAnniClass, getObjectMethod);
        if(!tmpObject)
            CCLog("Failed to get the current instance of the running activity");
        m_extBeatAnniInstance = (jobject)m_env->NewGlobalRef(tmpObject);

        m_startupFileExploreMethod = m_env->GetMethodID(m_extBeatAnniClass, "startupFileExplore", "()V");
        if (!m_startupFileExploreMethod)
            CCLog("Failed to find method startupFileExplore");

        m_getSelectedSongMethod = m_env->GetMethodID(m_extBeatAnniClass, "getSelectedSong", "()Ljava/lang/String;");
        if (!m_getSelectedSongMethod)
            CCLog("Failed to find method getSelectedSong");

        m_haveJniData = true;
    }

    // call the java method within the ExtremeBeatAnnihilation activity that will start up file explore
    m_env->CallNonvirtualVoidMethod(m_extBeatAnniInstance, m_extBeatAnniClass, m_startupFileExploreMethod);

    m_choseUserMusic = true;

    // if song wasn't selected previously, set up the scene to start the game
    if (!m_songSelected)
    {
        m_header->setString("Song selected! Press Play or choose another!");
        m_itemPlay->setVisible(true);
        m_itemPlay->setEnabled(true);
        m_songSelected = true;
    }
}

// On selecting the play menu item, get the selected song if user music was chosen, and switch to the
//   game scene
//
// sender [in] - the object that sent the selected event
void MusicSelect::HandlePlayPressed(CCObject* sender)
{
    SimpleAudioEngine::sharedEngine()->playEffect("SFX/select.wav");

    // if user chose from the SD card, get the selected song from the ExtremeBeatAnnihilation activity
    if (m_choseUserMusic)
    {
        // call the java method within the ExtremeBeatAnnihilation activity that will get the selected
        //   song
        jobject result = m_env->CallNonvirtualObjectMethod(m_extBeatAnniInstance, m_extBeatAnniClass, m_getSelectedSongMethod);
        if (!result)
            CCLog("Got a NULL back for the song selection");

        // convert the returned string to a C++ char* to that can be stored in Game_Song
        const char *charResult = m_env->GetStringUTFChars(jstring(result), NULL);
        Game_Song = charResult;

        // Be sure to set these up for garbage collection
        m_env->DeleteGlobalRef(m_extBeatAnniInstance);
        m_env->DeleteGlobalRef(m_extBeatAnniClass);

        m_choseUserMusic = false;
    }

    // stop the music and open the game scene
    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    CCDirector::sharedDirector()->replaceScene(LoadScene::Scene());
}

// On selecting the back menu item, switch back to character select scene
//
// sender [in] - the object that sent the selected event?
void MusicSelect::HandleBackPressed(CCObject* sender)
{
	SimpleAudioEngine::sharedEngine()->playEffect("SFX/back.wav");
    CCDirector::sharedDirector()->replaceScene(CharacterSelect::Scene());
}
