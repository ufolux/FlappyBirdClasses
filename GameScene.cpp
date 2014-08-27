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
        CC_BREAK_IF( !Scene::initWithPhysics() );
        
        
        //preload textrue
        this->preloadTextrue();
		
        m_background_layer = BackgroundLayer::create();
        m_background_layer->setPosition(Vec2(VISIBLE_SIZE.width / 2, VISIBLE_SIZE.height / 2));
		this->addChild(m_background_layer, 1, 1);

 		m_floor_layer = FloorLayer::create();
        m_floor_layer->setPosition(Vec2(VISIBLE_SIZE.width / 2, ORINGIN_SIZE.x + m_floor_layer->getContentSize().height / 2));
		this->addChild(m_floor_layer, 2, 2);

		m_bird_layer = BirdLayer::create();
        m_bird_layer->setPosition(Vec2(VISIBLE_SIZE.width / 2, VISIBLE_SIZE.height / 2));
		this->addChild(m_bird_layer, 3, 3);

		m_pipe_layer = PipeLayer::create();
		this->addChild(m_pipe_layer);

		m_pannel_layer = PannelLayer::create();
		this->addChild(m_pannel_layer);

 		m_touch_layer = TouchLayer::create();
		this->addChild(m_touch_layer);
        
        //init physics
        this->createPhysics();
        
        
		sRect = true;

	} while (0);

	return sRect;
}

void GameScene::preloadTextrue(){
    
    
    auto spriteFrameCache = SpriteFrameCache::getInstance();
    spriteFrameCache->addSpriteFramesWithFile(STATIC_DATA_STRING("flappy_plist"), STATIC_DATA_STRING("flappy_textrue"));
    
}


