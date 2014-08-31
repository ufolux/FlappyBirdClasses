//
//  StartLayer.cpp
//  fishGame
//
//  Created by NASA on 8/26/14.
//
//

#include "StartLayer.h"

bool StartLayer::init(){
    bool sRect = false;
    
    do{
        CC_BREAK_IF( !BasicLayer::init() );
        setupView();
        sRect = true;
    }while (0);
    
    return sRect;
}

void StartLayer::setupView(){
    //add a title
    title_sp = Sprite::createWithSpriteFrameName(STATIC_DATA_STRING("main"));
    title_sp->setPosition(Point(VISIBLE_SIZE.width / 2, VISIBLE_SIZE.height *3/4));
    title_sp->setScale(1.4f);
    this->addChild(title_sp);
    
    //add a start button
    auto playMenuNormal = Sprite::createWithSpriteFrameName(STATIC_DATA_STRING("start"));
    auto playMenuSelect = Sprite::createWithSpriteFrameName(STATIC_DATA_STRING("start"));
    auto playMenuItem = MenuItemSprite::create(playMenuNormal, playMenuSelect, CC_CALLBACK_1(StartLayer::setBegin, this));
    playMenuItem->setPosition(VISIBLE_SIZE.width / 2, VISIBLE_SIZE.height / 3);
    auto menu = Menu::createWithItem(playMenuItem);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    
    
}


void StartLayer::setBegin(Ref* pSender){
    
    this->setVisible(false);
    auto ry_layer = static_cast<ReadyLayer*>(this->getParent()->getChildByTag(8));
    
    ry_layer->setVisible(true);

}


