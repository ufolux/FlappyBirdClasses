#pragma once
#include "cocos2d.h"

#define STATIC_DATA_STRING(key) StaticData::shareStaticData()->getStringFromKey(key)
#define STATIC_DATA_INT(key) StaticData::shareStaticData()->getIntFromKey(key)
#define STATIC_DATA_UINT(key) StaticData::shareStaticData()->getUIntFromKey(key)
#define STATIC_DATA_FLOAT(key) StaticData::shareStaticData()->getFloatFromKey(key)
#define STATIC_DATA_DOUBLE(key) StaticData::shareStaticData()->getDoubleFromKey(key)
#define STATIC_DATA_SIZE(key) StaticData::shareStaticData()->getSizeFromKey(key)
#define STATIC_DATA_POINT(key) StaticData::shareStaticData()->getPointFromKey(key)
#define STATIC_DATA_RECT(key) StaticData::shareStaticData()->getRectFromKey(key)

#define SCALE_RATIO 1.4f


USING_NS_CC;
using namespace std;

class StaticData: public Ref{
    
public:
    static StaticData* shareStaticData();
    void purge();
    
    //@interface
    const char* getStringFromKey(string key);
    int getIntFromKey(string key);
    unsigned int getUIntFromKey(string key);
    float getFloatFromKey(string key);
    double getDoubleFromKey(string key);
    
    bool getBoolFromKey(string key);
    
    Size getSizeFromKey(string key);
    Point getPointFromKey(string key);
    Rect getRectFromKey(string key);
    
    //SYNTHESIZE
    CC_SYNTHESIZE_READONLY(const char *, _staticDataPath, StaticDataPath);
    
    
protected:
    __Dictionary* _dictionary;
    
private:
    
    StaticData();
    ~StaticData();
    bool init();
};