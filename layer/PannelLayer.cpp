#include "PannelLayer.h"

bool PannelLayer::init(){
    bool sRect = false;
    
    do{
        CC_BREAK_IF( !BasicLayer::init() );
        
        sRect = true;
    }while (0);
    
    return sRect;
}