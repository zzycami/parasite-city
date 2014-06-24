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

const int JoystickBgRadius = 64;
const int JoystickRadius = 32;

typedef enum _direction {
    DIRECTION_UP = 0,
    DIRECTION_DOWN = 1,
    DIRECTION_LEFT = 2,
    DIRECTION_RIGHT = 3
} Direction;

class OptionDelegate {
public:
    virtual void onWalk(Direction direction) = 0;
    virtual void onStop() = 0;
    virtual void onJump() = 0;
    virtual void onSquat() = 0;
    virtual Point getReferencePoint() = 0;
};

class OptionLayer:public Layer {
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
};