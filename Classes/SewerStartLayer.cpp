//
//  SewerStartLayer.cpp
//  parasite-city
//
//  Created by damingdan on 14-2-11.
//
//

#include "SewerStartLayer.h"

SewerStartLayer::SewerStartLayer()
{
    steelBox1 = NULL;
    steelBox2 = NULL;
}


SewerStartLayer::~SewerStartLayer()
{
    delete debugDraw;
    delete world;
}

bool SewerStartLayer::init()
{
    initBox2d();
    
    if (Layer::init()) {
        steelBox1 = Sprite::create("steel_box.png");
        //steelBox1->setAnchorPoint(Point::ZERO);
        steelBox1->setPosition(SteelBox1Position.x + steelBox1->getContentSize().width/2, SteelBox1Position.y + steelBox1->getContentSize().height/2);
        this->addChild(steelBox1);
        
        b2BodyDef steelBox1BodyDef;
        steelBox1BodyDef.type = b2_dynamicBody;
        steelBox1BodyDef.linearDamping = 1;// 线速度阻尼
        steelBox1BodyDef.angularDamping = 1;// 角速度阻尼
        steelBox1BodyDef.position.Set(steelBox1->getPositionX()/PTM_RATIO, steelBox1->getPositionY()/PTM_RATIO);
        steelBox1BodyDef.userData = steelBox1;
        steelBox1Body = world->CreateBody(&steelBox1BodyDef);
        
        b2FixtureDef steelBox1FextrureDef;
        b2PolygonShape boxShape;
        Size boxSize = steelBox1->getContentSize();
        boxShape.SetAsBox(boxSize.width/PTM_RATIO/2, boxSize.height/PTM_RATIO/2);
        steelBox1FextrureDef.shape = &boxShape;
        steelBox1FextrureDef.density = 7850.0f;
        steelBox1FextrureDef.friction = 0.5f;
        steelBox1Body->CreateFixture(&steelBox1FextrureDef);
        
        steelBox2 = Sprite::create("steel_box.png");
        //steelBox2->setAnchorPoint(Point::ZERO);
        steelBox2->setPosition(SteelBox2Position.x + steelBox2->getContentSize().width/2, SteelBox2Position.y + steelBox2->getContentSize().height/2);
        this->addChild(steelBox2);
        
        b2BodyDef steelBox2BodyDef;
        steelBox2BodyDef.type = b2_dynamicBody;
        steelBox2BodyDef.linearDamping = 1;// 线速度阻尼
        steelBox2BodyDef.angularDamping = 1;// 角速度阻尼
        steelBox2BodyDef.position.Set(steelBox2->getPositionX()/PTM_RATIO, steelBox2->getPositionY()/PTM_RATIO);
        steelBox2BodyDef.userData = steelBox2;
        steelBox2Body = world->CreateBody(&steelBox2BodyDef);
        
        b2FixtureDef steelBox2FextrureDef;
        steelBox2FextrureDef.shape = &boxShape;
        steelBox2FextrureDef.density = 7850.0f;
        steelBox2FextrureDef.friction = 0.5f;
        steelBox2Body->CreateFixture(&steelBox2FextrureDef);
        
        mouseJoint = NULL;
        schedule(schedule_selector(SewerStartLayer::tick));
        
        auto dispatcher = Director::getInstance()->getEventDispatcher();
        auto listener = EventListenerTouchAllAtOnce::create();
        listener->onTouchesBegan = CC_CALLBACK_2(SewerStartLayer::onTouchesBegan, this);
        listener->onTouchesMoved = CC_CALLBACK_2(SewerStartLayer::onTouchesMoved, this);
        listener->onTouchesEnded = CC_CALLBACK_2(SewerStartLayer::onTouchesEnded, this);
        dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
        
        return true;
    }else {
        return false;
    }
}

void SewerStartLayer::onTouchesBegan(const std::vector<Touch*>& touches, Event *event)
{
    if(mouseJoint != NULL){
        return ;
    }
    Touch *touch = touches[0];
    Point location = touch->getLocationInView();
    location = Director::getInstance()->convertToGL(location);
    b2Vec2 localtionInWorld = b2Vec2(location.x/PTM_RATIO, location.y/PTM_RATIO);
    
    for (b2Body *body = world->GetBodyList(); body; body = body->GetNext()) {
        for (b2Fixture *fixure = body->GetFixtureList(); fixure; fixure = fixure->GetNext()) {
            if (fixure->TestPoint(localtionInWorld)) {
                b2MouseJointDef mouseJointDef;
                mouseJointDef.bodyA = groundBody;
                mouseJointDef.bodyB = body;
                mouseJointDef.collideConnected = true;
                mouseJointDef.target = localtionInWorld;
                mouseJointDef.maxForce = 1000.0f*steelBox1Body->GetMass();
                mouseJoint = (b2MouseJoint *)world->CreateJoint(&mouseJointDef);
                body->SetAwake(true);
            }
        }
    }
}

