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
#include "SneakyJoystick.h"
#include "SneakyJoystickSkinnedBase.h"


OptionLayer::OptionLayer() {}

OptionLayer::~OptionLayer() {
    this->joystick->autorelease();
}

bool OptionLayer::init() {
	if(Layer::init()){
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile("UI.plist");
        
        Size winSize = Director::getInstance()->getWinSize();
        float joystickRadius = 150;
        this->joystick = SneakyJoystick::createWithRect(Rect::ZERO);
        joystick->setAutoCenter(true);
        joystick->setHasDeadzone(true);
        joystick->setDeadRadius(10);
        
        SneakyJoystickSkinnedBase *joystickSkin= SneakyJoystickSkinnedBase::create();
        joystickSkin->setBackgroundSprite(Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("JoyStick-base.png")));
        joystickSkin->setThumbSprite(Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("JoyStick-thumb.png")));
        joystickSkin->getThumbSprite()->setScale(1.0f);
        joystickSkin->setPosition(Point(joystickRadius, joystickRadius));
        joystickSkin->setJoystick(joystick);
        
        this->scheduleUpdate();
        this->addChild(joystickSkin);
        
		return true;
	}else {
		return false;
	}
}

void OptionLayer::update(float dt) {
    Point position = this->joystick->getVelocity()*50;
    
    if ((position.x  >  0)  && (position.x - position.y) >0 && (position.x + position.y) > 0) {
        // right
        this->getDelegator()->onWalk(DIRECTION_RIGHT);
    } else if((position.x < 0)  && (position.x + position.y) < 0 &&(position.x - position.y) < 0) {
        //left
        this->getDelegator()->onWalk(DIRECTION_LEFT);
    } else if((position.y > 0) &&(position.y - position.x) > 0 &&(position.y + position.x) >0) {
        // up
        this->getDelegator()->onJump();
    } else if((position.y < 0) &&(position.y - position.x) < 0 && (position.y + position.x) < 0) {
        // down
        this->getDelegator()->onSquat();
    }
}
