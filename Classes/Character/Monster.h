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
* @author ���ʽ�
*/
	static Monster* create(const std::string& filename);
	static Monster* create(enemyType_ type);

	/**
* @brief Monster���ƶ��Լ������ӵ�������δ�����Խ����﷢���ӵ���������
* @return ��
* @author ���ʽ�
*/
	void move();

	void shoot();

	virtual void die();


	/**
* @brief ΪMonster�������������
* @return ���Ƿ�ɹ�
* @author ���ʽ�
*/
	virtual bool bindPhysicsBody();


	virtual void receiveDamage(int damage);

	virtual void updateFacingStatus();


	virtual void updateWalkingStatus();


	void update(float dt);

	static bool isPlayerSuperDamage_;

protected:

	int ShootFreq;

	enemyType_ typeOfThisMonster;

	bool autoShoot = false;

	float shootGap = 2.f;

};




#endif // !MONSTER_H
