#pragma once
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;
using namespace CocosDenshion;

const float MenuRightMargin = 40;
const float MenuTopMargin = 60;
const float MenuGapMargin = 15;

class WelcomeLayer: public Layer
{
public:
	WelcomeLayer();
	~WelcomeLayer();
	CREATE_FUNC(WelcomeLayer);
	virtual bool init();
    virtual void onEnter();
    virtual void onExit();
    void menuNewGameCallBack(Object *sender);
    void menuStage1CallBack(Object *sender);
    void menuStage2CallBack(Object *sender);
    void menuStage3CallBack(Object *sender);
    void menuExitCallBack(Object *sender);
    void menuOmakeCallBack(Object *sender);
    void menuGalleryCallBack(Object *sender);
private:
    void initMenu();
    ControlSlider* initVolumeSlider();
    void volumeChange(Object *sender, Control::EventType eventType);
    float volume;
};