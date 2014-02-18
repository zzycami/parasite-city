//
//  SewerStartScene.cpp
//  parasite-city
//
//  Created by damingdan on 14-2-11.
//
//

#include "SewerStartScene.h"
#include "OptionLayer.h"

SewerStartScene::SewerStartScene()
{}

SewerStartScene::~SewerStartScene()
{}

vector<resource> SewerStartScene::getResourceList()
{
    resource res;
	vector<resource> resources = vector<resource>();
    LoadingLayer::addConsequentTextures("hero_idle%d.png", 4, resources);
    LoadingLayer::addConsequentTextures("hero_run%02d.png", 8, resources);
    LoadingLayer::addConsequentTextures("hero_squat_walk%02d.png", 8, resources);
    
    res.type = RESOURCE_TYPE_IMAGE;
    res.filename = "scene1_background.png";
    resources.push_back(res);
    
    res.type = RESOURCE_TYPE_IMAGE;
    res.filename = "steel_box.png";
    resources.push_back(res);

	res.type = RESOURCE_TYPE_IMAGE;
	res.filename = "joystick.png";
	resources.push_back(res);

	res.type = RESOURCE_TYPE_IMAGE;
	res.filename = "joystick_bg.png";
	resources.push_back(res);
	return resources;
}

bool SewerStartScene::init()
{
    if (Scene::init()) {
        backgroundLayer = Layer::create();
        if (backgroundLayer) {
            Sprite *background = Sprite::create("scene1_background.png");
            background->setAnchorPoint(Point(0, 0));
            background->setPosition(Point::ZERO);
            backgroundLayer->addChild(background);
            this->addChild(backgroundLayer);
        }
        sewerStartLayer = SewerStartLayer::create();
        if (sewerStartLayer) {
            this->addChild(sewerStartLayer);
        }

		auto optionLayer = OptionLayer::create();
		if(optionLayer) {
			this->addChild(optionLayer);
		}
        
        auto dispatcher = Director::getInstance()->getEventDispatcher();
        auto listener = EventListenerTouchAllAtOnce::create();
        listener->onTouchesBegan = CC_CALLBACK_2(SewerStartScene::onTouchesBegan, this);
        listener->onTouchesMoved = CC_CALLBACK_2(SewerStartScene::onTouchesMoved, this);
        listener->onTouchesEnded = CC_CALLBACK_2(SewerStartScene::onTouchesEnded, this);
        dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
        
        return true;
    }else {
        return false;
    }
}

void SewerStartScene::onTouchesBegan(const std::vector<Touch*>& touches, Event *event)
{
}

void SewerStartScene::onTouchesMoved(const std::vector<Touch*>& touches, Event *event)
{
//    if (sewerStartLayer->mouseJoint == NULL) {
//        Touch *touch = touches[0];
//        Point location = touch->getLocationInView();
//        Point startLocation = touch->getStartLocationInView();
//        Point position = this->getPosition();
//        float shift = location.x - startLocation.x;
//        position.x -= shift/10;
//        this->setPosition(position);
//    }
}

void SewerStartScene::onTouchesEnded(const std::vector<Touch*>& touches, Event *event)
{
}