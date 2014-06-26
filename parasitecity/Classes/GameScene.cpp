//
//  GameScene.cpp
//  parasitecity
//
//  Created by damingdan on 14-6-20.
//
//

#include "GameScene.h"
#include "HeroCharacter.h"


bool GameScene::init() {
    if (Scene::initWithPhysics()) {
        this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
        auto hero = HeroCharacter::getInstance();
        hero->setPosition(100, 150);
        hero->idle(DIRECTION_RIGHT);
        hero->configurePhysicsBody();
        this->addChild(hero);
        
        this->initPhysicsBoundary();
        this->initDynamicObjects();
        
        this->optionLayer = OptionLayer::create();
        if(this->optionLayer) {
            this->optionLayer->setDelegator(this);
            this->addChild(optionLayer);
        }
        
        // dispatch contact listener
        auto contactListener = EventListenerPhysicsContact::create();
        contactListener->onContactBegin = CC_CALLBACK_1(GameScene::onContactBegin, this);
        contactListener->onContactSeperate = CC_CALLBACK_1(GameScene::onContactSeperate, this);
        this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
        
        return true;
    }else {
        return false;
    }
}


bool GameScene::onContactBegin(cocos2d::PhysicsContact &contact) {
    HeroCharacter* hero;
    auto shapeA = contact.getShapeA();
    auto shapeB = contact.getShapeB();
    
    if(shapeA->getTag() == ShapeTagPush && shapeB->getTag() == ShapeTagBox) {
        hero = (HeroCharacter*) shapeA->getBody()->getNode();
        hero->push((Sprite*)shapeB->getBody()->getNode());
    } else if(shapeA->getTag() == ShapeTagPush && shapeB->getTag() == ShapeTagBox) {
        hero = (HeroCharacter*) shapeB->getBody()->getNode();
        hero->push((Sprite*)shapeA->getBody()->getNode());
    }
    return true;
}

void GameScene::onContactSeperate(cocos2d::PhysicsContact &contact) {
}

void GameScene::onWalk(Direction direction) {
    HeroCharacter::getInstance()->walk(direction);
}

Point GameScene::getReferencePoint() {
    return HeroCharacter::getInstance()->getPosition();
}

void GameScene::onJump() {
}

void GameScene::onSquat() {
}

void GameScene::onStop() {
    HeroCharacter::getInstance()->idle(HeroCharacter::getInstance()->getCurrentDirection());
}

void GameScene::initPhysicsBoundary() {
    // create the physics bundary
    auto body = PhysicsBody::create();
    body->addShape(PhysicsShapeEdgeSegment::create(Point(453, GroundBottomHeight), Point(0, GroundBottomHeight)));
    body->addShape(PhysicsShapeEdgeSegment::create(Point(SceneSize.width, GroundBottomHeight), Point(533, GroundBottomHeight)));
    body->addShape(PhysicsShapeEdgeSegment::create(Point(0, GroundBottomHeight), Point(0, SceneSize.height)));
    body->addShape(PhysicsShapeEdgeSegment::create(Point(0, SceneSize.height), Point(SceneSize.width, SceneSize.height)));
    body->addShape(PhysicsShapeEdgeSegment::create(Point(SceneSize.width, SceneSize.height), Point(SceneSize.width, GroundBottomHeight)));
    body->setDynamic(false);
    body->setCategoryBitmask(ColliderTypeWall);
    
    auto edgeNode = Node::create();
    edgeNode->setPosition(Point::ZERO);
    edgeNode->setPhysicsBody(body);
    this->addChild(edgeNode);
}

void GameScene::initDynamicObjects(){
    steelBox = Sprite::create("steel_box.png");
    steelBox->setPosition(SteelBox1Position.x + steelBox->getContentSize().width/2, SteelBox1Position.y + steelBox->getContentSize().height/2);
    
    auto steelShape = PhysicsShapeBox::create(steelBox->getContentSize(), PhysicsMaterial(7850.0f, 0, 0));
    steelShape->setTag(ShapeTagBox);
    auto steelBoxBody = PhysicsBody::create();
    steelBoxBody->addShape(steelShape);
    
    steelBoxBody->setDynamic(true);
    steelBoxBody->setRotationEnable(false);
    steelBoxBody->setCategoryBitmask(ColliderTypeBox);
    steelBoxBody->setContactTestBitmask(ColliderTypeHero);
    steelBox->setPhysicsBody(steelBoxBody);
    steelBox->setTag(Tag::TagBox);
    this->addChild(steelBox);
}
