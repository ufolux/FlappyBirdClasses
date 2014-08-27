//
//  StartLayer.cpp
//  fishGame
//
//  Created by NASA on 8/26/14.
//
//

#include "StartLayer.h"

bool StartLayer::init(){
    bool sRect = false;
    
    do{
        CC_BREAK_IF( !BasicLayer::init() );
        
        sRect = true;
    }while (0);
    
    return sRect;
}