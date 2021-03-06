//
//  Character.h
//  parasitecity
//
//  Created by damingdan on 14-6-19.
//
//

#pragma once
#include "cocos2d.h"
#include "OptionLayer.h"

using namespace std;
using namespace cocos2d;



/**
 The Character state, include the hero and Enemy
 */
typedef enum : int{
    ACTION_STATE_IDLE = 0, // The default state
    ACTION_STATE_WALK, // The character move
    ACTION_STATE_ATTACK, // The character attack
    ACTION_STATE_HURT, // The character get hurt
    ACTION_STATE_KNOCKOUT, // The character is down
	ACTION_STATE_SQUATWALK, // The character is squat walk
	ACTION_STATE_PUSH, //The character is pushing
    ACTION_STATE_CLIMB,
    ACTION_STATE_SQUAT
} ActionState;

/* Bitmask for the different entities with physics bodies. */
typedef enum : uint8_t {
    ColliderTypeHero             = 0x1,
    ColliderTypeGoblinOrBoss     = 0x1<<1,
    ColliderTypeBox              = 0x1<<2,
    ColliderTypeWall             = 0x1<<3,
    ColliderTypeCave             = 0x1<<4
} ColliderType;

typedef enum : int {
    TagBox = 1,
    TagHero = 2
}Tag;

typedef enum : int {
    ShapeTagPush = 1,
    ShapeTagBody = 2,
    ShapeTagBox = 3
}ShapeTag;

class Character:public Sprite {
public:
    Character();
    ~Character();
    
    // Orientation, Movement, and Attacking.
    void idle(Direction direction);
    void walk(Direction direction);
    void attack(Direction direction);
    void hurt();
    void knockout();
	void squatwalk(Direction direction);
	void push(Sprite* target);
    void climb(Sprite* target);
    void squat(Direction direction);
    
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
    CC_SYNTHESIZE_RETAIN(Action*, squatAction, SquatAction);
    CC_SYNTHESIZE_RETAIN(FiniteTimeAction*, climbAction, ClimbAction);
    
    CC_SYNTHESIZE(ActionState, currentState, ActionState);
    CC_SYNTHESIZE(float, health, Health);
    
    CREATE_FUNC(Character);
    
protected:
    static cocos2d::Animation *createAnimation(const char *fmt, int count, float fps);
    static Animation *createAnimation(const char *fmt, int count, float fps, int start);
    bool changeState(ActionState state);
};