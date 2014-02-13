#pragma once
#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "Common.h"

using namespace cocos2d;

class PhysicalSprite:public Sprite
{
public:
	PhysicalSprite();
	~PhysicalSprite();

	/*virtual b2Body* getBody(b2World *world);
	virtual void setFixture(b2Body *body);*/

	CREATE_FUNC(PhysicalSprite);

	// override
	virtual bool init();
};
