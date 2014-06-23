//
//  Character.cpp
//  parasitecity
//
//  Created by damingdan on 14-6-19.
//
//

#include "Character.h"


Character::Character()
{
    idleAction = NULL;
    walkAction = NULL;
    hurtAction = NULL;
    knockoutAction = NULL;
    attackAction = NULL;
	squatwalkAction = NULL;
	pushAction = NULL;
}

Character::~Character()
{}

bool Character::init() {
    if(Sprite::init()) {
        return true;
    }else {
        return false;
    }
}

bool Character::changeState(ActionState state)
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

void Character::idle(Direction direction)
{
    if (changeState(ACTION_STATE_IDLE)) {
        this->runAction(idleAction);
    }
}

void Character::push(Direction direction)
{
	if(changeState(ACTION_STATE_PUSH)) {
		this->runAction(pushAction);
	}
}

void Character::walk(Direction direction)
{
    if (changeState(ACTION_STATE_WALK)) {
        this->runAction(walkAction);
    }
}


void Character::attack(Direction direction)
{
    if (changeState(ACTION_STATE_ATTACK)) {
        this->runAction(attackAction);
    }
}

void Character::hurt()
{
    if (changeState(ACTION_STATE_HURT)) {
        this->runAction(hurtAction);
    }
}

void Character::knockout()
{
    if (changeState(ACTION_STATE_KNOCKOUT)) {
        this->runAction(knockoutAction);
    }
}

void Character::squatwalk(Direction direction)
{
	if(changeState(ACTION_STATE_SQUATWALK)) {
		this->runAction(squatwalkAction);
	}
}

void Character::configurePhysicsBody() {
    // Overridden by subclasses to create a physics body with relevant collision settings for this character.
}

Animation* Character::createAnimation(const char *fmt, int count, float fps)
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