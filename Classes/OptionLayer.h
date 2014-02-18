//
//  OptionLayer.h
//  parasite-city
//
//  Created by damingdan on 14-2-18.
//
//

#pragma once
#include "cocos2d.h"
using namespace cocos2d;

class OptionDelegate
{
public:
    virtual void onWalk(Point direction, float distance) = 0;
    virtual void onStop() = 0;
};

class OptionLayer:public Layer
{
public:
    OptionLayer();
    ~OptionLayer();
    
    virtual bool init();
    CREATE_FUNC(OptionLayer);
    
    // override
    void onTouchesBegan(const std::vector<Touch*>& touches, Event *event);
    void onTouchesMoved(const std::vector<Touch*>& touches, Event *event);
    void onTouchesEnded(const std::vector<Touch*>& touches, Event *event);
    
    CC_SYNTHESIZE(OptionDelegate*, delegator, Delegator);
    
private:
    Sprite *joystick;
    Sprite *joystickBg;
    
    void activeJoystick(Point position);
    void inactiveJoystick();
    void updateJoystick(Point direction, float distance);
};