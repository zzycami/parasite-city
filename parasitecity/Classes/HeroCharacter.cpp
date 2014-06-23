//
//  HeroCharacter.cpp
//  parasitecity
//
//  Created by damingdan on 14-6-19.
//
//

#include "HeroCharacter.h"

HeroCharacter*  HeroCharacter::sharedHeroSprite = nullptr;

HeroCharacter* HeroCharacter::getInstance() {
    if (sharedHeroSprite == nullptr) {
        sharedHeroSprite = new HeroCharacter();
        if (!sharedHeroSprite->init()) {
            delete sharedHeroSprite;
            sharedHeroSprite = NULL;
            CCLOG("ERROR: Could not init sharedHeroSprite");
        }
    }
    return sharedHeroSprite;
}

HeroCharacter::HeroCharacter() {
}

HeroCharacter::~HeroCharacter() {
}

bool HeroCharacter::init() {
    if (Character::initWithFile("hero_idle0.png")) {
        Animation *idle = this->createAnimation("hero_idle%d.png", 4, 3);
		this->setIdleAction(RepeatForever::create(Animate::create(idle)));
        
		Animation *walk = this->createAnimation("hero_run%02d.png", 8, 10);
		this->setWalkAction(RepeatForever::create(Animate::create(walk)));
        
		Animation *squatwalk = this->createAnimation("hero_squat_walk%02d.png", 8, 8);
		this->setSquatwalkAction(RepeatForever::create(Animate::create(squatwalk)));
        
		Animation *push = this->createAnimation("hero_push%02d.png",10, 5);
		this->setPushAction(RepeatForever::create(Animate::create(push)));
        
        this->setCurrentDirection(DIRECTION_LEFT);
        return true;
    }else {
        return false;
    }
}

void HeroCharacter::configurePhysicsBody() {
    auto heroBody = PhysicsBody::createBox(this->getContentSize());
	heroBody->setDynamic(true);
    heroBody->setRotationEnable(false);
	this->setPhysicsBody(heroBody);
}

void HeroCharacter::idle(Direction direction) {
    Character::idle(direction);
}


void HeroCharacter::walk(Direction direction) {
    Character::walk(direction);
    if (this->getCurrentDirection() != direction) {
        this->setFlippedX(false);
    }else {
        this->setFlippedX(true);
    }
}


void HeroCharacter::attack(Direction direction) {
    Character::attack(direction);
}


void HeroCharacter::hurt() {
    Character::hurt();
}


void HeroCharacter::knockout() {
    Character::knockout();
}


void HeroCharacter::squatwalk(Direction direction) {
    Character::squatwalk(direction);
}


void HeroCharacter::push(Direction direction) {
    Character::push(direction);
}