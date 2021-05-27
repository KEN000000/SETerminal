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


	/**
* @brief ����һ��Bulletʵ��
* @param Bulletʵ����Ӧ���ز��ļ���
* @return ָ���Bulletʵ����ָ��
* @author ����
*/
	static Bullet* create(const std::string& filename);


	/**
* @brief ΪBullet�������������
* @return ���Ƿ�ɹ�
* @author ����
*/
	virtual bool bindPhysicsBody();

	/**
* @brief ΪBulletʵ���󶨷��䶯��
* @param ָ���䷽��ĵ�λ����
* @return �����Ƿ�ɹ�
* @author ����
*/
	bool shoot(const cocos2d::Vec2 shootDirection);

protected:

	float bulletSpeed_;									//�ӵ������ٶ�

	float bulletRange_;									//�ӵ������о���

	//�������ӵ���������
};

#endif // !__BULLET_H__
