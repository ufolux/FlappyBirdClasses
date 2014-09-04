#pragma once
#define WORLD_GRAVITY STATIC_DATA_FLOAT("gravity")

#include "cocos2d.h"
#include "BasicLayer.h"
#include "math.h"
#include "../data/DynamicData.h"

USING_NS_CC;

class BirdLayer: public BasicLayer{
public:

    typedef enum{
        e_Dead = 0,
        e_Alive = 1
    }PlayerState;
    
    CC_SYNTHESIZE(Sprite*, bd_sp, Bd_sp);

    
    virtual bool init();
    
    void setupView();
    
    void addHeight();
    void reset();
    void update(float t);
  
    CREATE_FUNC(BirdLayer);
    

private:
    Vector<SpriteFrame*> spriteFrame;

    
};