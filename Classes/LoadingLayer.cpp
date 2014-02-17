#include "LoadingLayer.h"


LoadingLayer::LoadingLayer()
{
	this->totalNum = 0;
	this->loadingNum = 0;
}

LoadingLayer::~LoadingLayer()
{
	this->resources.clear();
}

void LoadingLayer::initLoadingProgress()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	Sprite *loadingBackground = Sprite::create("loading_bg.png");
	loadingBackground->setAnchorPoint(Point::ZERO);
	loadingBackground->setPosition(73, 19);
	this->addChild(loadingBackground);

	Sprite *loading = Sprite::create("loading.png");
	progress = ProgressTimer::create(loading);
	progress->setType(ProgressTimer::Type::BAR);
	progress->setMidpoint(Point::ZERO);
	progress->setBarChangeRate(Point(1,0));
	progress->setAnchorPoint(Point::ZERO);
	progress->setPosition(74, 20);
	progress->setPercentage(0);
	this->addChild(progress);
}

bool LoadingLayer::initWithFilenames(vector<resource> resources, std::function<void(void)> complete)
{
	if(Layer::init()){
		initLoadingProgress();
		this->complete = complete;
		this->totalNum = resources.size();
		this->loadingNum = 0;
		this->resources = resources;
		for (auto resource : resources){
			switch (resource.type){
			case RESOURCE_TYPE_IMAGE:
				Director::getInstance()->getTextureCache()->addImageAsync(resource.filename, CC_CALLBACK_1(LoadingLayer::loadingCallBack, this));
				break;
			case RESOURCE_TYPE_PLIST:
				Director::getInstance()->getTextureCache()->addImageAsync(resource.filename+".png", CC_CALLBACK_1(LoadingLayer::loadingCallBack, this));
				break;
			case RESOURCE_TYPE_VOICE:
				// should use plist to preload the voice effect
				SimpleAudioEngine::getInstance()->preloadEffect(resource.filename.c_str());
				this->loadingCallBack(NULL);
				break;
			default:
				break;
			}
			
		}
		return true;
	} else {
		return false;
	}
}


LoadingLayer* LoadingLayer::createWithFilenames(vector<resource> resources, std::function<void(void)> complete)
{
	LoadingLayer *loadingLayer = new LoadingLayer();
	if(loadingLayer && loadingLayer->initWithFilenames(resources, complete)){
		loadingLayer->autorelease();
		return loadingLayer;
	}else {
		delete loadingLayer;
		loadingLayer = NULL;
		return NULL;
	}
}

void LoadingLayer::loadingCallBack(Texture2D *texture)
{
	auto resource = this->resources.at(this->loadingNum);
	if (resource.type == RESOURCE_TYPE_PLIST){
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile(resource.filename+".plist", texture);
	}
	this->loadingNum ++;
	float currentPercentage = this->progress->getPercentage();
	this->progress->setPercentage(100/totalNum + currentPercentage);
	if(this->loadingNum >= this->totalNum){
		this->complete();
	}
}