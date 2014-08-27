#include "BackgroundLayer.h"

bool BackgroundLayer::init(){
    bool sRect = false;
    
    do{
        CC_BREAK_IF( !BasicLayer::init() );
        setupView();
        sRect = true;
    }while (0);
    
    return sRect;
}


void BackgroundLayer::setupView(){
    
    auto bg_sp = Sprite::createWithSpriteFrameName(STATIC_DATA_STRING("bg"));
    bg_sp->setScale(SCALE_RATIO);
    this->addChild(bg_sp);
}
