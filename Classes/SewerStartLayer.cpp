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

    //auto heroBody = PhysicsBody::createPolygon(IdlePoints, 12, HeroPhysicsMaterial, Point::ZERO);
	auto heroBody = PhysicsBody::createBox(hero->getContentSize(), HeroPhysicsMaterial);
	heroBody->setDynamic(true);
    heroBody->setRotationEnable(false);
	hero->setPhysicsBody(heroBody);
	hero->setTag(HeroTag);
	this->addChild(hero);
}

bool SewerStartLayer::init()
{
    if (Layer::init()) {
		initPhysicsBoundary();
		initHero();
        initStaticObjects();
		initDynamicObjects();
        
		auto contactListener = EventListenerPhysicsContact::create();
		contactListener->onContactBegin = CC_CALLBACK_2(SewerStartLayer::onContactBegin, this);
		this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

        return true;
    }else {
        return false;
    }
}

bool SewerStartLayer::onContactBegin(EventCustom* event, const PhysicsContact& contact)
{
	auto spriteA = (Sprite*)contact.getShapeA()->getBody()->getNode();
	auto spriteB = (Sprite*)contact.getShapeA()->getBody()->getNode();
	if((spriteA == spriteB) ||(spriteA->getTag() == spriteB->getTag())) {
		return true;
	}
	if((spriteA->getTag() == HeroTag && spriteB->getTag() == SteelBoxTag) || (spriteB->getTag() == HeroTag && spriteA->getTag() == SteelBoxTag)){
		this->hero->push();
	}
	return true;
}

void SewerStartLayer::initPhysicsBoundary()
{
	auto body = PhysicsBody::create();
	body->addShape(PhysicsShapeEdgeSegment::create(Point(453, GroundBottomHeight), Point(0, GroundBottomHeight)));
	body->addShape(PhysicsShapeEdgeSegment::create(Point(SceneSize.width, GroundBottomHeight), Point(533, GroundBottomHeight)));
	body->addShape(PhysicsShapeEdgeSegment::create(Point(0, GroundBottomHeight), Point(0, SceneSize.height)));
	body->addShape(PhysicsShapeEdgeSegment::create(Point(0, SceneSize.height), Point(SceneSize.width, SceneSize.height)));
	body->addShape(PhysicsShapeEdgeSegment::create(Point(SceneSize.width, SceneSize.height), Point(SceneSize.width, GroundBottomHeight)));
	body->setDynamic(false);
	auto edgeNode = Node::create();
	edgeNode->setPosition(Point::ZERO);
	edgeNode->setPhysicsBody(body);
	this->addChild(edgeNode);
}

void SewerStartLayer::initDynamicObjects()
{
	steelBox1 = Sprite::create("steel_box.png");
	steelBox1->setTag(SteelBoxTag);
	steelBox1->setPosition(SteelBox1Position.x + steelBox1->getContentSize().width/2, SteelBox1Position.y + steelBox1->getContentSize().height/2);
	auto steelBox1Body = PhysicsBody::createBox(steelBox1->getContentSize(), PhysicsMaterial(7850.0f, 0.5f, 10));
	steelBox1Body->setDynamic(true);
	steelBox1Body->setRotationEnable(false);
	steelBox1->setPhysicsBody(steelBox1Body);
    this->addChild(steelBox1);
    
        
    steelBox2 = Sprite::create("steel_box.png");
	steelBox2->setTag(SteelBoxTag);
	steelBox2->setPosition(SteelBox2Position.x + steelBox2->getContentSize().width/2, SteelBox2Position.y + steelBox2->getContentSize().height/2);
	auto steelBox2Body = PhysicsBody::createBox(steelBox2->getContentSize(), PhysicsMaterial(7850.0f, 0.5f, 10));
	steelBox2Body->setDynamic(true);
	steelBox2Body->setRotationEnable(false);
	steelBox2->setPhysicsBody(steelBox2Body);
    this->addChild(steelBox2);
}

void SewerStartLayer::initStaticObjects()
{
    const Point platform1Position = Point(415, 321);
    const Size platform1Size = Size(499, 112);
    
    const Point platform2Position = Point(1221, 201);
    const Size platform2Size = Size(302, 352);
    
    platform1 = Sprite::create();
	platform1->setTag(PlatformTag);
    platform1->setContentSize(platform1Size);
    platform1->setPosition(platform1Position);
	auto platform1Body = PhysicsBody::createEdgeBox(platform1Size);
	platform1Body->setDynamic(false);
	platform1->setPhysicsBody(platform1Body);
	this->addChild(platform1);
    
    
    platform2 = Sprite::create();
	platform2->setTag(PlatformTag);
    platform2->setContentSize(platform2Size);
    platform2->setPosition(platform2Position);
	auto platform2Body = PhysicsBody::createEdgeBox(platform2Size);
	platform2Body->setDynamic(false);
	platform2->setPhysicsBody(platform2Body);
    this->addChild(platform2);
}