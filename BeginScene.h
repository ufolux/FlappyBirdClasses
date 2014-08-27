//
//  BeginLayer.h
//  fishGame
//
//  Created by NASA on 8/24/14.
//
//

#ifndef __fishGame__BeginLayer__
#define __fishGame__BeginLayer__

#include <stdio.h>
#include "cocos2d.h"
#include "layer/StartLayer.h"

USING_NS_CC;

class BeginScene: public Scene{
    
public:
    
    BeginScene();
    ~BeginScene();
    
    bool init();
  
    static Scene* scene();
    
    CREATE_FUNC(BeginScene);
protected:
    StartLayer* m_start_layer;
};




#endif /* defined(__fishGame__BeginLayer__) */
