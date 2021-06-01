#pragma once
/**
* @file Monster.h
*/

#ifndef MONSTER_H
#define MONSTER_H

#include "cocos2d.h"
#include "Character.h"

/**
*@brief ������
*/

class Monster : public Character
{
public:

	/**
* @brief ����һ��Monsterʵ��
* @param Monsterʵ����Ӧ���ز��ļ���
* @return ָ���Monsterʵ����ָ��
* @author ���ʽ�
*/
	static Monster* create(const std::string& filename);


	/**
* @brief Monster���ƶ��Լ������ӵ�������δ�����Խ����﷢���ӵ���������
* @return ��
* @author ���ʽ�
*/
	void Monster::move();


	/**
* @brief ΪMonster�������������
* @return ���Ƿ�ɹ�
* @author ���ʽ�
*/
	virtual bool bindPhysicsBody();


	/**
* @brief ����һ�����λ�õ�����ֵ
* @return ����һ��Vec2���͵�����(x,y)����
* @author ���ʽ�
*/
	cocos2d::Vec2 getRandomPosition();



	virtual void updateFacingStatus();


	virtual void updateWalkingStatus();


	void update(float dt);


protected:



};




#endif // !MONSTER_H
