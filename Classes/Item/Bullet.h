/**
* @file Bullet.h
*/

#ifndef __BULLET_H__
#define __BULLET_H__

#include "cocos2d.h"

/**
*@brief �ӵ���
*/

class Bullet : public cocos2d::Sprite
{
public:

	/**
* @brief ����һ��Bulletʵ��
* @param Bulletʵ����Ӧ���ز��ļ���
* @return ָ���Bulletʵ����ָ��
*/
	static Bullet* create(const std::string& filename);


	/**
* @brief ΪBulletʵ���󶨷��䶯��
* @param ָ���䷽��ĵ�λ����
* @return �����Ƿ�ɹ�
*/
	bool shoot(const cocos2d::Vec2 shootDirection);

protected:

	cocos2d::Sprite* sprite_;

	float bulletSpeed_;									//�ӵ������ٶ�

	float bulletRange_;									//�ӵ������о���

	//�������ӵ���������
};

#endif // !__BULLET_H__
