#pragma once
/**
* @file Monster.h
*/

#ifndef MONSTER_H
#define MONSTER_H

#include "cocos2d.h"
#include "Const/Const.h"
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
* @author ���ʽܡ�������
*/
	static Monster* create(const std::string& filename);
	static Monster* create(enemyType_ type);

	/**
* @brief Monster���ƶ��Լ������ӵ�������δ�����Խ����﷢���ӵ���������
* @return ��
* @author ���ʽܡ�������
*/
	void Monster::move();


	virtual void die();


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


	virtual void receiveDamage(int damage);

	virtual void updateFacingStatus();


	virtual void updateWalkingStatus();


	void update(float dt);


protected:

	float MoveTime;

	int Health;

	int ShootFreq;

};




#endif // !MONSTER_H
