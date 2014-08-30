#include "DynamicData.h"
#include "StaticData.h"


static DynamicData* ms_shareDynamicData = NULL;

void DynamicData::flush(){
    UserDefault::getInstance()->setBoolForKey("beginner", this->getIsBeginner());
    UserDefault::getInstance()->setIntegerForKey("count", this->getCount());
    //save file
    UserDefault::getInstance()->flush();
    //clean userdefault 
    UserDefault::getInstance()->destroyInstance();
}

bool DynamicData::init(){
    //if beginner not exsit set beginner true
    UserDefault::getInstance()->getBoolForKey("beginner",true);
    if (m_isBeginner == true) {
        this->reset();
        this->flush();
        this->setIsBeginner(false);
    }else{
        m_isBeginner = UserDefault::getInstance()->getBoolForKey("beginner");
        m_count = UserDefault::getInstance()->getIntegerForKey("count");
        //clean userdefault
        UserDefault::getInstance()->destroyInstance();
    }

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
    //don't need flush here
}

void DynamicData::reset(){
    int defalutCount = STATIC_DATA_INT("default_count");

    this->setIsBeginner(true);
    this->setCount(defalutCount);
    //save after alter
    this->flush();
}

void DynamicData::purge(){
    CC_SAFE_RELEASE_NULL(ms_shareDynamicData);
    
}