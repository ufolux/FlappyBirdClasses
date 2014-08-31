#include "PipeLayer.h"

bool PipeLayer::init(){
    bool sRect = false;
    
    do{
        CC_BREAK_IF( !BasicLayer::init() );
        setupView();
        sRect = true;
    }while (0);
    
    return sRect;
}


void PipeLayer::setupView(){
    
    pe_sp1 = Sprite::createWithSpriteFrameName(STATIC_DATA_STRING("pipe"));
    pe_sp2 = Sprite::createWithSpriteFrameName(STATIC_DATA_STRING("pipe"));
    pe_sp3 = Sprite::createWithSpriteFrameName(STATIC_DATA_STRING("pipe"));
    pe_sp4 = Sprite::createWithSpriteFrameName(STATIC_DATA_STRING("pipe"));
    

    pe_sp.pushBack(pe_sp1);
    pe_sp.pushBack(pe_sp2);
    pe_sp.pushBack(pe_sp3);
    pe_sp.pushBack(pe_sp4);
    
    static int i = 1;
    i=1;
    for (auto& pe_obj:pe_sp) {
        
        if (i <= pe_sp.size()) {
            //1,3在下，2，4在上
            if ( 0 == i % 2 ) {
                pe_obj->setAnchorPoint(Point(0.f, 0.f));
            }else{
                
                pe_obj->setAnchorPoint(Point(0.f, 1.0f));
            }
            pe_obj->setTag(i+9);
            this->addChild(pe_obj);
            i++;
        }
        
    }
    
    i = 0;
    //set first positionX, Y
    pe_sp1 -> setPositionX(VISIBLE_SIZE.width+1500);
    pe_sp2->setPositionX(VISIBLE_SIZE.width+1500);//开始时在屏幕外
    
    PipeY pipeY = randomPipeY();
    pe_sp1->setPositionY(pipeY.down);//总长度
    pe_sp2->setPositionY(pipeY.up);

    /*这里把原本分开的几个管道看作是两个相连的物体
     *
     *设置一个间隔，简化问题
     *
     **/
    //设置初始间隔
    pe_sp3->setPositionX(pe_sp1->getPositionX() + DIV);//VISIBLE_SIZE.width);
    pe_sp4->setPositionX(pe_sp2->getPositionX()+DIV);// VISIBLE_SIZE.width);
    pe_sp3->setPositionY(pipeY.down);//总长度
    pe_sp4->setPositionY(pipeY.up);
    
    
    //set scroll
    schedule(schedule_selector(PipeLayer::scrollPipe), STATIC_DATA_FLOAT("floorDelay"));
    
    
    
}

//Carmack scroll callback
/**
 *将两个管子＋间隔 接起来
 *然后卡马克卷轴算法
 *然后根据情况微调边界判断
 *
 *
 */
void PipeLayer::scrollPipe(float t){
    
    if (DynamicData::shareDynamicData()->getIsBegin()) {
        //标记是否显示
        /*
         */
        if ((pe_sp1->getPositionX() + 100 < ORINGIN_SIZE.x||pe_sp1->getPositionX()> VISIBLE_SIZE.width)&&(pe_sp2->getPositionX() + 100 < ORINGIN_SIZE.x||pe_sp2->getPositionX()> VISIBLE_SIZE.width )) {
            setIsPeSp1_2Display(false);
        }else{
            setIsPeSp1_2Display(true);
        }
        
        if ((pe_sp3->getPositionX()+100< ORINGIN_SIZE.x||pe_sp3->getPositionX()> VISIBLE_SIZE.width)&&(pe_sp4->getPositionX()+100 < ORINGIN_SIZE.x||pe_sp4->getPositionX()> VISIBLE_SIZE.width )) {
            setIsPeSp3_4Display(false);
        }else{
            setIsPeSp3_4Display(true);
        }
        
        auto deltaX = STATIC_DATA_INT("speedX");
        
        pe_sp1->setPositionX(pe_sp1->getPositionX() - deltaX);
        pe_sp2->setPositionX(pe_sp2->getPositionX() - deltaX);
        
        pe_sp3->setPositionX(pe_sp1->getPositionX() + DIV);
        pe_sp4->setPositionX(pe_sp2->getPositionX() + DIV);
        
        //判断sp1,sp2有无到达边界
        if (pe_sp1->getPositionX()+pe_sp1->getContentSize().width+100+DIV<= ORINGIN_SIZE.x&&pe_sp2->getPositionX()+pe_sp2->getContentSize().width+100+DIV <= ORINGIN_SIZE.x) {
            //设置sp1，sp2从边界开始
            pe_sp1->setPositionX(VISIBLE_SIZE.width+150);
            pe_sp2->setPositionX(VISIBLE_SIZE.width+150);
            pe_sp3->setPositionX(VISIBLE_SIZE.width+DIV);
            pe_sp4->setPositionX(VISIBLE_SIZE.width+DIV);
        }
        //set height
        if (!getIsPeSp3_4Display()) {
            PipeY pipeY = randomPipeY();
            pe_sp3->setPositionY(pipeY.down);//总长度
            pe_sp4->setPositionY(pipeY.up);
        }
        
        if (!getIsPeSp1_2Display()) {
            PipeY pipeY = randomPipeY();
            pe_sp1->setPositionY(pipeY.down);//总长度
            pe_sp2->setPositionY(pipeY.up);
        }

    }
    
}



PipeY PipeLayer::randomPipeY(){
    PipeY pipeY;
    
    auto gap = 180;//空隙大小
    srand(time(NULL));
    auto randomDownYRatio = ((rand() % 60) + 30) / 100.0 ;
    auto randomUpYRation = 1 - randomDownYRatio;
    
    pipeY.down = randomDownYRatio*(VISIBLE_SIZE.height - gap);//总长度
    pipeY.up = VISIBLE_SIZE.height-randomUpYRation*(VISIBLE_SIZE.height - gap);
    
    return pipeY;
    
}

Sprite*  PipeLayer::getPipeDisplay(){
    
    if (getIsPeSp1_2Display()) {
        
        return getPe_sp1();
    }else if(getIsPeSp3_4Display()){

        return getPe_sp3();
    }else{
        
        return NULL;
    }
}


void PipeLayer::reset(){
    setIsPeSp1_2Display(false);
    setIsPeSp3_4Display(false);
}
