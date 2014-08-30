 /*for displaying score
  *and game over
  *
  *
  */

#include "GameOverLayer.h"

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
    replay_sp = Sprite::createWithSpriteFrameName(STATIC_DATA_STRING("start"));
    replay_sp->setPosition(Point(VISIBLE_SIZE.width / 2, VISIBLE_SIZE.height / 3));
    this->addChild(replay_sp);
}


