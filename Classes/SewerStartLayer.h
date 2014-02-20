//
//  SewerStartLayer.h
//  parasite-city
//
//  Created by damingdan on 14-2-11.
//
//

#pragma once
#include "cocos2d.h"
#include "GLES-Render.h"
#include "HeroSprite.h"
#include "OptionLayer.h"
#include "Common.h"

using namespace cocos2d;

const Point SteelBox1Position = Point(211, 26);
const Point SteelBox2Position = Point(321, 365);
const Size SceneSize = Size(1404, 804);
const int GroundBottomHeight = 25;

class SewerStartLayer:public Layer, public OptionDelegate
{
public:
    SewerStartLayer();
    ~SewerStartLayer();
    virtual bool init();
    CREATE_FUNC(SewerStartLayer);
    
    // override
    void onTouchesBegan(const std::vector<Touch*>& touches, Event *event);
    void onTouchesMoved(const std::vector<Touch*>& touches, Event *event);
    void onTouchesEnded(const std::vector<Touch*>& touches, Event *event);

	void onWalk(Point direction, float distance);
	void onStop();
    
    b2MouseJoint *mouseJoint;
private:
    GLESDebugDraw *debugDraw;
    Sprite *steelBox1;
    b2Body *steelBox1Body;
    Sprite *steelBox2;
    b2Body *steelBox2Body;
    b2World *world;
    b2Body *groundBody;
    Sprite *platform1;
    b2Body *platform1Body;
    Sprite *platform2;
    b2Body *platform2Body;
	ActionSprite *hero;
	b2Body *heroBody;
	int heroVelocity;
    
    
    
    void initBox2d();
	void initHero();
    void initStaticObjects();
    void tick(float dt);
    virtual void draw() override;
    void initDebugDraw();
};