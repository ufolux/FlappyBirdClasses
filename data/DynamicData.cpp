#include "DynamicData.h"
#include "StaticData.h"


static DynamicData* ms_shareDynamicData = NULL;

void DynamicData::flush(){
    
    UserDefault::getInstance()->setIntegerForKey("maxCount", this->getMaxCount());
    //save file
    UserDefault::getInstance()->flush();
    //clean userdefault
    UserDefault::getInstance()->destroyInstance();
}

bool DynamicData::init(){
    //if beginner not exsit set beginner true
    
    setIsBegin(false);
    m_max_count = UserDefault::getInstance()->getIntegerForKey("maxCount");
    //clean userdefault
    UserDefault::getInstance()->destroyInstance();
    
    
    return true;
}

DynamicData* DynamicData::shareDynamicData(){
    
    if (ms_shareDynamicData == NULL) {
        ms_shareDynamicData = new DynamicData();
        ms_shareDynamicData -> init();
    }
    
    return ms_shareDynamicData;
}

void DynamicData::alterCount(int delta){
    
    int count = this->getCount();
    this->setCount(count+delta);
    if (count>getCount()) {
        setMaxCount(count);
    }
    //don't need flush here
}



void DynamicData::purge(){
    CC_SAFE_RELEASE_NULL(ms_shareDynamicData);
    
}