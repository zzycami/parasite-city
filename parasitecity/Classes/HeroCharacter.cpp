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
        
        Animation *squat = this->createAnimation("squat%02d.png", 9, 5, 1);
        this->setSquatAction(RepeatForever::create(Animate::create(squat)));
        
        Animation *climb = this->createAnimation("climb%02d.png", 3, 3, 1);
        this->setClimbAction(Animate::create(climb));
        
        this->setCurrentDirection(DIRECTION_RIGHT);
        this->walkSpeed = 200;
        this->pushSpeed = 30;
        
        this->scheduleUpdate();
        return true;
    }else {
        return false;
    }
}

void HeroCharacter::configurePhysicsBody() {
    auto heroBody = PhysicsBody::create();
    auto shapeBody = PhysicsShapeBox::create(Size(68, 180), HeroPhysicsMaterial, Vec2(0, -35));
    shapeBody->setTag(ShapeTagBody);
    heroBody->addShape(shapeBody);
    
    auto shapePush = PhysicsShapeBox::create(Size(148, 40), HeroPhysicsMaterial, Vec2(0, -20));
    shapePush->setTag(ShapeTagPush);
    heroBody->addShape(shapePush);
	
    heroBody->setRotationEnable(false);
    heroBody->setCategoryBitmask(ColliderTypeHero);
    heroBody->setCollisionBitmask(ColliderTypeWall | ColliderTypeBox);
    heroBody->setContactTestBitmask(ColliderTypeBox);
    heroBody->setDynamic(false);
    this->setTag(Tag::TagHero);
	this->setPhysicsBody(heroBody);
}

void HeroCharacter::idle(Direction direction) {
    if(this->getActionState() == ACTION_STATE_PUSH || this->getActionState() == ACTION_STATE_SQUAT) {
        // if hero is push state, when the user stop walk, stop the push animation
        this->pause();
        this->setSpriteFrame(SpriteFrame::create("climb01.png", Rect(0, 0, 255, 255)));
        return;
    }
    Character::idle(direction);
}


void HeroCharacter::walk(Direction direction) {
    if (this->getPhysicsBody()->isDynamic()) {
        // When we want to set the hero's postion
        //this->getPhysicsBody()->setDynamic(false);
    }
    if (this->getActionState() == ACTION_STATE_PUSH) {
        this->resume();
        // if the next directon is not the push direction, change to walk state
        if (this->getCurrentDirection() == direction) {
            return;
        }
    }
    Character::walk(direction);
    if (direction == DIRECTION_RIGHT) {
        this->setFlippedX(false);
    }else {
        // If current direction is not the right direction, change it
        this->setFlippedX(true);
    }
    this->setCurrentDirection(direction);
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


void HeroCharacter::push(Sprite* target) {
    // check the position of the object
    Point targetPosition = target->getPosition();
    if (targetPosition.x - this->getPositionX() > 0) {
        // target is at the right of hero
        if(this->getCurrentDirection() == DIRECTION_RIGHT) {
            Character::push(target);
        }
    }else {
        // target is at the left of hero
        if(this->getCurrentDirection() == DIRECTION_LEFT) {
            Character::push(target);
        }
    }
    
}

void HeroCharacter::climb(cocos2d::Sprite *target) {
    if (this->getActionState() == ACTION_STATE_PUSH) {
        if(changeState(ACTION_STATE_CLIMB)) {
            auto actionDone = CallFunc::create(std::bind(&HeroCharacter::squat, this));
            auto sequence = Sequence::createWithTwoActions(this->getClimbAction(), actionDone);
            this->runAction(sequence);
        }
    }
}

void HeroCharacter::squat() {
    this->resume();
    Character::squat(this->getCurrentDirection());
}

void HeroCharacter::update(float dt) {
    if (this->getActionState() == ACTION_STATE_WALK) {
        this->move(this->walkSpeed, dt);
    }else if(this->getActionState() == ACTION_STATE_PUSH) {
        this->move(this->pushSpeed, dt);
    }
}

void HeroCharacter::move(float speed, float dt) {
    auto deltaDistance = (this->getCurrentDirection() == DIRECTION_LEFT?-1:1)*speed*dt;
    auto detalVect = Point(this->getPositionX() + deltaDistance, this->getPositionY());
    this->setPosition(detalVect);
}
