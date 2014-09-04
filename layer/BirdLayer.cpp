
#include "BirdLayer.h"
static float ms_dropHeight = 0.f;
static float Time1 = 0.f;
static float Time2 = 0.f;

bool BirdLayer::init(){
    bool sRect = false;
    
    do{
        CC_BREAK_IF( !BasicLayer::init() );
        setupView();
        sRect = true;
    }while (0);
    
    return sRect;
}

void BirdLayer::setupView(){
    bd_sp = Sprite::createWithSpriteFrameName(STATIC_DATA_STRING("bird1"));
    
    bd_sp->setPosition(VISIBLE_SIZE.width / 3, VISIBLE_SIZE.height / 2);
    

    spriteFrame.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(STATIC_DATA_STRING("bird1")));
    spriteFrame.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(STATIC_DATA_STRING("bird2")));
    spriteFrame.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(STATIC_DATA_STRING("bird3")));
    
    auto animation = Animation::createWithSpriteFrames(spriteFrame, 0.2f);
    auto animate = Animate::create(animation);
    
    bd_sp -> runAction(RepeatForever::create(animate));
    
    
    
    bd_sp->setTag(7);
    this->addChild(bd_sp);
    
    this->schedule(schedule_selector(BirdLayer::update),STATIC_DATA_FLOAT("floorDelay"));
}

//tap to add height
/*need to modify
 *some bad experience
 *
 *
 */
void BirdLayer::addHeight(){

    if (DynamicData::shareDynamicData()->getIsBegin()&&!DynamicData::shareDynamicData()->getIsAtTop()) {
        
        float deltaHeight = STATIC_DATA_FLOAT("tapDeltaHeight");

        auto moveUp = MoveTo::create(0.05f, Point(bd_sp->getPositionX(),bd_sp->getPositionY()+deltaHeight));
        auto rotateUp = RotateTo::create(0.1f, -30.f);
        
        auto spawn = Spawn::createWithTwoActions(moveUp, rotateUp);
        bd_sp->runAction(spawn);
        
        //bd_sp->runAction(rotateDown);
        Time1 = 0.f;
        Time2 = 0.f;
        ms_dropHeight = 0.f;
        
        auto rotateDown = RotateTo::create(0.1f, 30.f);
        auto sequence = Sequence::createWithTwoActions(DelayTime::create(0.1f), rotateDown);
        bd_sp->runAction(sequence);

    }

}
//simulate move
void BirdLayer::update(float t){
    if (DynamicData::shareDynamicData()->getIsBegin()) {
    
        Time2 += STATIC_DATA_FLOAT("floorDelay");
        Time1 = Time2 - STATIC_DATA_FLOAT("floorDelay");
        float squreDelta = (Time2 + Time1)*(Time2 - Time1);
        float deltaHeightPerUnit = 1/2.f * WORLD_GRAVITY*(squreDelta);
        ms_dropHeight += deltaHeightPerUnit;
        bd_sp->setPositionY(bd_sp->getPositionY()+ms_dropHeight);
    }
}

void BirdLayer::reset(){
    ms_dropHeight = 0.f;
    Time1 = 0.f;
    Time2 = 0.f;
}

