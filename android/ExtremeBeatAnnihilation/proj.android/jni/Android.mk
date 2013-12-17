LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := game_shared

LOCAL_MODULE_FILENAME := libgame

LOCAL_SRC_FILES := maincpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/IntroScene.cpp \
                   ../../Classes/MainMenuScene.cpp \
                   ../../Classes/CharacterSelectScene.cpp \
                   ../../Classes/MusicSelectScene.cpp \
                   ../../Classes/EndGameScene.cpp \
				   ../../Classes/PlayerR.cpp \
				   ../../Classes/PlayerL.cpp \
				   ../../Classes/UILayer.cpp \
                   ../../Classes/GameScene.cpp \
                   ../../Classes/BackgroundRLayer.cpp \
                   ../../Classes/BackgroundLLayer.cpp \
                   ../../Classes/ForegroundRLayer.cpp \
                   ../../Classes/ForegroundLLayer.cpp \
                   ../../Classes/PauseScene.cpp \
                   ../../Classes/OptionsMenuScene.cpp \
                   ../../Classes/ClipNode.cpp \
                   ../../Classes/LoadScene.cpp \
                   ../../Classes/Obstacle.cpp \
                   ../../Classes/SoundEvent.cpp \
                   ../../Classes/LevelData.cpp \
                   ../../Classes/Global.cpp
                   
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes                   

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static cocosdenshion_static cocos_extension_static
            
include $(BUILD_SHARED_LIBRARY)

$(call import-module,CocosDenshion/android) \
$(call import-module,cocos2dx) \
$(call import-module,extensions)
