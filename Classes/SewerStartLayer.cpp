//
//  SewerStartLayer.cpp
//  parasite-city
//
//  Created by damingdan on 14-2-11.
//
//

#include "SewerStartLayer.h"

SewerStartLayer::SewerStartLayer()
{
    steelBox1 = NULL;
    steelBox2 = NULL;
}


SewerStartLayer::~SewerStartLayer()
{}

bool SewerStartLayer::init()
{
    // init box2d world
    b2Vec2 gravity(0.0f, -10.0f);
    world = new b2World(gravity);
    
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0, 0);
    groundBody = world->CreateBody(&groundBodyDef);
    
    // ground box shape
    b2PolygonShape groundBox;
    
    
    if (Layer::init()) {
        steelBox1 = Sprite::create("steel_box.png");
        steelBox1->setAnchorPoint(Point::ZERO);
        steelBox1->setPosition(SteelBox1Position);
        this->addChild(steelBox1);
        
        steelBox2 = Sprite::create("steel_box.png");
        steelBox2->setAnchorPoint(Point::ZERO);
        steelBox2->setPosition(SteelBox2Position);
        this->addChild(steelBox2);
        return true;
    }else {
        return false;
    }
}