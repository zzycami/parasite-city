//
//  Character.h
//  parasitecity
//
//  Created by damingdan on 14-6-19.
//
//

#pragma once
#include "cocos2d.h"

using namespace std;
using namespace cocos2d;

/**
 The Character state, include the hero and Enemy
 */
typedef enum{
    ACTION_STATE_IDLE = 0, // The default state
    ACTION_STATE_WALK, // The character move
    ACTION_STATE_ATTACK, // The character attack
    ACTION_STATE_HURT, // The character get hurt
    ACTION_STATE_KNOCKOUT, // The character is down
	ACTION_STATE_SQUATWALK, // The character is squat walk
	ACTION_STATE_PUSH //The character is pushing
} ActionState;

class Character:public Sprite {
public:
    Character();
    ~Character();
    
    // Orientation, Movement, and Attacking.
    void idle();
    void walk();
    void attack();
    void hurt();
    void knockout();
	void squatwalk();
	void push();
    
    // Physical
    void configurePhysicsBody();
    
    // Override
    virtual bool init();
    
    
    CC_SYNTHESIZE_RETAIN(Action*, idleAction, IdleAction);
    CC_SYNTHESIZE_RETAIN(Action*, attackAction, AttackAction);
    CC_SYNTHESIZE_RETAIN(Action*, hurtAction, HurtAction);
    CC_SYNTHESIZE_RETAIN(Action*, knockoutAction, KnockoutAction);
    CC_SYNTHESIZE_RETAIN(Action*, walkAction, WalkAction);
	CC_SYNTHESIZE_RETAIN(Action*, pushAction, PushAction);
	CC_SYNTHESIZE_RETAIN(Action*, squatwalkAction, SquatwalkAction);
    
    CC_SYNTHESIZE(ActionState, currentState, ActionState);
    CC_SYNTHESIZE(float, health, Health);
    
    CREATE_FUNC(Character);
    
protected:
    static cocos2d::Animation *createAnimation(const char *fmt, int count, float fps);
    
private:
    bool changeState(ActionState state);
};