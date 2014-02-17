#pragma once
#include "cocos2d.h"
#include "WelcomeLayer.h"

using namespace cocos2d;

class WelcomeScene:public Scene
{
public:
	WelcomeScene();
	~WelcomeScene();
	static vector<resource> getResourceList();
	CREATE_FUNC(WelcomeScene);
	virtual bool init();
private:
	WelcomeLayer *welcomeLayer;
};