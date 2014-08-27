#include "BasicLayer.h"

bool BasicLayer::init(){
    bool sRect = false;
    
    do{
        CC_BREAK_IF( !Layer::init() );

        sRect = true;
    }while (0);
    
    return sRect;
}

