#pragma once
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "extensions/cocos-ext.h"
#include "LoadingLayer.h"

using namespace cocos2d;
using namespace cocos2d::extension;
using namespace CocosDenshion;
using namespace std;

const float MenuRightMargin = 40;
const float MenuTopMargin = 70;
const float MenuGapMargin = 20;

const int MenuTagStart = 100;
const int MenuTagStage1 = 101;
const int MenuTagStage2 = 102;
const int MenuTagStage3 = 103;
const int MenuTagOmake = 104;
const int MenuTagGallery = 105;
const int MenuTagExit = 106;

class WelcomeLayer: public Layer
{
public:
	WelcomeLayer();
	~WelcomeLayer();
	CREATE_FUNC(WelcomeLayer);
	virtual bool init();
    virtual void onEnter();
    virtual void onExit();
    void menuNewGameCallBack();
    void menuStage1CallBack();
    void menuStage2CallBack();
    void menuStage3CallBack();
    void menuExitCallBack();
    void menuOmakeCallBack();
    void menuGalleryCallBack();
    void startNextScene();
private:
    void initMenu();
    ControlSlider* initVolumeSlider();
    void volumeChange(Object *sender, Control::EventType eventType);
	void menuItemSelectedAnimate(Object *sender);
    float volume;
};