#pragma once

#include "cocos2d.h"
#include "BasicLayer.h"

USING_NS_CC;

class PipeLayer: public BasicLayer{
public:
    virtual bool init();
    void setupView();
    CREATE_FUNC(PipeLayer);
};