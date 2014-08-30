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
    
    bg_sp = Sprite::createWithSpriteFrameName(STATIC_DATA_STRING("bg"));
    bg_sp->setPosition(VISIBLE_SIZE.width / 2, VISIBLE_SIZE.height / 2);
    
    this->addChild(bg_sp);
}

