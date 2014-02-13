//
//  ActionSprite.h
//  parasite-city
//
//  Created by damingdan on 14-2-13.
//
//

#pragma once
#include "cocos2d.h"
using namespace cocos2d;

typedef enum{
    ACTION_STATE_NONE = 0,
    ACTION_STATE_IDLE,
	ACTION_STATE_RUN,
    ACTION_STATE_WALK,
    ACTION_STATE_ATTACK,
    ACTION_STATE_HURT,
    ACTION_STATE_KNOCKOUT,
} ActionState;

class ActionSprite:public Sprite
{
public:
    ActionSprite();
    ~ActionSprite();
    
    void idle();
    void walk(Point direction);
    void attack();
    void hurt(int damage);
    void knockout();
    
    CC_SYNTHESIZE_RETAIN(Action*, idleAction, IdleAction);
    CC_SYNTHESIZE_RETAIN(Action*, attackAction, AttackAction);
    CC_SYNTHESIZE_RETAIN(Action*, hurtAction, HurtAction);
    CC_SYNTHESIZE_RETAIN(Action*, knockoutAction, KnockoutAction);
    CC_SYNTHESIZE_RETAIN(Action*, walkAction, WalkAction);

    // 精灵的当前状态
    CC_SYNTHESIZE(ActionState, currentState, ActionState);
    
    CC_SYNTHESIZE(float, velocity, Velocity); // 移动速度
    CC_SYNTHESIZE(Point, direction, Direction); // 移动方向（向量）
    CC_SYNTHESIZE(unsigned int, hp, HP); // 生命值
    CC_SYNTHESIZE(unsigned int, atk, ATK); // 攻击力
    
protected:
    // 定义一个创建状态动画的方法
    // fmt   - 状态的图片名格式(查看pd_sprites.plist,每种状态格式都类似hero_idle_xx.png)
    // count - 状态图片序列的数量
    // fps   - 动画的播放帧率
    static cocos2d::Animation *createAnimation(const char *fmt, int count, float fps);
    
    
private:
    // 切换演员的当前状态
    bool changeState(ActionState state);
};