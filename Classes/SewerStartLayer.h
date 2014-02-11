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

using namespace cocos2d;
#define PTM_RATIO 32

const Point SteelBox1Position = Point(211, 25);
const Point SteelBox2Position = Point(321, 365);

class SewerStartLayer:public Layer
{
public:
    SewerStartLayer();
    ~SewerStartLayer();
    virtual bool init();
    CREATE_FUNC(SewerStartLayer);
private:
    Sprite *steelBox1;
    Sprite *steelBox2;
    b2World *world;
    b2Body *groundBody;
};