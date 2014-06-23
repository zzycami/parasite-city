//
//  GameScene.h
//  parasitecity
//
//  Created by damingdan on 14-6-20.
//
//

#include "cocos2d.h"
#include "OptionLayer.h"

using namespace cocos2d;

const Point SteelBox1Position = Point(211, 26);
const Point SteelBox2Position = Point(321, 365);
const Size SceneSize = Size(1404, 804);
const int GroundBottomHeight = 25;

class GameScene : public Scene , public OptionDelegate{
public:
    virtual bool init();
    
    virtual void onWalk(Direction direction);
    virtual void onStop();
    virtual void onJump();
    virtual void onSquat();
    virtual Point getReferencePoint();
    
    CREATE_FUNC(GameScene);
    
    void initPhysicsBoundary();
private:
    OptionLayer* optionLayer;
};
