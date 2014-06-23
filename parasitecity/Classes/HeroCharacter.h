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
    
    // Override
    void configurePhysicsBody();
    void idle(Direction direction);
    void walk(Direction direction);
    void attack(Direction direction);
    void hurt();
    void knockout();
    void squatwalk(Direction direction);
    void push(Direction direction);
    
    // single instance
    static HeroCharacter* getInstance();
    CC_SYNTHESIZE(Direction, currentDirection, CurrentDirection);
    
private:
    static HeroCharacter* sharedHeroSprite;
};