//
//  OvalActionInterval.cpp
//  parasitecity
//
//  Created by damingdan on 14/7/1.
//
//

#include "OvalActionInterval.h"

OvalActionInterval* OvalActionInterval::create(float duration, const OvalConfig &ovalConfig) {
    auto ovalActionInerval = new OvalActionInterval();
    ovalActionInerval->initWithDuration(duration, ovalConfig);
    ovalActionInerval->autorelease();
    return ovalActionInerval;
}

ActionInterval* OvalActionInterval::reverse() const {
    return nullptr;
}

ActionInterval* OvalActionInterval::clone() const {
    auto ovalActionInerval = new OvalActionInterval();
    ovalActionInerval->initWithDuration(this->getDuration(), this->ovalConfig);
    ovalActionInerval->autorelease();
    return ovalActionInerval;
}

bool OvalActionInterval::initWithDuration(float duration, const OvalConfig &ovalConfig) {
    if (ActionInterval::initWithDuration(duration)) {
        this->ovalConfig = ovalConfig;
        return true;
    }else {
        return false;
    }
}

void OvalActionInterval::update(float time) {
    if (_target) {
        this->startPosition = this->ovalConfig.centerPosition;
        float a = this->ovalConfig.aLength;
        float bx = this->ovalConfig.centerPosition.x;
        float by = this->ovalConfig.centerPosition.y;
        float c = this->ovalConfig.cLength;
        float x = OvalActionInterval::ovalXAt(a, bx, c, time);
        float y = OvalActionInterval::ovalYAt(a, by, c, time);
        _target->setPosition(this->startPosition + Point(x, y));
    }
}