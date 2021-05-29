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
*@brief ����������
* @author ����
*/
    virtual bool bindPhysicsBody() = 0;


protected:

    cocos2d::Sprite* sprite_;

};

#endif // !__CHARACTER_H__
