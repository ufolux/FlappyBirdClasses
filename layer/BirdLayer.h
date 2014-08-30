#pragma once
#define WORLD_GRAVITY STATIC_DATA_FLOAT("gravity")

#include "cocos2d.h"
#include "BasicLayer.h"
#include "math.h"
USING_NS_CC;

class BirdLayer: public BasicLayer{
public:

    typedef enum{
        e_Dead = 0,
        e_Alive = 1
    }PlayerState;
    
    CC_SYNTHESIZE(Sprite*, bd_sp, Bd_sp);
    CC_SYNTHESIZE(bool, is_tap, IsTap);
    CC_SYNTHESIZE(bool, is_val_zero, IsValZero);
    
    virtual bool init();
    
    void setupView();
    
    void addHeight();
    void update(float t);
    //void tapGravitySim(float t);
    CREATE_FUNC(BirdLayer);
    
    
};