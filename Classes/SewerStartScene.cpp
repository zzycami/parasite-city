//
//  SewerStartScene.cpp
//  parasite-city
//
//  Created by damingdan on 14-2-11.
//
//

#include "SewerStartScene.h"

SewerStartScene::SewerStartScene()
{}

SewerStartScene::~SewerStartScene()
{}

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
        return true;
    }else {
        return false;
    }
}