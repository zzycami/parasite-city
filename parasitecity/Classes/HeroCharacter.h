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


const PhysicsMaterial HeroPhysicsMaterial = PhysicsMaterial(10000.0f, 0.0f, 0.0f);


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
    void push(Sprite* target);
    void climb(Sprite* target);
    void squat();
    void update(float dt);
    
    // single instance
    static HeroCharacter* getInstance();
    CC_SYNTHESIZE(Direction, currentDirection, CurrentDirection);
    
private:
    static HeroCharacter* sharedHeroSprite;
    float walkSpeed;
    float pushSpeed;
    void move(float speed, float dt);
};