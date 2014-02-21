#pragma once
#include "ActionSprite.h"
#include "Common.h"

const PhysicsMaterial HeroPhysicsMaterial = PhysicsMaterial(1000.0f, 0.3f, 0.5f);

const Point IdlePoints[] = {
    Point(-33.0, -90.0),
    Point(-34.0, 35.0),
    Point(-30.0, 83.0),
    Point(-29.0, 85.0),
    Point(-26.0, 88.0),
    Point(-24.0, 89.0),
    Point(-15.0, 89.0),
    Point(-13.0, 88.0),
    Point(-10.0, 85.0),
    Point(-8.0, 81.0),
    Point(33.0, -88.0),
    Point(33.0, -90.0)
};

const Point PushPoints[] = {
    Point(53.5, 46.4),
    Point(53.7, 22.7),
    Point(10.1, -72.3),
    Point(-58.3, -72.4),
    Point(23.6, 48.0),
    Point(53.8, 46.6)
};

const Point SquatWalkPoints[] = {
    Point(-35.0, -68.0),
    Point(-38.0, -67.0),
    Point(-40.0, -65.0),
    Point(-40.0, -61.0),
    Point(-32.0, 16.0),
    Point(-30.0, 20.0),
    Point(-20.0, 32.0),
    Point(15.0, 64.0),
    Point(17.0, 65.0),
    Point(27.0, 65.0),
    Point(29.0, 64.0),
    Point(32.0, 61.0),
    Point(34.0, 57.0),
    Point(43.0, -14.0),
    Point(36.0, -64.0),
    Point(34.0, -66.0),
    Point(31.0, -67.0),
    Point(25.0, -68.0)
};

const PhysicsBody *IdlePhysicsBody = PhysicsBody::createPolygon(IdlePoints, 12, HeroPhysicsMaterial, Point::ZERO);
const PhysicsBody *PushPhysicsBody = PhysicsBody::createPolygon(PushPoints, 6, HeroPhysicsMaterial, Point::ZERO);
const PhysicsBody *SquatWalkPhysicsBody = PhysicsBody::createPolygon(SquatWalkPoints, 6, HeroPhysicsMaterial, Point::ZERO);


class HeroSprite : public ActionSprite
{
public:
	HeroSprite(void);
	~HeroSprite(void);

	virtual bool init();
	CREATE_FUNC(HeroSprite);
};

