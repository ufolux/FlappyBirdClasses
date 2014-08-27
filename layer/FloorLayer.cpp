#include "FloorLayer.h"

bool FloorLayer::init(){
    bool sRect = false;
    
    do{
        CC_BREAK_IF( !BasicLayer::init() );
        setupView();
        sRect = true;
    }while (0);
    
    return sRect;
}

void FloorLayer::setupView(){
    
    fr_sp = Sprite::createWithSpriteFrameName(STATIC_DATA_STRING("floor"));
    fr_sp->setScale(SCALE_RATIO);
    this->addChild(fr_sp);
    
}