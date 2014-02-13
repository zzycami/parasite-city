#include "PhysicalSprite.h"

PhysicalSprite::PhysicalSprite()
{
}

PhysicalSprite::~PhysicalSprite()
{}

bool PhysicalSprite::init()
{
	if(Sprite::init()){
		return true;
	}else {
		return false;
	}
}