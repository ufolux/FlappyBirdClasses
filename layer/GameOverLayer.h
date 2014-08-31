#pragma once

#include "cocos2d.h"
#include "BasicLayer.h"
#include "ReadyLayer.h"


USING_NS_CC;

class GameOverLayer: public BasicLayer{
public:
    virtual bool init();
    void setupView();
    void displayCounter(int count);
    
    CREATE_FUNC(GameOverLayer);
    CC_SYNTHESIZE(Sprite*, score_sp, ScoreSp);
    CC_SYNTHESIZE(Sprite*, title_sp, TitleSp);
    CC_SYNTHESIZE(Sprite*, replay_sp, ReplaySp);

    CC_SYNTHESIZE(Sprite*, counter_basic, CounterBasic);
    CC_SYNTHESIZE(Sprite*, counter_tens, CounterTens);
    CC_SYNTHESIZE(Sprite*, counter_hundred, CounterHundred);
    
    CC_SYNTHESIZE(int, counter, Counter);
    CC_SYNTHESIZE(Size, counter_size, CounterSize);

    void setRestart(Ref* pSender);
    
private:
    const int m_max_count = 999;
    const int m_defalut_count=0;
};