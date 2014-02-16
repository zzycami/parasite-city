LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                  ../../Classes/AppDelegate.cpp \
                  ../../Classes/HelloWorldScene.cpp \
				  ../../Classes/ActionSprite.cpp \
				  ../../Classes/GLES-Render.cpp \
				  ../../Classes/HeroSprite.cpp \
				  ../../Classes/PhysicalSprite.cpp \
				  ../../Classes/SewerStartLayer.cpp \
				  ../../Classes/SewerStartScene.cpp \
				  ../../Classes/WelcomeLayer.cpp \
				  ../../Classes/WelcomeScene.cpp \
				  ../../Classes/LoadingScene.cpp \

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static


include $(BUILD_SHARED_LIBRARY)

$(call import-module,2d)
$(call import-module,audio/android)
$(call import-module,Box2D)
$(call import-module,extensions)
