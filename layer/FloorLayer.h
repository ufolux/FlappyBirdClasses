#pragma once

#include "cocos2d.h"
#include "BasicLayer.h"
USING_NS_CC;

class FloorLayer: public BasicLayer{
public:

    
    virtual bool init();
    void setupView();
    void scrollFloor(float t);
    
    CREATE_FUNC(FloorLayer);
    
    CC_SYNTHESIZE(Sprite*, fr_sp1, Fr_sp1);
    CC_SYNTHESIZE(Sprite*, fr_sp2, Fr_sp2);

};