//
//  SewerStartScene.cpp
//  parasite-city
//
//  Created by damingdan on 14-2-11.
//
//

#include "SewerStartScene.h"

SewerStartScene::SewerStartScene()
{}

SewerStartScene::~SewerStartScene()
{}

bool SewerStartScene::init()
{
    if (Scene::init()) {
        backgroundLayer = Layer::create();
        if (backgroundLayer) {
            Sprite *background = Sprite::create("scene1_background.png");
            background->setAnchorPoint(Point(0, 0));
            background->setPosition(Point::ZERO);
            backgroundLayer->addChild(background);
            this->addChild(backgroundLayer);
        }
        sewerStartLayer = SewerStartLayer::create();
        if (sewerStartLayer) {
            this->addChild(sewerStartLayer);
        }
        
        auto dispatcher = Director::getInstance()->getEventDispatcher();
        auto listener = EventListenerTouchAllAtOnce::create();
        listener->onTouchesBegan = CC_CALLBACK_2(SewerStartScene::onTouchesBegan, this);
        listener->onTouchesMoved = CC_CALLBACK_2(SewerStartScene::onTouchesMoved, this);
        listener->onTouchesEnded = CC_CALLBACK_2(SewerStartScene::onTouchesEnded, this);
        dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
        
        return true;
    }else {
        return false;
    }
}

void SewerStartScene::onTouchesBegan(const std::vector<Touch*>& touches, Event *event)
{
}

void SewerStartScene::onTouchesMoved(const std::vector<Touch*>& touches, Event *event)
{
//    if (sewerStartLayer->mouseJoint == NULL) {
//        Touch *touch = touches[0];
//        Point location = touch->getLocationInView();
//        Point startLocation = touch->getStartLocationInView();
//        Point position = this->getPosition();
//        float shift = location.x - startLocation.x;
//        position.x -= shift/10;
//        this->setPosition(position);
//    }
}

void SewerStartScene::onTouchesEnded(const std::vector<Touch*>& touches, Event *event)
{
}