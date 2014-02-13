//
//  SewerStartLayer.h
//  parasite-city
//
//  Created by damingdan on 14-2-11.
//
//

#pragma once
#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "GLES-Render.h"
#include "HeroSprite.h"

using namespace cocos2d;
#define PTM_RATIO 32.0

const Point SteelBox1Position = Point(211, 26);
const Point SteelBox2Position = Point(321, 365);
const Size SceneSize = Size(1404, 804);
const int GroundBottomHeight = 25;

class SewerStartLayer:public Layer
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
    
    
    
    void initBox2d();
	void initHero();
    void initStaticObjects();
    void tick(float dt);
    virtual void draw() override;
    void initDebugDraw();
};