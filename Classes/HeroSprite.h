#pragma once
#include "ActionSprite.h"
#include "Common.h"


//class HeroBody : public b2Body
//{
//public:
//	HeroBody(b2World *world);
//	~HeroBody();
//
//private:
//	b2BodyDef getHeroBodyDef();
//
//};


class HeroSprite : public ActionSprite
{
public:
	HeroSprite(void);
	~HeroSprite(void);

	virtual bool init();
	CREATE_FUNC(HeroSprite);
};

