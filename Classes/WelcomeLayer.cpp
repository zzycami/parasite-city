#include "WelcomeLayer.h"
#include "SewerStartScene.h"

WelcomeLayer::WelcomeLayer()
{
    volume = 0.8f;
}

WelcomeLayer::~WelcomeLayer()
{
	SimpleAudioEngine::getInstance()->stopAllEffects();
	SimpleAudioEngine::getInstance()->end();
}

bool WelcomeLayer::init()
{
	if(Layer::init()){
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
    auto *gameStartMenuItem = MenuItemSprite::create(gameStartNormal, gameStartSelect, CC_CALLBACK_1(WelcomeLayer::menuItemSelectedAnimate, this));
    gameStartMenuItem->setAnchorPoint(Point(1, 0));
    float menuXPosition = winSize.width - MenuRightMargin;
    float menuYPosition = winSize.height - gameStartMenuItem->getContentSize().height - MenuTopMargin;
	gameStartMenuItem->setTag(MenuTagStart);
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
    auto *galleryMenuItem = MenuItemSprite::create(galleryNormal, gallerySelect, galleryGrey, CC_CALLBACK_1(WelcomeLayer::menuItemSelectedAnimate, this));
	galleryMenuItem->setTag(MenuTagGallery);
    galleryMenuItem->setAnchorPoint(Point(1, 0));
    
    Sprite *omakeWhite = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("omake_white.png"));
    Sprite *omakeSelectBackground = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("omake_select.png"));
    Sprite *omakeGrey = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("omake_grey.png"));
    Sprite *omakeNormal = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("omake_white.png"));
    Sprite *omakeSelect = Sprite::create();
    omakeWhite->setAnchorPoint(Point::ZERO);
    omakeSelectBackground->setAnchorPoint(Point::ZERO);
    omakeSelect->addChild(omakeSelectBackground);
    omakeSelect->addChild(omakeWhite);
    auto *omakeMenuItem = MenuItemSprite::create(omakeNormal, omakeSelect, omakeGrey, CC_CALLBACK_1(WelcomeLayer::menuItemSelectedAnimate, this));
	omakeMenuItem->setTag(MenuTagOmake);
    omakeMenuItem->setAnchorPoint(Point(1, 0));
    
    Sprite *exitNormal = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("exit_white.png"));
    auto exitMenuItem = MenuItemSprite::create(exitNormal, exitNormal, CC_CALLBACK_1(WelcomeLayer::menuItemSelectedAnimate, this));
    exitMenuItem->setAnchorPoint(Point(1, 0));
	exitMenuItem->setTag(MenuTagExit);
    
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
		stageMenuItem = MenuItemSprite::create(stageNormal, stageSelectButton, stageGrey, CC_CALLBACK_1(WelcomeLayer::menuItemSelectedAnimate, this));
        stageMenuItem->setAnchorPoint(Point(1, 0));
        menuYPosition = menuYPosition - stageMenuItem->getContentSize().height - MenuGapMargin;
        stageMenuItem->setPosition(menuXPosition, menuYPosition);
        stageMenuItem->setEnabled(false);
		stageMenuItem->setTag(100 + i);
        menu->addChild(stageMenuItem);
    }
    
    ControlSlider *volumeSlider = initVolumeSlider();
    menuYPosition = menuYPosition - volumeSlider->getContentSize().height - MenuGapMargin;
    volumeSlider->setPosition(menuXPosition, menuYPosition);
    this->addChild(volumeSlider);

	menuYPosition = menuYPosition - omakeMenuItem->getContentSize().height - MenuGapMargin;
    omakeMenuItem->setPosition(menuXPosition, menuYPosition);
    omakeMenuItem->setEnabled(false);
    menu->addChild(omakeMenuItem);
    
    menuYPosition = menuYPosition - galleryMenuItem->getContentSize().height - MenuGapMargin;
    galleryMenuItem->setPosition(menuXPosition, menuYPosition);
    galleryMenuItem->setEnabled(false);
    menu->addChild(galleryMenuItem);

    menuYPosition = menuYPosition - exitMenuItem->getContentSize().height - MenuGapMargin;
    exitMenuItem->setPosition(menuXPosition, menuYPosition);
    exitMenuItem->setEnabled(true);
    menu->addChild(exitMenuItem);
    
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
}

