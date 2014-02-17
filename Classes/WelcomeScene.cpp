#include "WelcomeScene.h"

WelcomeScene::WelcomeScene()
{
	welcomeLayer = NULL;
}

WelcomeScene::~WelcomeScene(){}

vector<resource> WelcomeScene::getResourceList()
{
	resource res;
	vector<resource> resources = vector<resource>();
	for (int  i= 1;  i< 33; i++){
			char buffer[50] = {0};
			sprintf(buffer, "lisa_rest%02d.png", i);
			res.filename = buffer;
			res.type = RESOURCE_TYPE_IMAGE;
			resources.push_back(res);
	}
	res.filename = "00104.wav";
	res.type = RESOURCE_TYPE_VOICE;
	resources.push_back(res);
	res.filename = "00258.wav";
	res.type = RESOURCE_TYPE_VOICE;
	resources.push_back(res);
	res.filename = "menu";
	res.type = RESOURCE_TYPE_PLIST;
	resources.push_back(res);
	return resources;
}

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