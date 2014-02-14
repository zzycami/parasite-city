//
//  ActionSprite.h
//  parasite-city
//
//  Created by damingdan on 14-2-13.
//
//

#pragma once
#include "cocos2d.h"
using namespace cocos2d;

typedef enum{
    ACTION_STATE_NONE = 0,
    ACTION_STATE_IDLE,
	ACTION_STATE_RUN,
    ACTION_STATE_WALK,
    ACTION_STATE_ATTACK,
    ACTION_STATE_HURT,
    ACTION_STATE_KNOCKOUT,
	ACTION_STATE_SQUATWALK,
} ActionState;

class ActionSprite:public Sprite
{
public:
    ActionSprite();
    ~ActionSprite();
    
    void idle();
    void walk();
    void attack();
    void hurt();
    void knockout();
	void squatwalk();
    
    CC_SYNTHESIZE_RETAIN(Action*, idleAction, IdleAction);
    CC_SYNTHESIZE_RETAIN(Action*, attackAction, AttackAction);
    CC_SYNTHESIZE_RETAIN(Action*, hurtAction, HurtAction);
    CC_SYNTHESIZE_RETAIN(Action*, knockoutAction, KnockoutAction);
    CC_SYNTHESIZE_RETAIN(Action*, walkAction, WalkAction);
	CC_SYNTHESIZE_RETAIN(Action*, squatwalkAction, SquatwalkAction);

    CC_SYNTHESIZE(ActionState, currentState, ActionState);

protected:
    static cocos2d::Animation *createAnimation(const char *fmt, int count, float fps);
    
private:
    bool changeState(ActionState state);
};