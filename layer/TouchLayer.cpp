#include "TouchLayer.h"

bool TouchLayer::init(){
    bool sRect = false;
    
    do{
        CC_BREAK_IF( !BasicLayer::init() );
        
        touchEventHandler();
        
        sRect = true;
    }while (0);
    
    return sRect;
}



void TouchLayer::touchEventHandler(){
    
    auto eventDispatcher = Director::getInstance()->getEventDispatcher();
    eventDispatcher->setEnabled(true);
    
    auto m_touchListener = EventListenerTouchOneByOne::create();
    m_touchListener->setSwallowTouches(true);
    
    m_touchListener->onTouchBegan = [&](Touch* touch, Event* event){
        

        if (DynamicData::shareDynamicData()->getIsBegin() == true) {
            auto birdLayer = static_cast<BirdLayer*>(this->getParent()->getChildByTag(2));
            birdLayer->addHeight();
        }

        
        return true;
    };
    
    m_touchListener->onTouchMoved = [](Touch* touch, Event* event){
        
    };
    
    m_touchListener->onTouchEnded = [](Touch* touch, Event* event){
        
    };
    
    auto _eventDispatcher = EventDispatcher();
    
    eventDispatcher->addEventListenerWithSceneGraphPriority(m_touchListener, this);
    
}