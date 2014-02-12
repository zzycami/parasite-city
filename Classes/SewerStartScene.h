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
    
    // override
    void onTouchesBegan(const std::vector<Touch*>& touches, Event *event);
    void onTouchesMoved(const std::vector<Touch*>& touches, Event *event);
    void onTouchesEnded(const std::vector<Touch*>& touches, Event *event);
private:
    Layer *backgroundLayer;
    SewerStartLayer *sewerStartLayer;
};