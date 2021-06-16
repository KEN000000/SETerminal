/**
* @file Obstacle.h
*/

#ifndef __OBSTACLE_H__
#define __OBSTACLE_H__

#include "cocos2d.h"
#include "Character/Character.h"
#include <vector>

class Obstacle: public cocos2d::Node
{
public:
	/**
* @brief ����ͼ����
* @param ָ�򱻰󶨸���Ʒ����ľ���
*/
	static Obstacle* create(const std::string& filename);

	/**
* @brief ���ø����岻�ܱ�����ȥ
*@param ������ײ������ָ�룬�Ƿ��øú�����Ч(Ĭ����Ч)
*/
	void collision(Character* targetSprite, bool flag = true);

	/**
*@brief ����ͼ����
* @param ָ�򱻰󶨸���Ʒ����ľ���
*/
	void bindPictureSprite(cocos2d::Sprite* sprite);


	bool bindPhysicsBody();


	static cocos2d::Vector<Obstacle*> createObsSet(const int& serial);


protected:

	cocos2d::Sprite* sprite_;
};

#endif // !__OBSTACLE_H__