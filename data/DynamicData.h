#pragma once
#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class DynamicData: public Ref{
public:
    CC_SYNTHESIZE(bool, m_isBeginner, IsBeginner);
    CC_SYNTHESIZE(int, m_count, Count);
    
    static DynamicData* shareDynamicData();
    void purge();
    //write data to file
    void flush();

    //reset all data
    void reset();

    //alter count
    void alterCount(int delta);
private:
    bool init();
};