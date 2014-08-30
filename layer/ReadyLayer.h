//
//  ReadyLayer.h
//  FlappyBird
//
//  Created by NASA on 8/31/14.
//
//

#ifndef __FlappyBird__ReadyLayer__
#define __FlappyBird__ReadyLayer__

#include "cocos2d.h"
#include "BasicLayer.h"

USING_NS_CC;

class ReadyLayer: public BasicLayer{
public:
    CREATE_FUNC(ReadyLayer);
    virtual bool init();
    void setupView();
    
    CC_SYNTHESIZE(Sprite*, title_sp, TitleSp);
    CC_SYNTHESIZE(Sprite*, tap_sp, PlaySp);
    
};

#endif /* defined(__FlappyBird__ReadyLayer__) */
