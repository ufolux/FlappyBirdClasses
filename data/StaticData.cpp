#include "StaticData.h"
#define STATIC_DATA_PLIST "static_data.plist"

static StaticData* ms_shareStaticData = NULL;

StaticData::StaticData(){
    _staticDataPath = STATIC_DATA_PLIST;
}
StaticData::~StaticData(){
    CC_SAFE_RELEASE_NULL(_dictionary);
}

//interface
const char* StaticData::getStringFromKey(string key){
    return _dictionary->valueForKey(key)->getCString();
}

int StaticData::getIntFromKey(string key){
    return _dictionary->valueForKey(key)->intValue();
}
unsigned int StaticData::getUIntFromKey(string key){
    return _dictionary->valueForKey(key)->uintValue();
}
float StaticData::getFloatFromKey(string key){
    return _dictionary->valueForKey(key)->floatValue();
}
double StaticData::getDoubleFromKey(string key){
    return _dictionary->valueForKey(key)->doubleValue();
}

bool StaticData::getBoolFromKey(string key){
    return _dictionary->valueForKey(key)->boolValue();
}
Size StaticData::getSizeFromKey(string key){
    return SizeFromString(_dictionary->valueForKey(key)->getCString());
}
Point StaticData::getPointFromKey(string key){
    return PointFromString(_dictionary->valueForKey(key)->getCString());
}
Rect StaticData::getRectFromKey(string key){
    return RectFromString(_dictionary->valueForKey(key)->getCString());
}
//

bool StaticData::init(){
    _dictionary = __Dictionary::createWithContentsOfFile(this->getStaticDataPath());
    CC_SAFE_RETAIN(_dictionary);//__dictionary is a autorelease object,so retain it here and release it in destruction func
    return true;
    
}

StaticData* StaticData::shareStaticData(){
    
    if (ms_shareStaticData == NULL) {
        ms_shareStaticData = new StaticData();
        ms_shareStaticData -> init();
    }
    
    return ms_shareStaticData;
}

void StaticData::purge(){
    
    CC_SAFE_RELEASE_NULL(ms_shareStaticData);
}

