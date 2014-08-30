//
//  BeginLayer.h
//  fishGame
//
//  Created by NASA on 8/24/14.
//
//

#pragma once

#include <stdio.h>
#include "cocos2d.h"
#include "data/StaticData.h"
#include "data/DynamicData.h"

#include "layer/BackgroundLayer.h"
#include "layer/FloorLayer.h"
#include "layer/BirdLayer.h"
#include "layer/PipeLayer.h"
#include "layer/PannelLayer.h"
#include "layer/TouchLayer.h"
#include "layer/BasicLayer.h"
#include "layer/StartLayer.h"
#include "layer/GameOverLayer.h"
#include "layer/ReadyLayer.h"

USING_NS_CC;

class GameScene: public Scene{
    
public:

    
    bool init();
    bool isCollission();
    bool isPass();
    void alterCount();
    void preloadTextrue();
    void update(float t);
    CREATE_FUNC(GameScene);
private:
	GameScene();
	~GameScene();
    
    
protected:
	BackgroundLayer* m_background_layer;
	FloorLayer* m_floor_layer;
	BirdLayer* m_bird_layer;
	PipeLayer* m_pipe_layer;
	PannelLayer* m_pannel_layer;
	TouchLayer* m_touch_layer;
    StartLayer* m_start_layer;
    GameOverLayer* m_game_over_layer;
    ReadyLayer* m_ready_layer;
    
};






