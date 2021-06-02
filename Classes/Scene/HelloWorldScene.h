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
#include "Component/HealthBar/HealthBar.h"

class HelloWorld : public cocos2d::Scene
{
private:
    Player* player_;
    //��ͼ��,��Ӧ��ص�tmx�ļ�
<<<<<<< Updated upstream
    cocos2d::TMXTiledMap* _tileMap;
    //��ͼ�е�һ����
    cocos2d::TMXLayer* _background;
=======
    HealthBar* healthBar_;
    cocos2d::TMXTiledMap* _tileMap;
    //��ͼ�е�һ����
    cocos2d::TMXLayer* _background;

    cocos2d::Vec2 TouchLocation;

    bool TouchHolding = false;
>>>>>>> Stashed changes
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

    /*
    ��������굥��������
    */
    bool onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* unusedEvent);


    void onMouseMove(cocos2d::EventMouse* mouse);


    void onMouseMove(cocos2d::EventMouse* mouse);

    /**
* @brief ��Ӧ�����ڵ�������ײ�����е��˺󣬽�����ɾ��
*/
    bool onContactBegan(cocos2d::PhysicsContact& physicsContact);


    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);


};

#endif // __HELLOWORLD_SCENE_H__
