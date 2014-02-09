#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class WelcomeLayer: public Layer
{
public:
	WelcomeLayer();
	~WelcomeLayer();
	CREATE_FUNC(WelcomeLayer);
	virtual bool init();
};