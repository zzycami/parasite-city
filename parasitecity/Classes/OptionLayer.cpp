//
//  OptionLayer.cpp
//  parasite-city
//
//  Created by damingdan on 14-2-18.
//
//

#include "OptionLayer.h"
#include "DirectionPad.h"
#include <math.h>



OptionLayer::OptionLayer() {}

OptionLayer::~OptionLayer() {}

bool OptionLayer::init() {
	if(Layer::init()){
        auto dPad = DirectionPad::create();
        dPad->setPosition(200, 200);
        this->addChild(dPad);
        
		auto dispatcher = Director::getInstance()->getEventDispatcher();
        auto listener = EventListenerTouchAllAtOnce::create();
        listener->onTouchesBegan = CC_CALLBACK_2(OptionLayer::onTouchesBegan, this);
        listener->onTouchesMoved = CC_CALLBACK_2(OptionLayer::onTouchesMoved, this);
        listener->onTouchesEnded = CC_CALLBACK_2(OptionLayer::onTouchesEnded, this);
        dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
		return true;
	}else {
		return false;
	}
}


void OptionLayer::onTouchesBegan(const std::vector<Touch*>& touches, Event *event) {
	Size winSize = Director::getInstance()->getWinSize();
	for (auto touch : touches){
		Point position = touch->getLocation();
        auto deltaAngle = this->delegator->getReferencePoint() - position;
        if (deltaAngle.x < 0 && deltaAngle.y < 0) {
            this->delegator->onWalk(Direction::DIRECTION_RIGHT);
        }else if(deltaAngle.x > 0 && deltaAngle.y < 0){
            this->delegator->onWalk(Direction::DIRECTION_LEFT);
        }else {
            this->delegator->onSquat();
        }
    }
}

void OptionLayer::onTouchesMoved(const std::vector<Touch*>& touches, Event *event) {

}

void OptionLayer::onTouchesEnded(const std::vector<Touch*>& touches, Event *event) {
    for (auto touch : touches){
        auto startLocation = touch->getStartLocation();
        auto endLocation = touch->getLocation();
        if(endLocation.y - startLocation.y  > 100) {
            this->delegator->onJump();
        }
    }
	this->delegator->onStop();
}
