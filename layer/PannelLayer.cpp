/*for displaying score
 *and game over
 *
 *
 */

#include "PannelLayer.h"

PannelLayer::PannelLayer(){
    
}

PannelLayer::~PannelLayer(){
    
}


bool PannelLayer::init(){
    bool sRect = false;
    
    do{
        CC_BREAK_IF( !BasicLayer::init() );
        setupView();
        sRect = true;
    }while (0);
    
    return sRect;
}


void PannelLayer::setupView(){
    counter_basic = Sprite::create();
    counter_tens = Sprite::create();
    counter_hundred = Sprite::create();
    this->addChild(counter_basic);
    this->addChild(counter_tens);
    this->addChild(counter_hundred);
    
    this->scheduleUpdate();
    
    
}

//max 999
void PannelLayer::displayCounter(int count=0 ){
    if (count>=m_max_count)
        count = m_max_count;
    //char s_str[2];
    char b_str[3];
    int hundredPlace = count/100;
    int tensPlace = count%100/10;
    int basicUnit = count%100%10;
    
    
    if (hundredPlace == 0&&tensPlace == 0) {
        sprintf(b_str, "%db",basicUnit);
        counter_basic->setSpriteFrame(STATIC_DATA_STRING(b_str));
        counter_basic->setPosition(Point(VISIBLE_SIZE.width / 2, VISIBLE_SIZE.height * 3/4.0f));
        float width = counter_basic->getContentSize().width;
        float height = counter_basic->getContentSize().height;
        setCounterSize(Size(width,height));

    
        
    }else if (hundredPlace == 0&&tensPlace != 0){
        this->removeChild(counter_basic);
        sprintf(b_str, "%db",basicUnit);
        counter_basic->setSpriteFrame(STATIC_DATA_STRING(b_str));
        
        sprintf(b_str, "%db",tensPlace);
        counter_tens->setSpriteFrame(STATIC_DATA_STRING(b_str));
        
        float width = counter_basic->getContentSize().width + counter_tens->getContentSize().width;
        float height = counter_basic->getContentSize().height;
        setCounterSize(Size(width,height));
        
        counter_basic->setPosition(Point(VISIBLE_SIZE.width / 2 - width / 3, VISIBLE_SIZE.height * 3 /4.0f));
        counter_tens->setPosition(Point(VISIBLE_SIZE.width / 2 + width / 3, VISIBLE_SIZE.height * 3 /4.0f));
        
        
    }else if (hundredPlace!=0){
        this->removeChild(counter_basic);
        this->removeChild(counter_tens);
        
        sprintf(b_str, "%db",basicUnit);
        counter_basic->setSpriteFrame(STATIC_DATA_STRING(b_str));
        
        sprintf(b_str, "%db",tensPlace);
        counter_tens->setSpriteFrame(STATIC_DATA_STRING(b_str));
        
        sprintf(b_str, "%db",hundredPlace);
        counter_tens->setSpriteFrame(STATIC_DATA_STRING(b_str));
        
        float width = counter_basic->getContentSize().width + counter_tens->getContentSize().width + counter_hundred->getContentSize().width;
        float height = counter_basic->getContentSize().height;
        setCounterSize(Size(width,height));
        
        counter_basic->setPosition(Point(VISIBLE_SIZE.width / 2 - width / 2, VISIBLE_SIZE.height * 3 /4.0f));
        counter_tens ->setPosition(Point(VISIBLE_SIZE.width / 2 , VISIBLE_SIZE.height * 3 /4.0f));
        counter_hundred->setPosition(Point(VISIBLE_SIZE.width / 2 - width / 2, VISIBLE_SIZE.height * 3 /4.0f));

    }
    
}

void PannelLayer::update(float dt){
    int count = DynamicData::shareDynamicData()->getCount();
    displayCounter(count);
    
}



