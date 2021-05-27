#pragma once
/**
* @file Monster.h
*/

#ifndef MONSTER_H
#define MONSTER_H

#include "cocos2d.h"
#include "./Item/Weapon.h"
#include "Character.h"
#include <string>

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
	static Monster* create(const std::string& filename, float sizeX, float sizeY);


	/**
* @brief ΪMonster�������������
* @return ���Ƿ�ɹ�
* @author ���ʽ�
*/
	void Monster::move(float sizeX, float sizeY, cocos2d::Vec2 playerPostion);


	/**
* @brief ΪMonster�������������
* @return ���Ƿ�ɹ�
* @author ���ʽ�
*/
	virtual bool bindPhysicsBody();




protected:

	int health_ = 3;																//����ֵ

	bool isAlive_ = true;														//�Ƿ���

	float shield = 0.5f;															//���׼�����
	//�����ƶ��ٶ�
	float monsterSpeed = 160;

	//���������ԡ�Ѫ����buff��

};




#endif // !MONSTER_H
