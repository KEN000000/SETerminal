#pragma once
/**
* @file Monster.h
*/

#ifndef MONSTER_H
#define MONSTER_H

#include "cocos2d.h"
#include "Character.h"
#include <string>
#include "./Scene/HelloWorldScene.h"

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


protected:

	int health_ = 3;																//����ֵ

	bool isAlive_ = true;														//�Ƿ���

	float shield = 0.5f;															//���׼�����
	//�����ƶ��ٶ�
	float monsterSpeed = 160.0f;


};




#endif // !MONSTER_H
