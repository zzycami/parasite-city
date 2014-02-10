#include "WelcomeLayer.h"
#include "HelloWorldScene.h"

WelcomeLayer::WelcomeLayer()
{
    volume = 0.8f;
}

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
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile("menu.plist");

		SimpleAudioEngine::getInstance()->preloadEffect("00104.wav");

		// add background
		//Sprite *background = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("lisa_rest00.png"));
		Sprite *background = Sprite::create("lisa_rest00.png");
		background->setAnchorPoint(Point(0, 0));
		background->setPosition(0, 0);
		this->addChild(background);

		// add the girl sitting
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
        SimpleAudioEngine::getInstance()->setEffectsVolume(volume);
		SimpleAudioEngine::getInstance()->playEffect("00104.wav", true);
        
        initMenu();
		return true;
	}else {
		return false;
	}
}

void WelcomeLayer::initMenu()
{
    // create menu
    Size winSize = Director::getInstance()->getWinSize();
    
    
    Sprite *gameStartNormal = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("start_white.png"));
    Sprite *gameStartSelect = Sprite::create();
    Sprite *startWhite = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("start_white.png"));
    startWhite->setPosition(startWhite->getContentSize().width*0.5, startWhite->getContentSize().height*0.5);
    Sprite *startSelect = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("start_select.png"));
    startSelect->setAnchorPoint(Point::ZERO);
    gameStartSelect->addChild(startSelect);
    gameStartSelect->addChild(startWhite);
    auto *gameStartMenuItem = MenuItemSprite::create(gameStartNormal, gameStartSelect, CC_CALLBACK_1(WelcomeLayer::menuNewGameCallBack, this));
    gameStartMenuItem->setAnchorPoint(Point::ZERO);
    float menuXPosition = winSize.width - gameStartMenuItem->getContentSize().width - MenuRightMargin;
    float menuYPosition = winSize.height - gameStartMenuItem->getContentSize().height - MenuTopMargin;
    gameStartMenuItem->setPosition(menuXPosition, menuYPosition);
    gameStartMenuItem->setEnabled(true);
    
    Sprite *galleryWhite = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("gallery_white.png"));
    Sprite *galleryGrey = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("gallery_grey.png"));
    Sprite *gallerySelectBackground = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("gallery_select.png"));
    Sprite *galleryNormal = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("gallery_white.png"));
    Sprite *gallerySelect = Sprite::create();
    galleryWhite->setAnchorPoint(Point::ZERO);
    gallerySelectBackground->setAnchorPoint(Point::ZERO);
    gallerySelect->addChild(gallerySelectBackground);
    gallerySelect->addChild(galleryWhite);
    auto *galleryMenuItem = MenuItemSprite::create(galleryNormal, gallerySelect, galleryGrey, CC_CALLBACK_1(WelcomeLayer::menuGalleryCallBack, this));
    galleryMenuItem->setAnchorPoint(Point::ZERO);
    
    Sprite *omakeWhite = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("omake_white.png"));
    Sprite *omakeSelectBackground = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("omake_select.png"));
    Sprite *omakeGrey = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("omake_grey.png"));
    Sprite *omakeNormal = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("omake_white.png"));
    Sprite *omakeSelect = Sprite::create();
    omakeWhite->setAnchorPoint(Point::ZERO);
    omakeSelectBackground->setAnchorPoint(Point::ZERO);
    omakeSelect->addChild(omakeSelectBackground);
    omakeSelect->addChild(omakeWhite);
    auto *omakeMenuItem = MenuItemSprite::create(omakeNormal, omakeSelect, omakeGrey, CC_CALLBACK_1(WelcomeLayer::menuOmakeCallBack, this));
    omakeMenuItem->setAnchorPoint(Point::ZERO);
    
    Sprite *exitNormal = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("exit_white.png"));
    auto exitMenuItem = MenuItemSprite::create(exitNormal, exitNormal, CC_CALLBACK_1(WelcomeLayer::menuExitCallBack, this));
    exitMenuItem->setAnchorPoint(Point::ZERO);
    
    Menu *menu = Menu::create(gameStartMenuItem, NULL);
    
    for (int i = 1; i<=3; i++) {
        char stageWhiteName[50] = {0};
        char stageGreyName[50] = {0};
        sprintf(stageWhiteName, "stage%d_white.png", i);
        sprintf(stageGreyName, "stage%d_grey.png", i);
        Sprite *stageNormal = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(stageWhiteName));
        Sprite *stageSelectButton = Sprite::create();
        Sprite *stageWhite = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(stageWhiteName));
        Sprite *stageGrey = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(stageGreyName));
        Sprite *stageSelect = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("stage_select.png"));
        stageWhite->setAnchorPoint(Point::ZERO);
        stageSelect->setAnchorPoint(Point::ZERO);
        stageSelectButton->addChild(stageSelect);
        stageSelectButton->addChild(stageWhite);
        MenuItemSprite *stageMenuItem;
        switch (i) {
            case 1:
                stageMenuItem = MenuItemSprite::create(stageNormal, stageSelectButton, stageGrey, CC_CALLBACK_1(WelcomeLayer::menuStage1CallBack, this));
                break;
            case 2:
                stageMenuItem = MenuItemSprite::create(stageNormal, stageSelectButton, stageGrey, CC_CALLBACK_1(WelcomeLayer::menuStage2CallBack, this));
                break;
            case 3:
                stageMenuItem = MenuItemSprite::create(stageNormal, stageSelectButton, stageGrey, CC_CALLBACK_1(WelcomeLayer::menuStage3CallBack, this));
                break;
            default:
                break;
        }
        stageMenuItem->setAnchorPoint(Point::ZERO);
        menuYPosition = menuYPosition - stageMenuItem->getContentSize().height - MenuGapMargin;
        stageMenuItem->setPosition(menuXPosition, menuYPosition);
        stageMenuItem->setEnabled(false);
        menu->addChild(stageMenuItem);
    }
    
    ControlSlider *volumeSlider = initVolumeSlider();
    menuYPosition = menuYPosition - volumeSlider->getContentSize().height - MenuGapMargin;
    volumeSlider->setPosition(menuXPosition, menuYPosition);
    this->addChild(volumeSlider);
    
    menuYPosition = menuYPosition - galleryMenuItem->getContentSize().height - MenuGapMargin;
    galleryMenuItem->setPosition(menuXPosition, menuYPosition);
    galleryMenuItem->setEnabled(false);
    menu->addChild(galleryMenuItem);
    
    menuYPosition = menuYPosition - omakeMenuItem->getContentSize().height - MenuGapMargin;
    omakeMenuItem->setPosition(menuXPosition, menuYPosition);
    omakeMenuItem->setEnabled(false);
    menu->addChild(omakeMenuItem);
    
    menuYPosition = menuYPosition - exitMenuItem->getContentSize().height - MenuGapMargin;
    exitMenuItem->setPosition(menuXPosition, menuYPosition);
    exitMenuItem->setEnabled(true);
    menu->addChild(exitMenuItem);
    
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
}

