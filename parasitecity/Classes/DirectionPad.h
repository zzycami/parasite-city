//
//  DirectionPad.h
//  parasitecity
//
//  Created by damingdan on 14/6/30.
//
//
#pragma once
#include "cocos2d.h"
#include "OptionLayer.h"

using namespace cocos2d;

class DirectionPad : public Sprite{
    virtual bool init();
    
    Sprite* getDirectionButton(Direction direction);
    
    CC_SYNTHESIZE(float, radius, Radius);
    CREATE_FUNC(DirectionPad);
private:
    RepeatForever* createButtonPath(Direction direction);
    
    ParticleSystem* createParticleLine();
    
    Sprite* createButton(Direction direction);
    
    Sprite* buttonTop;
    Sprite* buttonLeft;
    Sprite* buttonRight;
    Sprite* buttonBottom;
};