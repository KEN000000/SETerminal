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


	/**
* @brief ���������ͨ��ԭʼ�˺�����ڻ���ħ���ȼ��˴���ʹ��
* @param �յ���ԭʼ�˺�ֵ
* @author ���ʽ�
*/
	void receiveDamage(int damage);


	/**
* @brief ��ȡ��ɫ�Ƿ�����
* @return ���״̬
* @author ���ʽ�
*/
	bool isAlive();


	/**
* @brief ��ɫ����
* @author ���ʽ�
*/
	void die();



protected:

	//����ֵ
	int health_ = 3;																
	//�Ƿ���
	bool isAlive_ = true;														
	//���׼�����
	float shield = 0.5f;
	//�����ƶ��ٶ�
	float monsterSpeed = 160.0f;
	//�޵�״̬��Ĭ��Ϊfalse
	bool superBody = false;

};




#endif // !MONSTER_H
