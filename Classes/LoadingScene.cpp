#include "LoadingScene.h"

LoadingScene::LoadingScene()
{
	nextScene = NULL;
	this->filenames = Vector<String*>();
}

LoadingScene::~LoadingScene()
{}

bool LoadingScene::initWithFilenamesAndNextScene(Vector<String*> filenames, Scene *nextScene)
{
	if(Scene::init()){
		this->nextScene = nextScene;
		this->filenames = filenames;
		this->loadingLayer = LoadingLayer::createWithFilenamesAndNextScene(filenames, nextScene);
		this->addChild(this->loadingLayer);
		return true;
	}else {
		return false;
	}
}

LoadingScene* LoadingScene::createWithFilenamesAndNextScene(Vector<String*> filenames, Scene *nextScene)
{
	LoadingScene *loadingScene = new LoadingScene();
	if (loadingScene && loadingScene->initWithFilenamesAndNextScene(filenames, nextScene)){
		loadingScene->autorelease();
		return loadingScene;
	}else {
		delete loadingScene;
		loadingScene = NULL;
		return NULL;
	}
}

LoadingLayer::LoadingLayer()
{
	this->totalNum = 0;
	this->loadingNum = 0;
}

LoadingLayer::~LoadingLayer()
{
	//this->loadingLabel->removeFromParent();
}

bool LoadingLayer::initWithFilenamesAndNextScene(Vector<String*> filenames, Scene *nextScene)
{
	if(Layer::init()){
		//CCASSERT(nextScene == nullptr, "next scene should not be null");
		this->nextScene = nextScene;
		Size visibleSize = Director::getInstance()->getVisibleSize();
		Point origin = Director::getInstance()->getVisibleOrigin();
		loadingLabel = LabelTTF::create("LOADING...", "OCTAPOST.ttf", 24);
		//loadingLabel->setAnchorPoint(Point(1, 1));
		loadingLabel->setPosition(origin.x + visibleSize.width - loadingLabel->getContentSize().width/2 + 20, origin.y + loadingLabel->getContentSize().height/2 + 20);
		Blink *blink = Blink::create(0.01f, 5000); 
		loadingLabel->runAction(blink);
		this->addChild(loadingLabel);

		this->totalNum = filenames.size();
		this->loadingNum = 0;
		/*for (auto filename : filenames){
			Director::getInstance()->getTextureCache()->addImageAsync(filename->getCString(), CC_CALLBACK_1(LoadingLayer::loadingCallBack, this));
		}*/
		return true;
	} else {
		return false;
	}
}


LoadingLayer* LoadingLayer::createWithFilenamesAndNextScene(Vector<String*> filenames, Scene *nextScene)
{
	LoadingLayer *loadingLayer = new LoadingLayer();
	if(loadingLayer && loadingLayer->initWithFilenamesAndNextScene(filenames, nextScene)){
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
	if(++ this->loadingNum >= this->totalNum){
		//this->loadingLabel->stopAllActions();
		//this->loadingLabel->removeFromParent();
		//TransitionScene *transition = TransitionFade::create(1, this->nextScene);
		//Director::getInstance()->replaceScene(transition);
	}
}