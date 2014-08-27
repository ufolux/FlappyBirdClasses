
#include "BirdLayer.h"


bool BirdLayer::init(){
    bool sRect = false;
    
    do{
        CC_BREAK_IF( !BasicLayer::init() );
        setupView();
        sRect = true;
    }while (0);
    
    return sRect;
}

void BirdLayer::setupView(){
    bd_sp = Sprite::createWithSpriteFrameName(STATIC_DATA_STRING("bird1"));
    bd_sp->setScale(SCALE_RATIO);
    Vector<SpriteFrame*> spriteFrame;
    
    spriteFrame.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(STATIC_DATA_STRING("bird1")));
    spriteFrame.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(STATIC_DATA_STRING("bird2")));
    spriteFrame.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(STATIC_DATA_STRING("bird3")));
    
    auto animation = Animation::createWithSpriteFrames(spriteFrame, 0.2f);
    auto animate = Animate::create(animation);
    
    bd_sp -> runAction(RepeatForever::create(animate));

    this->addChild(bd_sp);
}


