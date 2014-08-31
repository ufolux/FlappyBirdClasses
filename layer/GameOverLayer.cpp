 /*for displaying score
  *and game over
  *
  *
  */

#include "GameOverLayer.h"
#include "GameScene.h"

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
    
    //set title
    title_sp = Sprite::createWithSpriteFrameName(STATIC_DATA_STRING("gameover"));
    title_sp->setPosition(Point(VISIBLE_SIZE.width / 2, VISIBLE_SIZE.height*2/3));
    title_sp->setScale(1.4f);
    this->addChild(title_sp);
    
    //add score
    score_sp = Sprite::createWithSpriteFrameName(STATIC_DATA_STRING("score"));
    score_sp->setPosition(Point(VISIBLE_SIZE.width / 2, VISIBLE_SIZE.height / 2));
    
    this->addChild(score_sp);
    
    
    //add button

    auto restart_normal = Sprite::createWithSpriteFrameName(STATIC_DATA_STRING("start"));
    auto restart_selected = Sprite::createWithSpriteFrameName(STATIC_DATA_STRING("start"));
    auto playMenuItem = MenuItemSprite::create(restart_normal, restart_selected, CC_CALLBACK_1(GameOverLayer::setRestart, this));
    playMenuItem->setPosition(Point(VISIBLE_SIZE.width / 2, VISIBLE_SIZE.height/3));
    auto menu = Menu::createWithItem(playMenuItem);
    
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
}

void GameOverLayer::setRestart(Ref* pSender){
    
    this->setVisible(false);
    this->setZOrder(1);
    
    auto bd_layer = static_cast<BirdLayer*>(getParent()->getChildByTag(2));
    auto pe_layer = static_cast<PipeLayer*>(getParent()->getChildByTag(3));
    
    bd_layer->reset();
    pe_layer->reset();
    
    DynamicData::shareDynamicData()->purge();
    Director::getInstance()->resume();
    auto game_scene = GameScene::create();
    Director::getInstance()->replaceScene(TransitionFade::create(0.5f, game_scene));

    
}



