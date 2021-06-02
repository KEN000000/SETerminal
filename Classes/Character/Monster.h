#pragma once
/**
* @file Monster.h
*/

#ifndef MONSTER_H
#define MONSTER_H

#include "cocos2d.h"
#include "Character.h"
<<<<<<< Updated upstream
#include <string>
=======
#include "Scene/HelloWorldScene.h"
>>>>>>> Stashed changes

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
<<<<<<< Updated upstream
	static Monster* create(const std::string& filename, float sizeX, float sizeY);


	/**
* @brief ΪMonster�������������
* @return ���Ƿ�ɹ�
* @author ���ʽ�
*/
	void Monster::move(float sizeX, float sizeY, cocos2d::Vec2 playerPostion);
=======
	static Monster* create(const std::string& filename);


	/**
* @brief Monster���ƶ��Լ������ӵ�������δ�����Խ����﷢���ӵ���������
* @return ��
* @author ���ʽ�
*/
	void Monster::move();
>>>>>>> Stashed changes


	/**
* @brief ΪMonster�������������
* @return ���Ƿ�ɹ�
* @author ���ʽ�
*/
	virtual bool bindPhysicsBody();


<<<<<<< Updated upstream


protected:

	int health_ = 3;																//����ֵ

	bool isAlive_ = true;														//�Ƿ���

	float shield = 0.5f;															//���׼�����
	//�����ƶ��ٶ�
	float monsterSpeed = 160;

	//���������ԡ�Ѫ����buff��
=======
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


>>>>>>> Stashed changes

};




#endif // !MONSTER_H
