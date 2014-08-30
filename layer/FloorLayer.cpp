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
    
    fr_sp1 = Sprite::createWithSpriteFrameName(STATIC_DATA_STRING("floor"));
    fr_sp2 = Sprite::createWithSpriteFrameName(STATIC_DATA_STRING("floor"));
    
    fr_sp1->setAnchorPoint(Point(0.f, 0.f));
    fr_sp2->setAnchorPoint(Point(0.f, 0.f));
    
    fr_sp1->setPosition(Point(ORINGIN_SIZE.x, ORINGIN_SIZE.y));
    fr_sp2->setPosition(Point((ORINGIN_SIZE.x + fr_sp1->getContentSize().width), ORINGIN_SIZE.y));
    
    fr_sp1->setTag(8);
    fr_sp2->setTag(9);
    
    this->addChild(fr_sp1);
    this->addChild(fr_sp2);
    
    schedule(schedule_selector(FloorLayer::scrollFloor), STATIC_DATA_FLOAT("floorDelay"));
}

//Carmack卷轴
void FloorLayer::scrollFloor(float t){
    auto deltaX = STATIC_DATA_INT("speedX");
    fr_sp1->setPositionX(fr_sp1->getPositionX() - deltaX);
    fr_sp2->setPositionX(fr_sp1->getPositionX()+fr_sp1->getContentSize().width);

    //防止跳过
    if (fr_sp1->getPositionX() + fr_sp1->getContentSize().width  < 10 ) {
        fr_sp1->setPositionX(ORINGIN_SIZE.x);
        fr_sp2->setPositionX(ORINGIN_SIZE.x + fr_sp1->getContentSize().width);
    }
        
    
    
    
}