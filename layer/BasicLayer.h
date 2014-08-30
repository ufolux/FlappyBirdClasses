#pragma once

#include "cocos2d.h"
#include "DynamicData.h"
#include "StaticData.h"




#define WIN_SIZE Director::getInstance()->getWinSize()
#define VISIBLE_SIZE Director::getInstance()->getVisibleSize()
#define ORINGIN_SIZE Director::getInstance()->getVisibleOrigin()

USING_NS_CC;

class BasicLayer: public Layer{
public:
    virtual bool init();
    CREATE_FUNC(BasicLayer);
};