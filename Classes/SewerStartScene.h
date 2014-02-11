//
//  SewerStartScene.h
//  parasite-city
//
//  Created by damingdan on 14-2-11.
//
//

#pragma once
#include "cocos2d.h"
#include "SewerStartLayer.h"

using namespace cocos2d;

class SewerStartScene: public Scene
{
public:
    SewerStartScene();
    ~SewerStartScene();
    virtual bool init();
    CREATE_FUNC(SewerStartScene);
private:
    Layer *backgroundLayer;
    SewerStartLayer *sewerStartLayer;
};