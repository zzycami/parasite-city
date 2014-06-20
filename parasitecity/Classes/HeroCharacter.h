//
//  HeroCharacter.h
//  parasitecity
//
//  Created by damingdan on 14-6-19.
//
//

#pragma once
#include "cocos2d.h"
#include "Character.h"

using namespace cocos2d;


class HeroCharacter : public Character {
public:
    HeroCharacter();
    ~HeroCharacter();
    
    virtual bool init();
    CREATE_FUNC(HeroCharacter);
    
    // Override
    void configurePhysicsBody();
};