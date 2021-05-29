/**
* @file Character.h
*/

#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "cocos2d.h"

/**
*@brief ��ɫ�࣬Ԥ�ư�����Һ͹���
*/

class Character : public cocos2d::Sprite
{
public:

    virtual ~Character() = default;


    /**
*@brief ����ͼ����
* @param ָ�򱻰󶨸���ɫ����ľ���
* @author ����
*/
    void bindPictureSprite(cocos2d::Sprite* sprite);


    /**
*@brief ����
* @author ����
*/
    void die();


    /**
*@brief ����������
* @author ����
*/
    virtual bool bindPhysicsBody() = 0;


protected:

    cocos2d::Sprite* sprite_;

    int health_;

    float shield_;

    bool isAlive_ = true;

    float moveSpeed_;

};

#endif // !__CHARACTER_H__