ControlSlider* WelcomeLayer::initVolumeSlider()
{
    ControlSlider *volumeSlider = ControlSlider::create("slider_bg.png", "slider_pg.png", "slider.png");
    volumeSlider->setMaximumValue(1.0f);
    volumeSlider->setMinimumValue(0.0f);
    volumeSlider->setValue(volume);
    volumeSlider->addTargetWithActionForControlEvents(this, cccontrol_selector(WelcomeLayer::volumeChange), Control::EventType::VALUE_CHANGED);
	volumeSlider->setAnchorPoint(Point(1, 0));
    return volumeSlider;
}

void WelcomeLayer::menuItemSelectedAnimate(Object *sender)
{
	MenuItemSprite *menuItem = (MenuItemSprite *)sender;
	Size winSize = Director::getInstance()->getWinSize();
	auto *actionMove = MoveTo::create(0.1f, Point(menuItem->getPositionX() - 30, menuItem->getPositionY()));
	auto *actionBack = MoveTo::create(0.2f, Point(winSize.width + menuItem->getContentSize().width, menuItem->getPositionY()));

	function<void(void)> callback;
	switch (menuItem->getTag())
	{
	case MenuTagStart:
		callback = bind(&WelcomeLayer::menuNewGameCallBack, this);
		break;
	case MenuTagExit:
		callback = bind(&WelcomeLayer::menuExitCallBack, this);
		break;
	case MenuTagGallery:
		callback = bind(&WelcomeLayer::menuGalleryCallBack, this);
		break;
	case MenuTagOmake:
		callback = bind(&WelcomeLayer::menuOmakeCallBack, this);
		break;
	case MenuTagStage1:
		callback = bind(&WelcomeLayer::menuStage1CallBack, this);
		break;
	case MenuTagStage2:
		callback = bind(&WelcomeLayer::menuStage2CallBack, this);
		break;
	case MenuTagStage3:
		callback = bind(&WelcomeLayer::menuStage3CallBack, this);
		break;
	default:
		break;
	}
	CallFunc *actionDone = CallFunc::create(callback);
	Sequence *sequence = Sequence::create(actionMove, actionBack, actionDone, NULL);
    SimpleAudioEngine::getInstance()->playEffect("00258.wav");
	menuItem->runAction(sequence);
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
	// add background
	//Sprite *background = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("lisa_rest00.png"));
	Sprite *background = Sprite::create("lisa_rest00.png");
	background->setAnchorPoint(Point(0, 0));
	background->setPosition(0, 0);
	this->addChild(background);

	// add the girl sitting
	//Sprite *lisaRest = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("lisa_rest01.png"));
	Sprite *lisaRest = Sprite::create("lisa_rest01.png");
	lisaRest->getTexture()->setAliasTexParameters();
	lisaRest->setAnchorPoint(Point(0, 0));
	lisaRest->setPosition(107, 0);
	Animation *animation = Animation::create();
	animation->setDelayPerUnit(0.08f);
	for (int  i= 1;  i< 33; i++){
		char buffer[50] = {0};
		sprintf(buffer, "lisa_rest%02d.png", i);
		//SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(buffer);
		SpriteFrame *frame = SpriteFrame::create(buffer, Rect(0, 0, 686, 629));
		frame->getTexture()->setAliasTexParameters();
		animation->addSpriteFrame(frame);
	}
	Animate *animate = Animate::create(animation);
	lisaRest->runAction(RepeatForever::create(animate));
	this->addChild(lisaRest);
    SimpleAudioEngine::getInstance()->setEffectsVolume(volume);
	SimpleAudioEngine::getInstance()->playEffect("00104.wav", true);
        
    initMenu();
}

void WelcomeLayer::onExit()
{
    Layer::onExit();
}

void WelcomeLayer::menuExitCallBack()
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void WelcomeLayer::menuGalleryCallBack()
{
}

void WelcomeLayer::menuNewGameCallBack()
{
    auto *sewerStartScene = SewerStartScene::create();
    TransitionScene *transition = TransitionFade::create(1, sewerStartScene);
    Director::getInstance()->replaceScene(transition);
}

void WelcomeLayer::menuOmakeCallBack()
{}

void WelcomeLayer::menuStage1CallBack()
{}

void WelcomeLayer::menuStage2CallBack()
{}

void WelcomeLayer::menuStage3CallBack()
{}
