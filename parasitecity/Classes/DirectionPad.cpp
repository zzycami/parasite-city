//
//  DirectionPad.cpp
//  parasitecity
//
//  Created by damingdan on 14/6/30.
//
//

#include "DirectionPad.h"
#include <math.h>
#define CoefficientConstant (sqrt(2) - 1)
#define DefaultRadius 10.0f

bool DirectionPad::init() {
    if (Sprite::init()) {
        this->setRadius(DefaultRadius);
        this->buttonTop = this->createButton(DIRECTION_UP);
        this->addChild(this->buttonTop);

        this->buttonBottom = this->createButton(DIRECTION_DOWN);
        this->addChild(this->buttonBottom);
        
        this->buttonRight = this->createButton(DIRECTION_RIGHT);
        this->addChild(this->buttonRight);
        
        this->buttonLeft = this->createButton(DIRECTION_LEFT);
        this->addChild(this->buttonLeft);
        
        return true;
    } else {
        return false;
    }
}

Sprite* DirectionPad::createButton(Direction direction) {
    auto button = Sprite::create();
    auto line = this->createParticleLine();
    line->runAction(this->createButtonPath(direction));
    button->addChild(line);
    return button;
}

Sprite* DirectionPad::getDirectionButton(Direction direction) {
    switch (direction) {
        case DIRECTION_LEFT:
            return this->buttonLeft;
            break;
        case DIRECTION_DOWN:
            return this->buttonBottom;
            break;
        case DIRECTION_RIGHT:
            return this->buttonRight;
            break;
        case DIRECTION_UP:
            return this->buttonTop;
            break;
        default:
            break;
    }
}

RepeatForever* DirectionPad::createButtonPath(Direction direction) {
    ccBezierConfig bezierConfig;
    float duration = 0.8;
    float x = this->getPositionX();
    float y = this->getPositionY();
    MoveBy* move1 = nullptr;
    MoveBy* move2 = nullptr;
    BezierBy* bezierBy = nullptr;
    
    if (direction == DIRECTION_UP) {
        bezierConfig.controlPoint_1 = Vec2(x - this->getRadius(), y + CoefficientConstant*this->getRadius());
        bezierConfig.controlPoint_2 = Vec2(x + this->getRadius(), y + CoefficientConstant*this->getRadius());
        bezierConfig.endPosition = Vec2(x + this->getRadius(), y + sqrt(2)*this->getRadius());
        bezierBy = BezierBy::create(0.8f, bezierConfig);
        move1 = MoveBy::create(duration, Vec2(x, y + sqrt(3)*this->getRadius()));
        move2 = MoveBy::create(duration, Vec2(x - this->getRadius(), y + sqrt(2)*this->getRadius()));
    } else if(direction == DIRECTION_DOWN) {
        bezierConfig.controlPoint_1 = Vec2(x - this->getRadius(), y - CoefficientConstant*this->getRadius());
        bezierConfig.controlPoint_2 = Vec2(x + this->getRadius(), y - CoefficientConstant*this->getRadius());
        bezierConfig.endPosition = Vec2(x + this->getRadius(), y - sqrt(2)*this->getRadius());
        bezierBy = BezierBy::create(0.8f, bezierConfig);
        move1 = MoveBy::create(duration, Vec2(x, y - sqrt(3)*this->getRadius()));
        move2 = MoveBy::create(duration, Vec2(x - this->getRadius(), y - sqrt(2)*this->getRadius()));
    } else if (direction == DIRECTION_LEFT) {
        bezierConfig.controlPoint_1 = Vec2(y - this->getRadius(), x - CoefficientConstant*this->getRadius());
        bezierConfig.controlPoint_2 = Vec2(y + this->getRadius(), x - CoefficientConstant*this->getRadius());
        bezierConfig.endPosition = Vec2(y + this->getRadius(), x - sqrt(2)*this->getRadius());
        bezierBy = BezierBy::create(0.8f, bezierConfig);
        move1 = MoveBy::create(duration, Vec2(y, x - sqrt(3)*this->getRadius()));
        move2 = MoveBy::create(duration, Vec2(y - this->getRadius(), x - sqrt(2)*this->getRadius()));
    } else if (direction == DIRECTION_RIGHT){
        bezierConfig.controlPoint_1 = Vec2(y - this->getRadius(), x + CoefficientConstant*this->getRadius());
        bezierConfig.controlPoint_2 = Vec2(y + this->getRadius(), x + CoefficientConstant*this->getRadius());
        bezierConfig.endPosition = Vec2(y + this->getRadius(), x + sqrt(2)*this->getRadius());
        bezierBy = BezierBy::create(0.8f, bezierConfig);
        move1 = MoveBy::create(duration, Vec2(y, x + sqrt(3)*this->getRadius()));
        move2 = MoveBy::create(duration, Vec2(y - this->getRadius(), x + sqrt(2)*this->getRadius()));
    }
    return RepeatForever::create(Sequence::create(bezierBy, move1, move2, NULL));
}

ParticleSystem* DirectionPad::createParticleLine() {
    auto emitter = ParticleSystemQuad::createWithTotalParticles(50);
    emitter->setTexture(Director::getInstance()->getTextureCache()->addImage("point.png"));
    emitter->setAnchorPoint(Vec2::ZERO);
    // duration
    emitter->setDuration(ParticleSystem::DURATION_INFINITY);
    // radius mode
    emitter->setEmitterMode(ParticleSystem::Mode::RADIUS);
    // radius mode: start and end radius in pixels
    emitter->setStartRadius(4);
    emitter->setStartRadiusVar(1);
    emitter->setEndRadius(ParticleSystem::START_RADIUS_EQUAL_TO_END_RADIUS);
    emitter->setEndRadiusVar(0);
    // radius mode: degrees per second
    emitter->setRotatePerSecond(100);
    emitter->setRotatePerSecondVar(0);
    // angle
    emitter->setAngle(90);
    emitter->setAngleVar(0);
    // emitter position
    emitter->setPosVar(Vec2::ZERO);
    // life of particles
    emitter->setLife(0.5);
    emitter->setLifeVar(0);
    // spin of particles
    emitter->setStartSpin(0);
    emitter->setStartSpinVar(0);
    emitter->setEndSpin(0);
    emitter->setEndSpinVar(0);
    // color of particles
    Color4F startColor(0.0f, 0.8f, 0.9f, 1.0f);
    emitter->setStartColor(startColor);
    Color4F startColorVar(0, 0, 0, 1.0f);
    emitter->setStartColorVar(startColor);
    Color4F endColor(1.0f, 1.0f, 1.0f, 0.1f);
    emitter->setEndColor(endColor);
    Color4F endColorVar(0, 0, 0, 0.1f);
    emitter->setEndColorVar(endColorVar);
    // size, in pixels
    emitter->setStartSize(20);
    emitter->setStartSizeVar(1);
    emitter->setEndSize(0);
    // emits per second
    emitter->setEmissionRate(emitter->getTotalParticles()/emitter->getLife());
    // additive
    emitter->setBlendAdditive(false);
    return emitter;
}