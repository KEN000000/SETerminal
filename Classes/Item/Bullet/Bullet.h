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


	//����һ��Bulletʵ��
	static Bullet* create(const std::string& filename);


	//ΪBullet�������������
	virtual bool bindPhysicsBody();
	
<<<<<<< Updated upstream:Classes/Item/Bullet/Bullet.h
	//�ӵ�������Ч����������Ч������ը
//	void dieEffect();
	
	//ΪBulletʵ���󶨷��䶯��
	bool shoot(const cocos2d::Vec2 shootDirection);
=======

	//�ӵ�������Ч����������Ч������ը
	void dieEffect();
	

	//ΪBulletʵ���󶨷��䶯��
	bool shoot(const cocos2d::Vec2 shootDirection, float Speed);

>>>>>>> Stashed changes:Classes/Item/Bullet.h

protected:

	float bulletSpeed_;									//�ӵ������ٶ�

	float bulletRange_;									//�ӵ������о���

	//�������ӵ���������
};

#endif // !__BULLET_H__
