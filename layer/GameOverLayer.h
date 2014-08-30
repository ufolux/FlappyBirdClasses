#pragma once

#include "cocos2d.h"
#include "BasicLayer.h"
USING_NS_CC;

class GameOverLayer: public BasicLayer{
public:
    virtual bool init();
    void setupView();
    
    CREATE_FUNC(GameOverLayer);
    CC_SYNTHESIZE(Sprite*, score_sp, ScoreSp);
    CC_SYNTHESIZE(Sprite*, title_sp, TitleSp);
    CC_SYNTHESIZE(Sprite*, replay_sp, ReplaySp);

};