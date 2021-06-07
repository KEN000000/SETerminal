/**
* @file HelloWorldScene.h
*/

#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

/**
* @brief ��ǽ�ɫ������ͷ��ڵ�tag
*/


#include "cocos2d.h"
#include "Character/Player.h"
#include "Character/Monster.h"
#include "Component/HealthBar/HealthBar.h"
#include "Component/WeaponUI/WeaponUI.h"
#include "Component/CameraEffect/CameraEffect.h"
#include "Item/Bullet/Bullet.h"
#include "Const/Const.h"

class HelloWorld : public cocos2d::Scene
{
private:
    Player* player_;
    //��ͼ��,��Ӧ��ص�tmx�ļ�
    HealthBar* healthBar_;

    WeaponUI* weaponUI_;

    CameraEffect* mainCamera_;

    static cocos2d::Node* generateNode_;

    cocos2d::TMXTiledMap* _tileMap;

    bool TouchHolding = false;
    //��ͼ�е�һ����
    //cocos2d::TMXLayer* _background;
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

    /*
��ʼ�������
    */
    void HelloWorld::setCamera(Scene* scene);

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


    /**
* @brief ��Ӧ�����ڵ�������ײ�����е��˺󣬽�����ɾ��
*/
    bool onContactBegan(cocos2d::PhysicsContact& physicsContact);


    bool onContactSeparated(cocos2d::PhysicsContact& physicsContact);


    void contactBetweenPlayerAndItem(Player* player, Item* Item);
    void contactBetweenCharacterAndBullet(Character* character, Bullet* bullet);


    void generateNode(float dt);

    static cocos2d::Node*& getGenerateNode();
    


    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);


};

#endif // __HELLOWORLD_SCENE_H__
