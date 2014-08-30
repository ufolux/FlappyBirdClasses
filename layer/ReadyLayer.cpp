//
//  ReadyLayer.cpp
//  FlappyBird
//
//  Created by NASA on 8/31/14.
//
//

#include "ReadyLayer.h"

bool ReadyLayer::init(){
    bool sRect = false;
    
    do{
        CC_BREAK_IF( !BasicLayer::init() );
        setupView();
        sRect = true;
    }while (0);
    
    return sRect;
}

void ReadyLayer::setupView(){
    //add a title
    title_sp = Sprite::createWithSpriteFrameName(STATIC_DATA_STRING("ready"));
    title_sp->setPosition(Point(VISIBLE_SIZE.width / 2, VISIBLE_SIZE.height *2/3));
    title_sp->setScale(1.4f);
    this->addChild(title_sp);
    
    //add a start button
    tap_sp = Sprite::createWithSpriteFrameName(STATIC_DATA_STRING("tap"));
    tap_sp->setPosition(Point(VISIBLE_SIZE.width / 2, VISIBLE_SIZE.height / 2));
    this->addChild(tap_sp);
    
    
}