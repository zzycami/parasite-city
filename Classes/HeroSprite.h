#pragma once
#include "ActionSprite.h"



class HeroSprite : public ActionSprite
{
public:
	HeroSprite(void);
	~HeroSprite(void);

	virtual bool init();
	CREATE_FUNC(HeroSprite);
};

