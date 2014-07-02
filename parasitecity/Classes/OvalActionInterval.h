//
//  OvalActionInterval.h
//  parasitecity
//
//  Created by damingdan on 14/7/1.
//
//

#pragma once
#include "cocos2d.h"
#include <math.h>
using namespace cocos2d;

struct OvalConfig {
    Point centerPosition;
    float aLength;
    float cLength;
};

class CC_DLL OvalActionInterval:public ActionInterval {
public:
    static OvalActionInterval* create(float duration, const OvalConfig &ovalConfig);
    
    virtual ActionInterval* reverse() const override;
    virtual ActionInterval *clone() const override;
    virtual void update(float time) override;
    
CC_CONSTRUCTOR_ACCESS:
    bool initWithDuration(float duration, const OvalConfig &ovalConfig);
    
private:
    static inline float ovalXAt(float a, float bx, float c, float t){
        return -a*cos(2*M_PI*t);
    }
    
    static inline float ovalYAt(float a, float by, float c, float t) {
        float b = sqrt(powf(a, 2) - powf(c, 2));
        return b*sin(2*M_PI*t);
    }
    
    OvalConfig ovalConfig;
    Point startPosition;
};