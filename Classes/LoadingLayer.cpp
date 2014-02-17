#include "LoadingLayer.h"


LoadingLayer::LoadingLayer()
{
	this->totalNum = 0;
	this->loadingNum = 0;
}

LoadingLayer::~LoadingLayer()
{
	//this->loadingLabel->removeFromParent();
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

bool LoadingLayer::initWithFilenames(vector<string> filenames, std::function<void(void)> complete)
{
	if(Layer::init()){
		initLoadingProgress();
		this->complete = complete;
		this->totalNum = filenames.size();
		this->loadingNum = 0;
		for (auto filename : filenames){
			Director::getInstance()->getTextureCache()->addImageAsync(filename, CC_CALLBACK_1(LoadingLayer::loadingCallBack, this));
		}
		return true;
	} else {
		return false;
	}
}


LoadingLayer* LoadingLayer::createWithFilenames(vector<string> filenames, std::function<void(void)> complete)
{
	LoadingLayer *loadingLayer = new LoadingLayer();
	if(loadingLayer && loadingLayer->initWithFilenames(filenames, complete)){
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
	this->loadingNum ++;
	float currentPercentage = this->progress->getPercentage();
	this->progress->setPercentage(100/totalNum + currentPercentage);
	if(this->loadingNum >= this->totalNum){
		this->complete();
	}
}