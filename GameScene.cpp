//
//  GameScene.cpp
//  fishGame
//
//  Created by NASA on 8/24/14.
//
//
#include "GameScene.h"

static bool isPassFlag = false;

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
    spriteFrameCache->addSpriteFramesWithFile(STATIC_DATA_STRING("flappy_plist"),
                                              STATIC_DATA_STRING("flappy_textrue"));
}


bool GameScene::isCollission(){
    auto birdRect = m_bird_layer->getBd_sp()->getBoundingBox();
    
    auto floor1Rect = m_floor_layer->getFr_sp1()->getBoundingBox();
    auto floor2Rect = m_floor_layer->getFr_sp2()->getBoundingBox();
    
    auto pipe1Rect = m_pipe_layer->getPe_sp1()->getBoundingBox();
    auto pipe2Rect = m_pipe_layer->getPe_sp2()->getBoundingBox();
    auto pipe3Rect = m_pipe_layer->getPe_sp3()->getBoundingBox();
    auto pipe4Rect = m_pipe_layer->getPe_sp4()->getBoundingBox();
    //is beyond top
    if (m_bird_layer->getBd_sp()->getPositionY()+30 > VISIBLE_SIZE.height) {
        DynamicData::shareDynamicData()->setIsAtTop(true);
    }else{
        DynamicData::shareDynamicData()->setIsAtTop(false);
    }
    //is collision
    if (birdRect.intersectsRect(floor1Rect)||birdRect.intersectsRect(floor2Rect)) {
        return true;
    }else if(birdRect.intersectsRect(pipe1Rect)||birdRect.intersectsRect(pipe2Rect)||birdRect.intersectsRect(pipe3Rect)||birdRect.intersectsRect(pipe4Rect)){
        return true;
    }else{
        return false;
    }
    
    
}

void GameScene::update(float dt){
    
    if (DynamicData::shareDynamicData()->getIsBegin()) {
        auto bd_sp = m_bird_layer->getBd_sp();
        if(isCollission()){
            
            m_floor_layer->unscheduleAllSelectors();
            m_pipe_layer->unscheduleAllSelectors();
            
            
            auto moveDown = MoveTo::create(0.1f, Point(VISIBLE_SIZE.width/3, m_floor_layer->getFr_sp1()->getContentSize().height+40));
            auto rotateDown = RotateTo::create(0.05, 90);
            auto spawn = Spawn::createWithTwoActions(moveDown, rotateDown);
            
            auto sequence = Sequence::create(DelayTime::create(0.1f),spawn,DelayTime::create(0.1f),NULL);
            bd_sp->runAction(sequence);
            bd_sp->setSpriteFrame(STATIC_DATA_STRING("birdDead"));
            
            DynamicData::shareDynamicData()->setIsBegin(false);
            

            
            m_game_over_layer->setVisible(true);
            m_game_over_layer->setZOrder(12);
            m_bird_layer->unscheduleAllSelectors();

            
        }
        alterCount();

    }

}



bool GameScene::isPass(){
    
    bool sRet = false;
    if (DynamicData::shareDynamicData()->getIsBegin()&&!isPassFlag) {
        /*todo*/
        Sprite* pipe = m_pipe_layer->getPipeDisplay();
        auto bird = m_bird_layer->getBd_sp();
        
        auto birdX = bird->getPositionX() - bird->getContentSize().width/2;
        
        if (pipe == NULL) {
            return sRet;
        }
        auto pipeX = pipe->getPositionX() + 100;
        if (std::abs(birdX-pipeX) < 4.f) {
            
            sRet = true;
            setIsPassFlag(true);
        }
        
    }
    
    
    return sRet;
}

void GameScene::alterCount(){
    if(isPass()){
        DynamicData::shareDynamicData()->alterCount(1);
    }
}


bool GameScene::getIsPassFlag(){
    return isPassFlag;
}

void GameScene::setIsPassFlag(bool isPass){
    isPassFlag = isPass;
    
}


