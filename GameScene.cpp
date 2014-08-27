//
//  GameScene.cpp
//  fishGame
//
//  Created by NASA on 8/24/14.
//
//
#include "GameScene.h"

GameScene::GameScene(){}
GameScene::~GameScene(){}

bool GameScene::init(){
	bool sRect = false;
	do
	{
        CC_BREAK_IF( !Scene::init() );
        
        
        //preload textrue
        this->preloadTextrue();
		
        m_background_layer = BackgroundLayer::create();
		this->addChild(m_background_layer, 1, 1);

        m_bird_layer = BirdLayer::create();
        this->addChild(m_bird_layer, 3, 2);
        
        m_pipe_layer = PipeLayer::create();
        this->addChild(m_pipe_layer, 3, 3);
        
 		m_floor_layer = FloorLayer::create();
        this->addChild(m_floor_layer, 3, 4);

		
		m_pannel_layer = PannelLayer::create();
		this->addChild(m_pannel_layer, 4, 5);

 		m_touch_layer = TouchLayer::create();
		this->addChild(m_touch_layer, 5, 6);
        
        //init physics
       
        
        
		sRect = true;

	} while (0);

	return sRect;
}

void GameScene::preloadTextrue(){
    
    
    auto spriteFrameCache = SpriteFrameCache::getInstance();
    spriteFrameCache->addSpriteFramesWithFile(STATIC_DATA_STRING("flappy_plist"), STATIC_DATA_STRING("flappy_textrue"));
    
}


