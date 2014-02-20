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

		Animation *walk = this->createAnimation("hero_run%02d.png", 8, 10);
		this->setWalkAction(RepeatForever::create(Animate::create(walk)));

		Animation *squatwalk = this->createAnimation("hero_squat_walk%02d.png", 8, 8);
		this->setSquatwalkAction(RepeatForever::create(Animate::create(squatwalk)));

		Animation *push = this->createAnimation("hero_push%02d.png",10, 5);
		this->setPushAction(RepeatForever::create(Animate::create(push)));

		return true;
	}else {
		return false;
	}
}