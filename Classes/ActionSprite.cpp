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
	squatwalkAction = NULL;
	pushAction = NULL;
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
    }
}

void ActionSprite::push()
{
	if(changeState(ACTION_STATE_PUSH)) {
		this->runAction(pushAction);
	}
}

void ActionSprite::walk()
{
    if (changeState(ACTION_STATE_WALK)) {
        this->runAction(walkAction);
    }
}


void ActionSprite::attack()
{
    if (changeState(ACTION_STATE_ATTACK)) {
        this->runAction(attackAction);
        
    }
}

void ActionSprite::hurt()
{
    if (changeState(ACTION_STATE_HURT)) {
        this->runAction(hurtAction);
    }
}

void ActionSprite::knockout()
{
    if (changeState(ACTION_STATE_KNOCKOUT)) {
        this->runAction(knockoutAction);
    }
}

void ActionSprite::squatwalk()
{
	if(changeState(ACTION_STATE_SQUATWALK)) {
		this->runAction(squatwalkAction);
	}
}

Animation* ActionSprite::createAnimation(const char *fmt, int count, float fps)
{
    Animation *animation = Animation::create();
    animation->setDelayPerUnit(1/fps);
	for (int i = 0; i < count; i++){
		const char *filename = String::createWithFormat(fmt, i)->getCString();
		Texture2D *texture = Director::getInstance()->getTextureCache()->addImage(filename);
		texture->setAliasTexParameters();
		Rect frameRect = Rect(0, 0, texture->getContentSize().width, texture->getContentSize().height);
		SpriteFrame *frame = SpriteFrame::createWithTexture(texture, frameRect);
		animation->addSpriteFrame(frame);
	}
	return animation;
}