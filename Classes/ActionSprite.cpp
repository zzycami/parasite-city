//
//  ActionSprite.cpp
//  parasite-city
//
//  Created by damingdan on 14-2-13.
//
//

#include "ActionSprite.h"


ActionSprite::ActionSprite()
{
    idleAction = NULL;
    walkAction = NULL;
    hurtAction = NULL;
    knockoutAction = NULL;
    attackAction = NULL;
}

ActionSprite::~ActionSprite()
{}

bool ActionSprite::changeState(ActionState state)
{
    if(currentState == ACTION_STATE_KNOCKOUT){
        return false;
    }
    
    if (currentState == state) {
        return false;
    }
    
    this->stopAllActions();
    currentState = state;
    return true;
}

void ActionSprite::idle()
{
    if (changeState(ACTION_STATE_IDLE)) {
        this->runAction(idleAction);
        velocity = 0;
    }
}

void ActionSprite::walk(cocos2d::Point direction)
{
    if (changeState(ACTION_STATE_WALK)) {
        this->runAction(walkAction);
        this->direction = direction;
        this->direction.x > 0?this->setFlippedX(true):this->setFlippedX(false);
    }
}

void ActionSprite::attack()
{
    if (changeState(ACTION_STATE_ATTACK)) {
        this->runAction(attackAction);
        
    }
}

void ActionSprite::hurt(int damage)
{
    if (changeState(ACTION_STATE_HURT)) {
        this->runAction(hurtAction);
        this->hp -= damage;
        if (this->hp <= 0) {
            knockout();
        }
    }
}

void ActionSprite::knockout()
{
    if (changeState(ACTION_STATE_KNOCKOUT)) {
        this->runAction(knockoutAction);
    }
}

Animation* ActionSprite::createAnimation(const char *fmt, int count, float fps)
{
    Animation *animation = Animation::create();
    animation->setDelayPerUnit(1/fps);
}