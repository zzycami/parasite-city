#pragma once
#include "cocos2d.h"
#include "PhysicalSprite.h"
#include "Box2D\Box2D.h"

using namespace cocos2d;
using namespace std;

const string SteelBoxFilename = "steel_box.png";

class SteelBoxSprite:public PhysicalSprite
{
public:
	SteelBoxSprite();
	~SteelBoxSprite();
	CREATE_FUNC(SteelBoxSprite);

	// overrider
	virtual bool init();
	virtual b2Body* getBody(b2World *world);
	virtual void setFixture(b2Body *body);

	CC_SYNTHESIZE(string, shiftEffect, ShiftEffect);
};