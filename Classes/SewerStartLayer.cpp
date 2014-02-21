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

void SewerStartLayer::onWalk(Point direction, float distance)
{
	this->hero->setFlippedX(direction.x<0?true:false);
	this->hero->walk();
	heroVelocity = direction.x<0?-150:150;
	this->hero->getPhysicsBody()->setVelocity(Vect(heroVelocity, 0));
    this->hero->getPhysicsBody()->removeAllShapes();
    this->hero->getPhysicsBody()->addShape(PhysicsShapePolygon);
}

void SewerStartLayer::onStop()
{
	this->hero->idle();
	this->hero->getPhysicsBody()->setVelocity(Vect::ZERO);
}

SewerStartLayer::~SewerStartLayer()
{
}

void SewerStartLayer::initHero()
{
	hero = HeroSprite::create();
	hero->setPosition(Point(200, hero->getContentSize().height/2));
	hero->idle();

    auto heroBody = PhysicsBody::createPolygon(IdlePoints, 12, HeroPhysicsMaterial, Point::ZERO);
	heroBody->setDynamic(true);
    heroBody->setRotationEnable(false);
	hero->setPhysicsBody(heroBody);
	this->addChild(hero);
}

bool SewerStartLayer::init()
{
    if (Layer::init()) {
		initPhysicsBoundary();
		initHero();
        initStaticObjects();
		initDynamicObjects();
        
        return true;
    }else {
        return false;
    }
}

void SewerStartLayer::initPhysicsBoundary()
{
	Point points[6] = {
		Point(453, GroundBottomHeight), 
		Point(0, GroundBottomHeight), 
		Point(0, SceneSize.height), 
		Point(SceneSize.width, SceneSize.height), 
		Point(SceneSize.width, GroundBottomHeight), 
		Point(533, GroundBottomHeight)};
	//auto body = PhysicsBody::createEdgePolygon(points, 6, PHYSICSBODY_MATERIAL_DEFAULT, 3);
	auto body = PhysicsBody::createEdgeBox(SceneSize, PHYSICSBODY_MATERIAL_DEFAULT, 3, Point::ZERO);
	body->setDynamic(false);
	auto edgeNode = Node::create();
	edgeNode->setPosition(SceneSize.width/2, SceneSize.height/2);
	edgeNode->setPhysicsBody(body);
	this->addChild(edgeNode);
}

void SewerStartLayer::initDynamicObjects()
{
	steelBox1 = Sprite::create("steel_box.png");
    steelBox1->setPosition(SteelBox1Position.x/2 + steelBox1->getContentSize().width/2, SteelBox1Position.y/2 + steelBox1->getContentSize().height/2);
	auto steelBox1Body = PhysicsBody::createBox(steelBox1->getContentSize(), PhysicsMaterial(7850.0f, 0.5f, 0.5f), Point::ZERO);
	steelBox1Body->setDynamic(true);
	steelBox1->setPhysicsBody(steelBox1Body);
    this->addChild(steelBox1);
    
        
    steelBox2 = Sprite::create("steel_box.png");
    steelBox2->setPosition(SteelBox2Position.x/2 + steelBox2->getContentSize().width/2, SteelBox2Position.y/2 + steelBox2->getContentSize().height/2);
	auto steelBox2Body = PhysicsBody::createBox(steelBox2->getContentSize(), PhysicsMaterial(7850.0f, 0.5f, 0.5f), Point::ZERO);
	steelBox2Body->setDynamic(true);
	steelBox2->setPhysicsBody(steelBox2Body);
    this->addChild(steelBox2);
}

void SewerStartLayer::initStaticObjects()
{
    const Point platform1Position = Point(415/2, 321/2);
    const Size platform1Size = Size(499, 112);
    
    const Point platform2Position = Point(1221/2, 201/2);
    const Size platform2Size = Size(302, 352);
    
    platform1 = Sprite::create();
	platform1->setTag(Platform1Tag);
    platform1->setContentSize(platform1Size);
    platform1->setPosition(platform1Position);
	auto platform1Body = PhysicsBody::createEdgeBox(platform1Size, PHYSICSBODY_MATERIAL_DEFAULT, 1, platform1Position);
	platform1Body->setDynamic(false);
	platform1->setPhysicsBody(platform1Body);
	this->addChild(platform1);
    
    
    platform2 = Sprite::create();
    platform2->setContentSize(platform2Size);
    platform2->setPosition(platform2Position);
	auto platform2Body = PhysicsBody::createEdgeBox(platform2Size, PHYSICSBODY_MATERIAL_DEFAULT, 1, platform2Position);
	platform2Body->setDynamic(false);
	platform2->setPhysicsBody(platform2Body);
    this->addChild(platform2);
}