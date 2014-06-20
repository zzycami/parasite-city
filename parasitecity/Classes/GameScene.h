//
//  GameScene.h
//  parasitecity
//
//  Created by damingdan on 14-6-20.
//
//

#include "cocos2d.h"

using namespace cocos2d;

class GameScene : public Scene {
public:
    virtual bool init();
    
    CREATE_FUNC(GameScene);
    
    void initPhysicsBoundary();
};
