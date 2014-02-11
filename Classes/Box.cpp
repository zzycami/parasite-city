//
//  Box.cpp
//  parasite-city
//
//  Created by damingdan on 14-2-11.
//
//

#include "Box.h"

Box::Box()
{
    shiftSpeed = 20;
}

Box::~Box()
{}

bool Box::init()
{
    if (Sprite::init()) {
        return true;
    }else {
        return false;
    }
}

void Box::setShiftEffect(const std::string &shiftEffect)
{
    this->shiftEffect = shiftEffect;
}

void Box::setShiftSpeed(const float shiftSpeed)
{
    this->shiftSpeed = shiftSpeed;
}