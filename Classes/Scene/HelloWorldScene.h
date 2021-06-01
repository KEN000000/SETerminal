/**
* @file HelloWorldScene.h
*/

#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

/**
* @brief ��ǽ�ɫ������ͷ��ڵ�tag
*/
#define ME 100
#define ENEMY 200
#define ME_BULLET 10
#define ENEMY_BULLET 20
#define ITEM 50

#include "cocos2d.h"
#include "Character/Player.h"
#include "Character/Monster.h"
#include "Component/HealthBar/HealthBar.h"

class HelloWorld : public cocos2d::Scene
{
private:
    Player* player_;
    //��ͼ��,��Ӧ��ص�tmx�ļ�
    HealthBar* healthBar_;
    cocos2d::TMXTiledMap* _tileMap;
    //��ͼ�е�һ����
    cocos2d::TMXLayer* _background;
public:

    /**
* @brief ��������ʵ��
* @return ָ�����ɵĳ�����ָ��
*/
    static cocos2d::Scene* createScene();


    /**
* @brief ��ʼ������
* @return ��ʼ���Ƿ�ɹ�
*/
    virtual bool init();


    /**
* @brief ���ɹ���
*/
    void addMonster(float dt);


    /**
* @brief ��Ӧ�����ڵ���Ļ����������굥����
*/
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unusedEvent);


    void onMouseMove(cocos2d::EventMouse* mouse);


    /**
* @brief ��Ӧ�����ڵ�������ײ�����е��˺󣬽�����ɾ��
*/
    bool onContactBegan(cocos2d::PhysicsContact& physicsContact);


    bool onContactSeparated(cocos2d::PhysicsContact& physicsContact);


    void contactBetweenPlayerAndItem(Player* player, Item* Item);
    void contactBetweenPlayerAndBullet(Player* player, cocos2d::Sprite* bullet);
    void contactBetweenMonsterAndBullet(Monster* monster, cocos2d::Sprite* bullet);


    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);


};

#endif // __HELLOWORLD_SCENE_H__
