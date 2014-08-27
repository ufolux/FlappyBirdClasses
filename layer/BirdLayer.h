#pragma once

#include "cocos2d.h"
#include "BasicLayer.h"
USING_NS_CC;

class BirdLayer: public BasicLayer{
public:

    CC_SYNTHESIZE(Sprite*, bd_sp, Bd_sp);
    
    virtual bool init();
    
    void setupView();
    
    CREATE_FUNC(BirdLayer);
};