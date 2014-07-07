//
//  SneakyButton.cpp
//  parasitecity
//
//  Created by damingdan on 14/7/7.
//
//

#include <SneakyButton.h>

using namespace cocos2d;

void SneakyButton::onEnterTransitionDidFinish() {
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(SneakyButton::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(SneakyButton::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(SneakyButton::onTouchEnded, this);
    listener->onTouchCancelled = CC_CALLBACK_2(SneakyButton::onTouchCancelled, this);
    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

bool SneakyButton::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event) {
    if (active) {
        return false;
    }
    
    Point location = touch->getLocation();
    location = this->convertToNodeSpace(location);
    if (location.x < -radius || location.x > radius || location.y < -radius || location.y > radius) {
        return false;
    } else {
        float dsq = location.x*location.x + location.y*location.y;
        if (radiusSq > dsq) {
            active = true;
            if (!isHoldable && !isToggleable) {
                value = 1;
                this->schedule(schedule_selector(SneakyButton::limiter), rateLimit);
            }
            if (isHoldable) {
                value = 1;
            }
            if (isToggleable) {
                value = !value;
            }
        }
    }
    return false;
}

void SneakyButton::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event) {
    if(!active) return;
    
    Point location = touch->getLocation();
    location = this->convertToNodeSpace(location);
    location = this->convertToNodeSpace(location);
    if (location.x < -radius || location.x > radius || location.y < -radius || location.y > radius) {
        return ;
    } else {
        float dSq = location.x*location.x + location.y*location.y;
        if(radiusSq > dSq){
            if (isHoldable) value = 1;
        } else {
            if (isHoldable) value = 0;
            active = false;
        }
    }
}

void SneakyButton::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event) {
    if (!active) return;
    if (isHoldable) value = 0;
    if (isHoldable||isToggleable) active = false;
}

void SneakyButton::onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *event) {
    this->onTouchEnded(touch, event);
}

bool SneakyButton::initWithRect(cocos2d::Rect rect) {
    if (Node::init()) {
        bounds = Rect(0, 0, rect.size.width, rect.size.height);
        center = Point(rect.size.width/2, rect.size.height/2);
        status = 1; // defaults to enabled
        active = false;
        value = 0;
        isHoldable = 0;
        isToggleable = 0;
        radius = 32.0f;
        rateLimit = 1.0f/120.0f;
        
        this->setPosition(rect.origin);
        return true;
    }else {
        return false;
    }
}

void SneakyButton::limiter(float delta) {
    value = 0;
    this->unschedule(schedule_selector(SneakyButton::limiter));
    active = false;
}

void SneakyButton::setRadius(float r) {
    radius = r;
    radiusSq = r*r;
}