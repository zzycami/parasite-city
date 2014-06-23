//
//  OptionLayer.cpp
//  parasite-city
//
//  Created by damingdan on 14-2-18.
//
//

#include "OptionLayer.h"
#include <math.h>



OptionLayer::OptionLayer() {}

OptionLayer::~OptionLayer() {}

bool OptionLayer::init() {
	if(Layer::init()){
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
        auto angle = CC_RADIANS_TO_DEGREES(deltaAngle.getAngle());
        if ((angle > -180 && angle < -135) || (angle > 135 && angle <= 180)) {
            this->delegator->onWalk(Direction::DIRECTION_RIGHT);
        }else if(angle >= -135 && angle <= -45) {
            this->delegator->onWalk(Direction::DIRECTION_UP);
            this->delegator->onJump();
        }else if(angle > -45 && angle <= 45) {
            this->delegator->onWalk(Direction::DIRECTION_LEFT);
        }else if(angle > 45 && angle <= 135) {
            this->delegator->onWalk(Direction::DIRECTION_DOWN);
            this->delegator->onSquat();
        }
    }
}

void OptionLayer::onTouchesMoved(const std::vector<Touch*>& touches, Event *event) {

}

void OptionLayer::onTouchesEnded(const std::vector<Touch*>& touches, Event *event) {
	this->delegator->onStop();
}