ControlSlider* WelcomeLayer::initVolumeSlider()
{
    ControlSlider *volumeSlider = ControlSlider::create("progress.png", "background.png", "thumb.png");
    volumeSlider->setMaximumValue(1.0f);
    volumeSlider->setMinimumValue(0.0f);
    volumeSlider->setValue(volume);
    volumeSlider->addTargetWithActionForControlEvents(this, cccontrol_selector(WelcomeLayer::volumeChange), Control::EventType::VALUE_CHANGED);
    volumeSlider->setAnchorPoint(Point::ZERO);
    return volumeSlider;
}

void WelcomeLayer::volumeChange(Object *sender, Control::EventType eventType)
{
    ControlSlider *volumeSlider = (ControlSlider*)sender;
    volume = volumeSlider->getValue();
    SimpleAudioEngine::getInstance()->setEffectsVolume(volume);
    SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(volume);
}

void WelcomeLayer::onEnter()
{
    Layer::onEnter();
}

void WelcomeLayer::onExit()
{
    Layer::onExit();
}

void WelcomeLayer::menuExitCallBack(cocos2d::Object *sender)
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void WelcomeLayer::menuGalleryCallBack(cocos2d::Object *sender)
{}

void WelcomeLayer::menuNewGameCallBack(cocos2d::Object *sender)
{
    auto *helloWorldScene = HelloWorld::createScene();
    TransitionScene *transition = TransitionFlipAngular::create(1, helloWorldScene);
    Director::getInstance()->replaceScene(transition);
}

void WelcomeLayer::menuOmakeCallBack(cocos2d::Object *sender)
{}

void WelcomeLayer::menuStage1CallBack(cocos2d::Object *sender)
{}

void WelcomeLayer::menuStage2CallBack(cocos2d::Object *sender)
{}

void WelcomeLayer::menuStage3CallBack(cocos2d::Object *sender)
{}
