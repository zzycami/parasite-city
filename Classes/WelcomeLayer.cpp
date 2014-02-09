#include "WelcomeLayer.h"

WelcomeLayer::WelcomeLayer(){}

WelcomeLayer::~WelcomeLayer(){}

bool WelcomeLayer::init()
{
	if(Layer::init()){
		Texture2D::PVRImagesHavePremultipliedAlpha(true);
		// load resources
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("lisa_rest1.plist");
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("lisa_rest2.plist");
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("lisa_rest3.plist");
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("lisa_rest4.plist");

		CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("00104.wav");

		// add background
		//Sprite *background = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("lisa_rest00.png"));
		Sprite *background = Sprite::create("lisa_rest00.png");
		background->setAnchorPoint(Point(0, 0));
		background->setPosition(0, 0);
		this->addChild(background);

		// add the girl sitting
		Size winSize = Director::getInstance()->getWinSize();
		//Sprite *lisaRest = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("lisa_rest01.png"));
		Sprite *lisaRest = Sprite::create("lisa_rest01.png");
		lisaRest->getTexture()->setAntiAliasTexParameters();
		lisaRest->setAnchorPoint(Point(0, 0));
		lisaRest->setPosition(107, 0);
		Animation *animation = Animation::create();
		animation->setDelayPerUnit(0.08f);
		for (int  i= 1;  i< 33; i++){
			char buffer[50] = {0};
			sprintf(buffer, "lisa_rest%02d.png", i);
			//SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(buffer);
			SpriteFrame *frame = SpriteFrame::create(buffer, Rect(0, 0, 686, 629));
			frame->getTexture()->setAntiAliasTexParameters();
			animation->addSpriteFrame(frame);
		}
		Animate *animate = Animate::create(animation);
		lisaRest->runAction(RepeatForever::create(animate));
		this->addChild(lisaRest);
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("00104.wav", true);
		return true;
	}else {
		return false;
	}
}