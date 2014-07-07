//
//  SneakyButtonSkinnedBase.cpp
//  parasitecity
//
//  Created by damingdan on 14/7/7.
//
//

#include "SneakyButtonSkinnedBase.h"

SneakyButtonSkinnedBase::~SneakyButtonSkinnedBase() {
    if (defaultSprite) {
        this->defaultSprite->release();
        this->defaultSprite = NULL;
    }
    
    if (this->activatedSprite) {
        activatedSprite->release();
        this->activatedSprite = NULL;
    }
    
    if (this->disabledSprite) {
        this->disabledSprite->release();
        this->disabledSprite = NULL;
    }
    
    if(this->pressSprite) {
        this->pressSprite->release();
        this->pressSprite = NULL;
    }
    
    if (button) {
        button->release();
        button = NULL;
    }
}

bool SneakyButtonSkinnedBase::init() {
    if (Layer::init()) {
        this->defaultSprite = NULL;
        this->activatedSprite = NULL;
        this->disabledSprite = NULL;
        this->pressSprite = NULL;
        this->button = NULL;
        
        this->schedule(schedule_selector(SneakyButtonSkinnedBase::watchSelf));
        return true;
    }else {
        return false;
    }
}

void SneakyButtonSkinnedBase::watchSelf(float delta) {
    if(!this->button->getStatus()) {
        if (disabledSprite) {
            disabledSprite->cocos2d::Node::setVisible(true);
        } else {
            disabledSprite->setVisible(false);
        }
    } else {
        if (!this->button->getIsActive()) {
            if (this->button->getValue() == 0) {
                activatedSprite->setVisible(false);
                if (defaultSprite) {
                    defaultSprite->setVisible(true);
                }
            } else {
                activatedSprite->setVisible(true);
            }
        } else {
            defaultSprite->setVisible(false);
            if (pressSprite) {
                pressSprite->setVisible(true);
            }
        }
    }
}

void SneakyButtonSkinnedBase::setContentSize(cocos2d::Size s) {
    Layer::setContentSize(s);
    defaultSprite->setContentSize(s);
}

void SneakyButtonSkinnedBase::setDefaultSprite(cocos2d::Sprite *aSprite) {
    if (defaultSprite) {
        if (defaultSprite->getParent()) {
            defaultSprite->removeFromParent();
            defaultSprite->release();
        }
    }
    aSprite->retain();
    defaultSprite = aSprite;
    if (aSprite) {
        this->addChild(defaultSprite, 0);
        this->cocos2d::Node::setContentSize(defaultSprite->getContentSize());
    }
}

void SneakyButtonSkinnedBase::setActivatedSprite(cocos2d::Sprite *aSprite) {
    if (activatedSprite) {
        if (activatedSprite->getParent()) {
            activatedSprite->removeFromParent();
            activatedSprite->release();
        }
    }
    aSprite->retain();
    activatedSprite = aSprite;
    if (aSprite) {
        this->addChild(activatedSprite, 1);
        this->setContentSize(activatedSprite->getContentSize());
    }
}

void SneakyButtonSkinnedBase::setDisabledSprite(cocos2d::Sprite *aSprite) {
    if (disabledSprite) {
        if (disabledSprite->getParent()) {
            disabledSprite->removeFromParent();
            disabledSprite->release();
        }
    }
    aSprite->retain();
    disabledSprite = aSprite;
    if (aSprite) {
        this->addChild(disabledSprite, 2);
        this->setContentSize(disabledSprite->getContentSize());
    }
}

void SneakyButtonSkinnedBase::setPressSprite(cocos2d::Sprite *aSprite) {
    if (pressSprite) {
        if (pressSprite->getParent()) {
            pressSprite->removeFromParent();
            pressSprite->release();
        }
    }
    aSprite->retain();
    pressSprite = aSprite;
    if (aSprite) {
        this->addChild(pressSprite, 3);
        this->setContentSize(pressSprite->getContentSize());
    }
}

void SneakyButtonSkinnedBase::setButton(SneakyButton *aButton) {
    if(button){
        if(button->getParent()){
            button->removeFromParent();
            button->release();
        }
    }
    aButton->retain();
    button = aButton;
    if(aButton){
        this->addChild(button, 4);
        if(defaultSprite){
            button->setRadius(defaultSprite->boundingBox().size.width/2);
        }
    }
}