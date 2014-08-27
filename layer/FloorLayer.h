#pragma once

#include "cocos2d.h"
#include "BasicLayer.h"
USING_NS_CC;

class FloorLayer: public BasicLayer{
public:
    CC_SYNTHESIZE(Sprite*, fr_sp, Fr_sp);
    
    virtual bool init();
    void setupView();
    CREATE_FUNC(FloorLayer);
};