//
//  SewerStartLayer.h
//  parasite-city
//
//  Created by damingdan on 14-2-11.
//
//

#pragma once
#include "cocos2d.h"
#include "HeroSprite.h"
#include "OptionLayer.h"
#include "Common.h"

using namespace cocos2d;

const Point SteelBox1Position = Point(211, 26);
const Point SteelBox2Position = Point(321, 365);
const Size SceneSize = Size(1404, 804);
const int GroundBottomHeight = 25;

const int PlatformTag = 100;
const int SteelBoxTag = 102;
const int HeroTag = 104;

class SewerStartLayer:public Layer, public OptionDelegate
{
public:
    SewerStartLayer();
    ~SewerStartLayer();
    virtual bool init();
    CREATE_FUNC(SewerStartLayer);

	void onWalk(Point direction, float distance);
	void onStop();
    
	void setPhyWorld(PhysicsWorld* world){this->world = world;}

private:
    Sprite *steelBox1;
    Sprite *steelBox2;
    PhysicsWorld *world;
    Sprite *platform1;
    Sprite *platform2;
	ActionSprite *hero;
	int heroVelocity;

	void initHero();
    void initStaticObjects();
	void initDynamicObjects();
	bool onContactBegin(EventCustom* event, const PhysicsContact& contact);
	void initPhysicsBoundary();
};