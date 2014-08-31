#pragma once

#include "cocos2d.h"
#include "BasicLayer.h"
#include <time.h>
#include <cstdlib>

#define DIV VISIBLE_SIZE.width + 100
USING_NS_CC;


struct PipeY{
    float up;
    float down;
};

class PipeLayer: public BasicLayer{
public:
    virtual bool init();
    void setupView();
    void scrollPipe(float t);
    Sprite* getPipeDisplay();
    void reset();
    CREATE_FUNC(PipeLayer);
    
    
    CC_SYNTHESIZE(Sprite*, pe_sp1, Pe_sp1);
    CC_SYNTHESIZE(Sprite*, pe_sp2, Pe_sp2);
    CC_SYNTHESIZE(Sprite*, pe_sp3, Pe_sp3);
    CC_SYNTHESIZE(Sprite*, pe_sp4, Pe_sp4);
    
    CC_SYNTHESIZE(bool, is_pe_sp1_2_display, IsPeSp1_2Display);
    CC_SYNTHESIZE(bool, is_pe_sp3_4_display, IsPeSp3_4Display);
    
protected:
    
    
    PipeY randomPipeY();
    
    Vector<Sprite*> pe_sp;
};