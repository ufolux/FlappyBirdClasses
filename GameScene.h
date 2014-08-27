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

USING_NS_CC;

class GameScene: public Scene{
    
public:
    CC_SYNTHESIZE(PhysicsBody*, bird_body, BirdBody);
    CC_SYNTHESIZE(PhysicsBody*, floor_body, FloorBody);
    CC_SYNTHESIZE(PhysicsBody*, pipe_body, PipeBody);
    
    bool init();
    void createPhysics();
    void preloadTextrue();
    
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
    
    
};






