//
//  BeginLayer.cpp
//  fishGame
//
//  Created by NASA on 8/24/14.
//
//

#include "BeginScene.h"

BeginScene::BeginScene(){}
BeginScene::~BeginScene(){}
bool BeginScene::init(){
    bool sRect = false;
    
    do{
        CC_BREAK_IF( !Scene::init() );
        m_start_layer = StartLayer::create();
        
        CC_BREAK_IF( !m_start_layer );
        this->addChild(m_start_layer);
        
        sRect = true;
    }while (0);
    
    return sRect;
}

