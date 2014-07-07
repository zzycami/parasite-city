//
//  SneakyButton.h
//  parasitecity
//
//  Created by damingdan on 14/7/7.
//
//

#pragma once
#include "cocos2d.h"
using namespace cocos2d;

class SneakyButton : public Node {
protected:
    Point center;
    float radiusSq;
    
    Rect bounds;
    
    CC_SYNTHESIZE(bool, status, Status);
    CC_SYNTHESIZE_READONLY(bool, active, IsActive);
    CC_SYNTHESIZE_READONLY(bool, value, Value);
    CC_SYNTHESIZE(bool, isHoldable, IsHoldable);
    CC_SYNTHESIZE(bool, isToggleable, IsToggleable);
    CC_SYNTHESIZE(float, rateLimit, RateLimit);
    
    CC_SYNTHESIZE_READONLY(float, radius, Radius);
    
    // public method
    virtual void onEnterTransitionDidFinish();
    bool initWithRect(Rect rect);
    void limiter(float delta);
    void setRadius(float r);
    
    virtual bool onTouchBegan(Touch *touch, Event *event);
    virtual void onTouchMoved(Touch *touch, Event *event);
    virtual void onTouchEnded(Touch *touch, Event *event);
    virtual void onTouchCancelled(Touch *touch, Event *event);
};