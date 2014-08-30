 /*for displaying score
  *and game over
  *
  *
  */

#include "GameOverLayer.h"

bool GameOverLayer::init(){
    bool sRect = false;
    
    do{
        CC_BREAK_IF( !BasicLayer::init() );
        setupView();
        sRect = true;
    }while (0);
    
    return sRect;
}


void GameOverLayer::setupView(){
    
    
    
}


