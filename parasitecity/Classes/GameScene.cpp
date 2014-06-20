//
//  GameScene.cpp
//  parasitecity
//
//  Created by damingdan on 14-6-20.
//
//

#include "GameScene.h"


bool GameScene::init() {
    if (Scene::initWithPhysics()) {
        return true;
    }else {
        return false;
    }
}

void GameScene::initPhysicsBoundary() {
    auto body = PhysicsBody::create();
}