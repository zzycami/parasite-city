//
//  Box.h
//  parasite-city
//
//  Created by damingdan on 14-2-11.
//
//

#pragma once

#include "cocos2d.h"
#include "Box2D/Box2D.h"
using namespace cocos2d;

#define PTM_RATIO 32

class Box:public Sprite
{
public:
    Box();
    ~Box();
    virtual bool init();
    CREATE_FUNC(Box);
    
protected:
    void setShiftSpeed(const float shiftSpeed);
    void setShiftEffect(const std::string &shiftEffect);
    
private:
    float shiftSpeed;
    std::string shiftEffect;
};