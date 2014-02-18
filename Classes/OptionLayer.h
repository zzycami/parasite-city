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
    virtual void onStop();
};

class OptionLayer:public Layer
{
public:
    OptionLayer();
    ~OptionLayer();
};