void SewerStartLayer::onTouchesMoved(const std::vector<Touch*>& touches, Event *event)
{
    if (mouseJoint == NULL) {
        return;
    }
    Touch *touch = touches[0];
    Point location = touch->getLocationInView();
    location = Director::getInstance()->convertToGL(location);
    std::printf("location:%f, %f\n", location.x, location.y);
    b2Vec2 localtionInWorld = b2Vec2(location.x/PTM_RATIO, location.y/PTM_RATIO);
    std::printf("localtionInWorld:%f, %f\n", localtionInWorld.x, localtionInWorld.y);
    mouseJoint->SetTarget(localtionInWorld);
}

void SewerStartLayer::onTouchesEnded(const std::vector<Touch*>& touches, Event *event)
{
    if (mouseJoint != NULL) {
        world->DestroyJoint(mouseJoint);
        mouseJoint = NULL;
        return;
    }
}

void SewerStartLayer::tick(float dt)
{
    int velocityIterations = 8;
    int positionIterations = 1;
    world->Step(dt, velocityIterations, positionIterations);
    
    for (b2Body *body = world->GetBodyList(); body; body = body->GetNext()) {
        if (body->GetUserData() != NULL) {
            Sprite *sprite = (Sprite *)body->GetUserData();
            sprite->setPosition(body->GetPosition().x*PTM_RATIO, body->GetPosition().y*PTM_RATIO);
            sprite->setRotation(-1 * CC_RADIANS_TO_DEGREES(body->GetAngle()));
        }
    }
}

void SewerStartLayer::initDebugDraw()
{
    debugDraw = new GLESDebugDraw(PTM_RATIO);
    uint32 flags = 0;
    flags += b2Draw::e_shapeBit;
    flags += b2Draw::e_jointBit;
    flags += b2Draw::e_aabbBit;
    flags += b2Draw::e_centerOfMassBit;
    flags += b2Draw::e_pairBit;
    debugDraw->SetFlags(flags);
    world->SetDebugDraw(debugDraw);
}

void SewerStartLayer::draw()
{
    Layer::draw();
    GL::enableVertexAttribs( cocos2d::GL::VERTEX_ATTRIB_FLAG_POSITION );
    kmGLPushMatrix();
    world->DrawDebugData();
    kmGLPopMatrix();
}

void SewerStartLayer::initBox2d()
{
    // init box2d world
    bool doSleep = true;
    b2Vec2 gravity(0.0f, -100.0f);
    world = new b2World(gravity);
    world->SetAllowSleeping(doSleep);
    world->SetContinuousPhysics(true);
    
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0, 0);
    groundBody = world->CreateBody(&groundBodyDef);
    
    // ground box shape
    b2EdgeShape groundBox;
    int stageHeight = 360;
    
    // bottom
    groundBox.Set(b2Vec2(0, GroundBottomHeight/PTM_RATIO), b2Vec2(453/PTM_RATIO, GroundBottomHeight/PTM_RATIO));
    groundBody->CreateFixture(&groundBox, 0);
    groundBox.Set(b2Vec2(533/PTM_RATIO, GroundBottomHeight/PTM_RATIO), b2Vec2(1070/PTM_RATIO, GroundBottomHeight/PTM_RATIO));
    groundBody->CreateFixture(&groundBox, 0);
    groundBox.Set(b2Vec2(1070/PTM_RATIO, (stageHeight + GroundBottomHeight)/PTM_RATIO), b2Vec2(SceneSize.width/PTM_RATIO, (stageHeight + GroundBottomHeight)/PTM_RATIO));
    groundBody->CreateFixture(&groundBox, 0);
    
    // top
    groundBox.Set(b2Vec2(0, SceneSize.height/PTM_RATIO), b2Vec2(SceneSize.width/PTM_RATIO, SceneSize.height/PTM_RATIO));
    groundBody->CreateFixture(&groundBox, 0);
    
    // left
    groundBox.Set(b2Vec2(0, SceneSize.height/PTM_RATIO), b2Vec2(0, 0));
    groundBody->CreateFixture(&groundBox, 0);
    
    // right
    groundBox.Set(b2Vec2(SceneSize.width/PTM_RATIO, SceneSize.height/PTM_RATIO), b2Vec2(SceneSize.width/PTM_RATIO, (stageHeight + GroundBottomHeight)/PTM_RATIO));
    groundBody->CreateFixture(&groundBox, 0);
    groundBox.Set(b2Vec2(1070/PTM_RATIO, (stageHeight + GroundBottomHeight)/PTM_RATIO), b2Vec2(1070/PTM_RATIO, GroundBottomHeight/PTM_RATIO));
    groundBody->CreateFixture(&groundBox, 0);
    
    initDebugDraw();
}