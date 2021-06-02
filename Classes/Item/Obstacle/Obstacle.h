/**
* @file Obstacle.h
*/

#ifndef __OBSTACLE_H__
#define __OBSTACLE_H__

#include "cocos2d.h"
#include "../Item.h"

class Obstacle: public Item
{
public:
	/**
* @brief ����ͼ����
* @param ָ�򱻰󶨸���Ʒ����ľ���
*/
	static Obstacle* create(const std::string& filename);


	/**
*@brief ����������
*/
	virtual bool bindPhysicsBody();


	/**
* @brief ���ø����岻�ܱ�����ȥ
*@param ������ײ������ָ�룬�Ƿ��øú�����Ч(Ĭ����Ч)
*/
	void collision(Sprite* targetSprite, bool flag = true);


	/**
*@brief ����
*/
	virtual void interact() {};
};

#endif // !__WEAPON_H__