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
    auto tap_sp_normal = Sprite::createWithSpriteFrameName(STATIC_DATA_STRING("tap"));
    auto tap_sp_selected = Sprite::createWithSpriteFrameName(STATIC_DATA_STRING("tap"));
    auto tapItem = MenuItemSprite::create(tap_sp_normal, tap_sp_selected, CC_CALLBACK_1(ReadyLayer::setBegin, this));
    tapItem->setPosition(Point(VISIBLE_SIZE.width / 2, VISIBLE_SIZE.height / 2));
    auto menu = Menu::createWithItem(tapItem);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    
}


void ReadyLayer::setBegin(Ref* pSender){
    
    this->setVisible(false);
    auto pe_layer = static_cast<PipeLayer*>(this->getParent()->getChildByTag(3));
    pe_layer->setVisible(true);
    pe_layer->resume();
    
    if (DynamicData::shareDynamicData()->getIsBegin()==false) {
        DynamicData::shareDynamicData()->setIsBegin(true);
        
    }
}