#pragma once
#include "ActionSprite.h"
#include "Common.h"

const PhysicsMaterial HeroPhysicsMaterial = PhysicsMaterial(1000.0f, 0.3f, 0.5f);

const Point IdlePoints[] = {
    Point(-33.0f, -90.0f),
    Point(-34.0f, 35.0f),
    Point(-30.0f, 83.0f),
    Point(-29.0f, 85.0f),
    Point(-26.0f, 88.0f),
    Point(-24.0f, 89.0f),
    Point(-15.0f, 89.0f),
    Point(-13.0f, 88.0f),
    Point(-10.0f, 85.0f),
    Point(-8.0f, 81.0f),
    Point(33.0f, -88.0f),
    Point(33.0f, -90.0f)
};

const Point PushPoints[] = {
    Point(53.5f, 46.4f),
    Point(53.7f, 22.7f),
    Point(10.1f, -72.3f),
    Point(-58.3f, -72.4f),
    Point(23.6f, 48.0f),
    Point(53.8f, 46.6f)
};

const Point SquatWalkPoints[] = {
    Point(-35.0f, -68.0f),
    Point(-38.0f, -67.0f),
    Point(-40.0f, -65.0f),
    Point(-40.0f, -61.0f),
    Point(-32.0f, 16.0f),
    Point(-30.0f, 20.0f),
    Point(-20.0f, 32.0f),
    Point(15.0f, 64.0f),
    Point(17.0f, 65.0f),
    Point(27.0f, 65.0f),
    Point(29.0f, 64.0f),
    Point(32.0f, 61.0f),
    Point(34.0f, 57.0f),
    Point(43.0f, -14.0f),
    Point(36.0f, -64.0f),
    Point(34.0f, -66.0f),
    Point(31.0f, -67.0f),
    Point(25.0f, -68.0f)
};

//const PhysicsShapePolygon *IdlePhysicsShapePolygon = PhysicsShapePolygon::create(IdlePoints, 12, HeroPhysicsMaterial, Point::ZERO);
//const PhysicsShapePolygon *PushPhysicsShapePolygon = PhysicsShapePolygon::create(PushPoints, 6, HeroPhysicsMaterial, Point::ZERO);
//const PhysicsShapePolygon *SquatPhysicsShapePolygon = PhysicsShapePolygon::create(SquatWalkPoints, 6, HeroPhysicsMaterial, Point::ZERO);


class HeroSprite : public ActionSprite
{
public:
	HeroSprite(void);
	~HeroSprite(void);

	virtual bool init();
	CREATE_FUNC(HeroSprite);
};

