#include "HeroSprite.h"


HeroSprite::HeroSprite(void)
{
}


HeroSprite::~HeroSprite(void)
{
}


bool HeroSprite::init()
{
	if(ActionSprite::initWithFile("hero_idle0.png")){
		//this->setAnchorPoint(Point(0.5, 0));

		Animation *idle = this->createAnimation("hero_idle%d.png", 4, 3);
		this->setIdleAction(RepeatForever::create(Animate::create(idle)));

		Animation *walk = this->createAnimation("hero_run%02d.png", 8, 8);
		this->setWalkAction(RepeatForever::create(Animate::create(walk)));

		setATK(20);
		setHP(100);
		setVelocity(1);
		setDirection(Point::ZERO);
		return true;
	}else {
		return false;
	}
}