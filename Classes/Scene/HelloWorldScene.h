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

#include "cocos2d.h"
#include "./Character/Player.h"

class HelloWorld : public cocos2d::Scene
{
private:
    Player* player_;
    //��ͼ��,��Ӧ��ص�tmx�ļ�
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


    /**
* @brief ��Ӧ�����ڵ�������ײ
*/
    bool onContactBegan(cocos2d::PhysicsContact& physicsContact);


    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
