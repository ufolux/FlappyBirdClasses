//
//  GameScene.cpp
//  fishGame
//
//  Created by NASA on 8/24/14.
//
//
#include "GameScene.h"

GameScene::GameScene(){}
GameScene::~GameScene(){
    this->unscheduleUpdate();
}

bool GameScene::init(){
    bool sRect = false;
    do
    {
        CC_BREAK_IF( !Scene::init() );
        
        
        //preload textrue
        this->preloadTextrue();
        
        m_background_layer = BackgroundLayer::create();
        this->addChild(m_background_layer, 1, 1);
        
        m_pipe_layer = PipeLayer::create();
        this->addChild(m_pipe_layer, 3, 3);
        m_pipe_layer->setVisible(false);
        m_pipe_layer->pause();
        
        
        m_bird_layer = BirdLayer::create();
        this->addChild(m_bird_layer, 3, 2);
        
        
        m_floor_layer = FloorLayer::create();
        this->addChild(m_floor_layer, 3, 4);
        
        
        m_pannel_layer = PannelLayer::create();
        this->addChild(m_pannel_layer, 4, 5);
        
        m_game_over_layer = GameOverLayer::create();
        this->addChild(m_game_over_layer,1);
        m_game_over_layer->setVisible(false);
        
        m_touch_layer = TouchLayer::create();
        this->addChild(m_touch_layer, 5, 6);
        
        
        m_start_layer = StartLayer::create();
        this->addChild(m_start_layer, 10, 7);
        
        m_ready_layer = ReadyLayer::create();
        this->addChild(m_ready_layer, 10, 8);
        m_ready_layer->setVisible(false);
        //
        //schedule
        this->scheduleUpdate();
        
        
        
        sRect = true;
        
    } while (0);
    
    return sRect;
}

void GameScene::preloadTextrue(){
    
    
    auto spriteFrameCache = SpriteFrameCache::getInstance();
    spriteFrameCache->addSpriteFramesWithFile(STATIC_DATA_STRING("flappy_plist"), STATIC_DATA_STRING("flappy_textrue"));
    
}


bool GameScene::isCollission(){
    auto birdRect = m_bird_layer->getBd_sp()->getBoundingBox();
    
    auto floor1Rect = m_floor_layer->getFr_sp1()->getBoundingBox();
    auto floor2Rect = m_floor_layer->getFr_sp2()->getBoundingBox();
    
    auto pipe1Rect = m_pipe_layer->getPe_sp1()->getBoundingBox();
    auto pipe2Rect = m_pipe_layer->getPe_sp2()->getBoundingBox();
    auto pipe3Rect = m_pipe_layer->getPe_sp3()->getBoundingBox();
    auto pipe4Rect = m_pipe_layer->getPe_sp4()->getBoundingBox();
    
    if (birdRect.intersectsRect(floor1Rect)||birdRect.intersectsRect(floor2Rect)) {
        return true;
    }else
        if(birdRect.intersectsRect(pipe1Rect)||birdRect.intersectsRect(pipe2Rect)||birdRect.intersectsRect(pipe3Rect)||birdRect.intersectsRect(pipe4Rect)){
            return true;
        }else{
            return false;
        }
}

void GameScene::update(float dt){
    
    if (DynamicData::shareDynamicData()->getIsBegin()) {
        auto bd_sp = m_bird_layer->getBd_sp();
        if(isCollission()){
            
            Director::getInstance()->pause();
            bd_sp->setSpriteFrame(STATIC_DATA_STRING("birdDead"));
            DynamicData::shareDynamicData()->setIsBegin(false);
            m_game_over_layer->setVisible(true);
            m_game_over_layer->setZOrder(12);
        }
        alterCount();
    }
    
    
    
    
}




bool GameScene::isPass(){
    
    bool sRet = false;
    if (DynamicData::shareDynamicData()->getIsBegin()) {
        /*todo*/
        Sprite* pipe = m_pipe_layer->getPipeDisplay();
        auto bird = m_bird_layer->getBd_sp();
        
        auto birdX = bird->getPositionX() - bird->getContentSize().width/2;
        
        if (pipe==NULL) {
            return sRet;
        }
        auto pipeX = pipe->getPositionX() + 100;
        if (std::abs(birdX-pipeX) < 1.f) {
            sRet = true;
        }
        
    }
    
    
    return sRet;
}

void GameScene::alterCount(){
    if(isPass()){
        DynamicData::shareDynamicData()->alterCount(1);
    }
}



