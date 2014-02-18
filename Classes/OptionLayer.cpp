//
//  OptionLayer.cpp
//  parasite-city
//
//  Created by damingdan on 14-2-18.
//
//

#include "OptionLayer.h"



OptionLayer::OptionLayer()
{}

OptionLayer::~OptionLayer()
{}

bool OptionLayer::init()
{
	if(Layer::init()){
		//this->delegator = new OptionDelegate();
		this->initJoystick();
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

void OptionLayer::initJoystick()
{
	this->joystick = Sprite::create("joystick.png");
	this->joystickBg = Sprite::create("joystick_bg.png");
	this->addChild(this->joystick);
	this->addChild(this->joystickBg);
	this->inactiveJoystick();
}

void OptionLayer::activeJoystick(Point position)
{
	this->joystick->setPosition(position);
	this->joystickBg->setPosition(position);
	this->joystick->setVisible(true);
	this->joystickBg->setVisible(true);
}

void OptionLayer::inactiveJoystick()
{
	this->joystick->setPosition(this->joystickBg->getPosition());
	this->joystick->setVisible(false);
	this->joystickBg->setVisible(false);
}

void OptionLayer::updateJoystick(Point direction, float distance)
{
	Point start = this->joystickBg->getPosition();
	if (distance < JoystickRadius){
		this->joystick->setPosition(start + (direction*distance));
	}else if(distance > (JoystickBgRadius + JoystickRadius)){
		this->joystick->setPosition(start + (direction*JoystickBgRadius));
	}else {
		this->joystick->setPosition(start + (direction*JoystickRadius));
	}
}

void OptionLayer::onTouchesBegan(const std::vector<Touch*>& touches, Event *event)
{
	Size winSize = Director::getInstance()->getWinSize();
	for (auto touch : touches){
		Point position = touch->getLocation();
        
        if (position.x <= winSize.width / 2) {
			// left
			this->activeJoystick(position);
        } else {
            // right
        }
	}
}

void OptionLayer::onTouchesMoved(const std::vector<Touch*>& touches, Event *event)
{
	Size winSize = Director::getInstance()->getWinSize();
    Touch *t = touches[0];
    Point start = t->getStartLocation();
    if (start.x > winSize.width / 2) {
        return;
    }

    Point p = t->getLocation();
    float distance = start.getDistance(p);
    Point direction = (p - start).normalize();
	this->updateJoystick(direction, distance);

	this->delegator->onWalk(direction, distance);
}

void OptionLayer::onTouchesEnded(const std::vector<Touch*>& touches, Event *event)
{
	this->inactiveJoystick();
	this->delegator->onStop();
}

