#pragma once

#include "cocos2d.h"
#include "BasicLayer.h"
#include "BirdLayer.h"
USING_NS_CC;

class TouchLayer: public BasicLayer{
public:
    virtual bool init();
    void touchEventHandler();
    CREATE_FUNC(TouchLayer);
    
};