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
#include "PipeLayer.h"

USING_NS_CC;

class ReadyLayer: public BasicLayer{
public:
    CREATE_FUNC(ReadyLayer);
    virtual bool init();
    void setupView();
    void setBegin(Ref* pSender);
    CC_SYNTHESIZE(Sprite*, title_sp, TitleSp);

    
};

#endif /* defined(__FlappyBird__ReadyLayer__) */
