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
        hero->setPosition(100, 100);
        hero->idle(DIRECTION_RIGHT);
        hero->configurePhysicsBody();
        this->addChild(hero);
        
        this->initPhysicsBoundary();
        
        this->optionLayer = OptionLayer::create();
        if(this->optionLayer) {
            this->optionLayer->setDelegator(this);
            this->addChild(optionLayer);
        }
        return true;
    }else {
        return false;
    }
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
    
    auto edgeNode = Node::create();
    edgeNode->setPosition(Point::ZERO);
    edgeNode->setPhysicsBody(body);
    this->addChild(edgeNode);
}