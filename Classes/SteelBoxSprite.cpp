#include "SteelBoxSprite.h"


SteelBoxSprite::SteelBoxSprite()
{}

SteelBoxSprite::~SteelBoxSprite()
{}


bool SteelBoxSprite::init()
{
	if(PhysicalSprite::initWithFile(SteelBoxFilename)){
		return true;
	}else {
		return false;
	}
}

void SteelBoxSprite::setFixture(b2Body *body)
{
	b2FixtureDef fextrureDef;
	b2PolygonShape boxShape;
	Size boxSize = this->getContentSize();
	boxShape.SetAsBox(boxSize.width/PTM_RATIO/2, boxSize.height/PTM_RATIO/2);
	fextrureDef.shape = &boxShape;
	fextrureDef.density = 7850.0f;
	fextrureDef.friction = 0.5f;
	body->CreateFixture(&fextrureDef);
}

b2Body* SteelBoxSprite::getBody(b2World *world)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.linearDamping = 1;
	bodyDef.angularDamping = 1;
	bodyDef.position.Set(this->getPositionX()/PTM_RATIO, this->getPositionY()/PTM_RATIO);
	bodyDef.userData = this;
	return world->CreateBody(&bodyDef);
}