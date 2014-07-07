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

OptionLayer::~OptionLayer() {}

bool OptionLayer::init() {
	if(Layer::init()){
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile("UI.plist");
        
        Size winSize = Director::getInstance()->getWinSize();
        float joystickRadius = 220;
        auto joystick = new SneakyJoystick();
        joystick->autorelease();
        joystick->initWithRect(Rect::ZERO);
        joystick->setAutoCenter(true);
        joystick->setHasDeadzone(true);
        joystick->setDeadRadius(10);
        
        SneakyJoystickSkinnedBase *joystickSkin=new SneakyJoystickSkinnedBase();
        joystickSkin->autorelease();
        joystickSkin->init();
        //背景
        joystickSkin->setBackgroundSprite(Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("JoyStick-base.png")));
        //中心点
        joystickSkin->setThumbSprite(Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("JoyStick-thumb.png")));
        joystickSkin->getThumbSprite()->setScale(1.0f);
        joystickSkin->setPosition(Point(joystickRadius,joystickRadius));
        joystickSkin->setJoystick(joystick);
        
        this->addChild(joystickSkin);
        
		return true;
	}else {
		return false;
	}
}
