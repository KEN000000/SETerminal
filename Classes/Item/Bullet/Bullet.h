/**
* @file Bullet.h
*/

#ifndef __BULLET_H__
#define __BULLET_H__

#include "cocos2d.h"
#include "../Item.h"

/**
*@brief �ӵ���
*/

class Bullet : public Item
{
public:

	virtual ~Bullet() = default;

	int getBulletAtk();

	//����һ��Bulletʵ��
	static Bullet* create(const std::string& filename);


	//ΪBullet�������������
	virtual bool bindPhysicsBody();


	//�ӵ�������Ч����������Ч������ը
	void dieEffect();


	//ΪBulletʵ���󶨷��䶯��
	bool shoot(const cocos2d::Vec2 shootDirection, float Speed);

	virtual void interact(){}

	


protected:

	float bulletSpeed_;									//�ӵ������ٶ�

	float bulletRange_;									//�ӵ������о���

	float bulletAtk_ = 10.f;

	//�������ӵ���������
};

#endif // !__BULLET_H__
