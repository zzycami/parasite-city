#include "WelcomeScene.h"

WelcomeScene::WelcomeScene()
{
	welcomeLayer = NULL;
}

WelcomeScene::~WelcomeScene(){}

bool WelcomeScene::init()
{
	if(Scene::init()){
		welcomeLayer = WelcomeLayer::create();
		if (welcomeLayer != NULL){
			this->addChild(welcomeLayer);
		}
		return true;
	}else {
		return false;
	}
}