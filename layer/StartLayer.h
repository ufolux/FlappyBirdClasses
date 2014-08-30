//
//  StartLayer.h
//  fishGame
//
//  Created by NASA on 8/26/14.
//
//

#ifndef __fishGame__StartLayer__
#define __fishGame__StartLayer__

#include "cocos2d.h"
#include "BasicLayer.h"

USING_NS_CC;

class StartLayer: public BasicLayer{
public:
    CREATE_FUNC(StartLayer);
    virtual bool init();
    void setupView();
    
    CC_SYNTHESIZE(Sprite*, title_sp, TitleSp);
    CC_SYNTHESIZE(Sprite*, play_sp, PlaySp);
    
};

#endif /* defined(__fishGame__StartLayer__) */
