#pragma once

#include "cocos2d.h"
#include "BasicLayer.h"
#include "../data/DynamicData.h"
USING_NS_CC;

class PannelLayer: public BasicLayer{
public:
    PannelLayer();
    ~PannelLayer();
    
    virtual bool init();
    virtual void update(float dt);
    
    void setupView();
    void displayCounter(int count);
    
    
    CREATE_FUNC(PannelLayer);
    CC_SYNTHESIZE(Sprite*, counter_basic, CounterBasic);
    CC_SYNTHESIZE(Sprite*, counter_tens, CounterTens);
    CC_SYNTHESIZE(Sprite*, counter_hundred, CounterHundred);
    
    CC_SYNTHESIZE(int, counter, Counter);
    CC_SYNTHESIZE(Size, counter_size, CounterSize);


private:
    const int m_max_count = 999;
    const int m_defalut_count=0;
    
};