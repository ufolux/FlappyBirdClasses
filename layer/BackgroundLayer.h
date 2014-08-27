#pragma once

#include "cocos2d.h"

#include "BasicLayer.h"


USING_NS_CC;

class BackgroundLayer: public BasicLayer{
public:
    CREATE_FUNC(BackgroundLayer);
    virtual bool init();
    void setupView();

    
};